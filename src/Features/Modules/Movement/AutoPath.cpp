//
// Created by vastrakai on 10/1/2024.
//

#include "AutoPath.hpp"
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/Actor/Actor.hpp>
#include <SDK/Minecraft/World/BlockLegacy.hpp>
#include <SDK/Minecraft/World/HitResult.hpp>
#include <Features/Events/BaseTickEvent.hpp>
#include <Features/Events/RenderEvent.hpp>




BlockSource* AutoPath::cachedSrc = nullptr;
const float AutoPath::SQRT_2 = sqrtf(2.f);

std::vector<Vec3i> AutoPath::sideAdj = {
    {1, 0, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, 0, -1}
};

std::vector<Vec3i> AutoPath::directAdj = {
    {1, 0, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, 0, -1},
    {0, 1, 0},
    {0, -1, 0}
};

std::vector<Vec3i> AutoPath::diagAdd = {
    {1, 0, 1},
    {-1, 0, 1},
    {-1, 0, -1},
    {1, 0, -1}
};

struct ScoreList {
    float gScore;
    float fScore;

    ScoreList() {
        this->gScore = 694206942069420.f;
        this->fScore = 694206942069420.f;
    }

    ScoreList(const float g, const float f) {
        this->gScore = g;
        this->fScore = f;
    }
};

static Vec3* getPlayerHitboxPathPosOffsets() {
    static Vec3 res[8] = {
        {0.17f, -0.99f, 0.17f},
        {0.83f, -0.99f, 0.17f},
        {0.83f, -0.99f, 0.83f},
        {0.17f, -0.99f, 0.83f},
        {0.17f, 0.9f, 0.17f},
        {0.83f, 0.9f, 0.17f},
        {0.83f, 0.9f, 0.83f},
        {0.17f, 0.9f, 0.83f}
    };

    return res;
}

__forceinline float AutoPath::heuristicEstimation(const Vec3i& node, const Vec3i& target) {
    const auto diff = node.sub(target);
    const int x = abs(diff.x);
    const int z = abs(diff.z);
    float straight;
    float diagonal;

    if (x < z) {
        straight = static_cast<float>(z) - static_cast<float>(x);
        diagonal = static_cast<float>(x);
    }
    else {
        straight = static_cast<float>(x) - static_cast<float>(z);
        diagonal = static_cast<float>(z);
    }

    diagonal *= SQRT_2;
    return straight + diagonal + static_cast<float>(abs(target.y - node.y));
}

inline bool AutoPath::isCompletelyObstructed(const Vec3i& pos) {
    const auto block = cachedSrc->getBlock(pos.toGlm());

    if (block->toLegacy()->getmMaterial().mIsBlockingMotion || block->toLegacy()->_BlockFlags.mSolid|| block->toLegacy()->getmMaterial().mIsBlockingPrecipitation || block->toLegacy()->getBlockId() != 0)
        return true;

    return false;
}

std::vector<std::pair<Vec3i, float>> AutoPath::getAirAdjacentNodes(const Vec3i& node, const Vec3i& start, Vec3i& goal) {
    std::vector<std::pair<Vec3i, float>> res;
    res.reserve(10);

    bool sideWorks[5];

    for (int i = 0; i < sideAdj.size(); i++) {
        bool works = false;
        const auto curr = node.add(sideAdj.at(i));

        if (curr.dist(start) <= 100) {
            if (!isCompletelyObstructed(curr) && !isCompletelyObstructed(curr.sub(0, 1, 0))) {
                res.emplace_back(curr, 1.f);
                works = true;
            }
        }

        sideWorks[i] = works;
    }

    // Top
    Vec3i curr = node.add(0, 1, 0);

    if (curr.dist(start) <= 100) {
        if (!isCompletelyObstructed(curr))
            res.emplace_back(curr, 1.f);
    }

    // Bottom
    curr = node.sub(0, 2, 0);

    if (curr.dist(start) <= 100) {
        if (!isCompletelyObstructed(curr))
            res.emplace_back(curr.add(0, 1, 0), 1.f);
    }

    // Diagonal
    sideWorks[4] = sideWorks[0];

    for (int i = 0; i < 4; i++) {
        if (sideWorks[i] && sideWorks[i + 1]) {
            curr = node.add(diagAdd.at(i));

            if (curr.dist(start) <= 100) {
                if (!isCompletelyObstructed(curr) && !isCompletelyObstructed(curr.sub(0, 1, 0)))
                    res.emplace_back(curr, SQRT_2);
            }
        }
    }

    return res;
}

std::vector<Vec3> AutoPath::findFlightPath(Vec3i start, Vec3i goal, BlockSource* src, float howClose, bool optimizePath, int64_t timeout, bool debugMsgs) {
    cachedSrc = src;

    std::map<Vec3i, Vec3i> cameFrom;
    std::map<Vec3i, ScoreList> scores;

    auto cmp = [&scores](const Vec3i& a, const Vec3i& b) {
        return scores[a].fScore < scores[b].fScore;
    };

    std::multiset<Vec3i, decltype(cmp)> openSet(cmp);  // this should be a priority queue or other minheap at some point
    float startH = heuristicEstimation(start, goal);

    scores[start] = ScoreList(0.f, startH);
    openSet.insert(start);

    Vec3 closestPoint = start.toVec3t();
    float bestHeuristic = startH;
    int64_t startTime = NOW;

    while (!openSet.empty()) {
        Vec3i current = *openSet.begin();

        openSet.erase(openSet.begin());

        if (heuristicEstimation(current, goal) <= howClose || NOW - startTime > 90 /*90 ms padding*/) {
            std::vector path = { closestPoint };
            Vec3i currentReconstructionNode = closestPoint;

            // unoptimised
            while (cameFrom.contains(currentReconstructionNode)) {
                currentReconstructionNode = cameFrom[currentReconstructionNode];
                path.push_back(currentReconstructionNode.toVec3t());
            }

            std::ranges::reverse(path.begin(), path.end());

            if (!path.empty()) {
                if (heuristicEstimation(current, goal) <= howClose)
                {
                    if (debugMsgs)
                        ChatUtils::displayClientMessage("§aFound path!");
                }
                else
                {
                    ChatUtils::displayClientMessage("§6Found partial path!");
                }

                if (optimizePath && path.size() >= 2) {
                    int startIdx = 0;
                    int endIdx = path.size() - 1;

                    while (startIdx < path.size() - 1) {
                        while (endIdx - startIdx > 1) {
                            // Check line of sight from start to end
                            bool hasLineOfSight = true;
                            Vec3* list = getPlayerHitboxPathPosOffsets();

                            for (int li = 0; li < 8; li++) {
                                // Check line of sight for each point
                                Vec3 startCheck = path.at(startIdx).add(list[li]);
                                Vec3 endCheck = path.at(endIdx).add(list[li]);
                                HitResult rt = src->checkRayTrace(startCheck.toGlm(), endCheck.toGlm());

                                if (rt.mType == HitType::BLOCK) {
                                    hasLineOfSight = false;
                                    break;
                                }
                                rt = src->checkRayTrace(startCheck.sub(0, 1, 0).toGlm(), endCheck.sub(0, 1, 0).toGlm());
                                if (rt.mType == HitType::BLOCK) {
                                    hasLineOfSight = false;
                                    break;
                                }
                            }

                            if (hasLineOfSight) {
                                startIdx++;
                                path.erase(path.begin() + startIdx, path.begin() + endIdx);
                                endIdx = path.size() - 1;
                            }
                            else
                                endIdx--;
                        }

                        startIdx++;
                        endIdx = path.size() - 1;
                    }
                }
            }



            // post-process and center x and z nodes
            for (auto& pos : path) {
                pos.x = floorf(pos.x) + 0.5f;
                pos.z = floorf(pos.z) + 0.5f;
            }

            return path;
        }

        for (auto& [pos, f] : getAirAdjacentNodes(current, start, goal)) {
            const float tentative_gScore = scores[current].gScore + f;

            if (tentative_gScore < scores[pos].gScore) {
                // better path found
                cameFrom[pos] = current;

                float h = heuristicEstimation(pos, goal);

                scores[pos] = ScoreList(tentative_gScore, tentative_gScore + h);
                openSet.insert(pos);

                if (h < bestHeuristic) {
                    bestHeuristic = h;
                    closestPoint = pos.toVec3t();
                }
            }
        }

        if (NOW - startTime > timeout) {
            ChatUtils::displayClientMessage("§cPathfinding timed out!");
            break;
        }
    }



    //Game.getGuiData()->displayClientMessageF("{}{}", RED, "No path found!");
    return {};
}

std::vector<glm::vec3> AutoPath::findFlightPathGlm(glm::vec3 start, glm::vec3 goal, BlockSource* src, float howClose,
    bool optimizePath, int64_t timeout, bool debugMsgs)
{
    auto res = findFlightPath(Vec3i(start), Vec3i(goal), src, howClose, optimizePath, timeout, debugMsgs);
    std::vector<glm::vec3> resGlm;
    for (const auto& pos : res) resGlm.push_back(pos.toGlm());
    return resGlm;
}

void AutoPath::onEnable()
{
    if (ClientInstance::get()->getLocalPlayer() == nullptr)
        setEnabled(false);

    mPosList.clear();
    mTicks = 0;

    gFeatureManager->mDispatcher->listen<BaseTickEvent, &AutoPath::onBaseTickEvent>(this);
    gFeatureManager->mDispatcher->listen<RenderEvent, &AutoPath::onRenderEvent>(this);
}

void AutoPath::onDisable()
{
    gFeatureManager->mDispatcher->deafen<BaseTickEvent, &AutoPath::onBaseTickEvent>(this);
    gFeatureManager->mDispatcher->deafen<RenderEvent, &AutoPath::onRenderEvent>(this);
    mPosList.clear();
    mTicks = 0;
}

void AutoPath::onBaseTickEvent(BaseTickEvent& event)
{
    /*for (const auto target : targetList) {
        const auto targetPos = *target->getPos();
        const auto path = findFlightPath(pos, targetPos, region, howClose, true);
        this->posList = path;
        break;
    }*/
    std::lock_guard<std::mutex> lock(mMutex);

    auto player = ClientInstance::get()->getLocalPlayer();
    if (player == nullptr)
        return;

    auto actors = ActorUtils::getActorList(false, true);
    std::erase(actors, player);

    std::ranges::sort(actors, [&](Actor* a, Actor* b) -> bool
    {
        return glm::distance(*a->getPos(), *player->getPos()) < glm::distance(*b->getPos(), *player->getPos());
    });

    if (actors.empty()) return;

    auto target = actors.at(0);
    if (target == nullptr) return;

    Vec3i targetng = Vec3i(target->getPos()->x, target->getPos()->y, target->getPos()->z);
    Vec3i srcng = Vec3i(player->getPos()->x, player->getPos()->y, player->getPos()->z);
    const auto targetPos = *target->getPos();
    const auto path = findFlightPath(srcng, targetng, ClientInstance::get()->getBlockSource(), mHowClose.mValue, true, mPathTimeout.mValue * 1000, mDebug.mValue);
    // Convert Vec3i to glm::vec3
    std::vector<glm::vec3> pathGlm;
    for (const auto pos : path) pathGlm.push_back(glm::vec3(pos.x, pos.y, pos.z));
    this->mPosList = pathGlm;
    spdlog::info("Added {} nodes to path", path.size());

}

void AutoPath::onRenderEvent(RenderEvent& event)
{
    std::lock_guard<std::mutex> lock(mMutex);

    if (mPosList.empty())
        return;

    auto player = ClientInstance::get()->getLocalPlayer();
    if (player == nullptr)
        return;

    auto pos = *player->getPos();
    auto region = ClientInstance::get()->getBlockSource();

    auto drawList = ImGui::GetBackgroundDrawList();

    std::vector<ImVec2> points;

    for (auto pos : mPosList)
    {
        ImVec2 point;
        if (!RenderUtils::worldToScreen(pos, point)) continue;
        points.emplace_back(point);
    }

    // Connect each point to form a line
    if (!points.empty())
        for (int i = 0; i < points.size() - 1; i++)
        {
            drawList->AddLine(points[i], points[i + 1], IM_COL32(0, 255, 0, 255), 2.0f);
        }

    for (auto pos : mPosList)
    {
        auto drawList = ImGui::GetBackgroundDrawList();

        AABB aabb = AABB(pos, glm::vec3(0.2f, 0.2f, 0.2f));
        auto points = MathUtils::getImBoxPoints(aabb);

        drawList->AddConvexPolyFilled(points.data(), points.size(), IM_COL32(255, 0, 0, 100));
        drawList->AddPolyline(points.data(), points.size(), IM_COL32(255, 0, 0, 255), 0, 2.f);
    }
}