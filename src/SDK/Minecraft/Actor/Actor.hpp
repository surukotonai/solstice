//
// Created by vastrakai on 6/25/2024.
//
#pragma once

#include <Utils/MemUtils.hpp>
#include "EntityContext.hpp"

#include "ActorFlags.hpp"
#include "Components/StateVectorComponent.hpp"
#include "Components/MoveInputComponent.hpp"
#include "Components/ActorRotationComponent.hpp"
#include "Components/BlockMovementSlowdownMultiplierComponent.hpp"
#include "Components/ActorEquipmentComponent.hpp"
#include "Components/AABBShapeComponent.hpp"
#include "Components/RenderPositionComponent.hpp"
#include "Components/ActorUniqueIDComponent.hpp"
#include "Components/ActorHeadRotationComponent.hpp"
#include "Components/MobBodyRotationComponent.hpp"
#include "Components/JumpControlComponent.hpp"
#include "Components/AttributesComponent.hpp"
#include "Components/CameraComponent.hpp"
#include "Components/CameraPresetComponent.hpp"
#include "Components/ActorWalkAnimationComponent.hpp"
#include "Components/ActorTypeComponent.hpp"
#include "Components/FlagComponent.hpp"
#include "Components/MaxAutoStepComponent.hpp"
#include "Components/MobHurtTimeComponent.hpp"
#include "Components/ActorDataFlagComponent.hpp"
#include "Components/MobJumpComponent.hpp"


#include <SDK/Minecraft/Inventory/ContainerManagerModel.hpp>
#include <SDK/Minecraft/World/Chunk/ChunkSource.hpp>


#define PLAYER_HEIGHT 1.62f
#define PLAYER_HEIGHT_VEC glm::vec3(0.f, PLAYER_HEIGHT, 0.f)

enum class ActorSwingSource : unsigned char {
    None = 0,
    Build = 1,
    Mine = 2,
    Interact = 3,
    Attack = 4,
    UseItem = 5,
    ThrowItem = 6,
    DropItem = 7,
    Event = 8,
};
enum class ActorLocation : int {
    Feet = 0,
    Body = 1,
    WeaponAttachPoint = 2,
    Head = 3,
    DropAttachPoint = 4,
    ExplosionPoint = 5,
    Eyes = 6,
    BreathingPoint = 7,
    Mouth = 8,
    Count = 9,
};

enum class ShapeType : unsigned char {
    Outline = 0,
    Collision = 1,
    CollisionForCamera = 2,
};
class Actor {
public:
    unsigned char filler[0x3d0]; // ItemActor::ItemActor on bds line 35 ItemStack::ItemStack((ItemActor *)((char *)this + 1024));

    CLASS_FIELD(uintptr_t**, vtable, 0x0);
    CLASS_FIELD(EntityContext, mContext, 0x8);
    CLASS_FIELD(std::string, mEntityIdentifier, OffsetProvider::Actor_mEntityIdentifier);

    bool getStatusFlag(ActorFlags flag) {
        auto data = getActorDataFlagComponent();
        return data->getStatusFlag(flag);
    }

    void setStatusFlag(ActorFlags flag, bool value) {
        auto data = getActorDataFlagComponent();
        data->setStatusFlag(flag, value);
    }

    template<typename flag_t>
    bool getFlag() {
        if (!isValid())
        {
            spdlog::error("Failed to get flag: actor is not valid");
            return false;
        }

        return mContext.mRegistry->has_flag<flag_t>(mContext.mEntityId);
    }

    template<typename flag_t>
    void setFlag(bool value)
    {
        try
        {
            if (!isValid())
            {
                spdlog::error("Failed to set flag: actor is not valid");
                return;
            }

            mContext.mRegistry->set_flag<flag_t>(mContext.mEntityId, value);
        }
        catch (std::exception& e) {
            spdlog::error("Failed to set flag: {}", e.what());
        }
        catch (...) {
            spdlog::error("Failed to set flag: unknown error");
        }
    }

    template<typename flag_t>
    bool getFlag(EntityId id) {
        if (!isValid())
        {
            spdlog::error("Failed to get flag: actor is not valid");
            return false;
        }

        return mContext.mRegistry->has_flag<flag_t>(id);
    }

    template<typename flag_t>
    void setFlag(bool value, EntityId id)
    {
        try
        {
            if (!isValid())
            {
                spdlog::error("Failed to set flag: actor is not valid");
                return;
            }
            /*auto storage = mContext.assure<flag_t>();
            bool has = storage->contains(id);
            if (value && !has) {
                storage->emplace(id);
            }
            else if (!value && has) {
                storage->remove(id);
            }*/
            mContext.mRegistry->set_flag<flag_t>(id, value);
        }
        catch (std::exception& e) {
            spdlog::error("Failed to set flag: {}", e.what());
        }
        catch (...) {
            spdlog::error("Failed to set flag: unknown error");
        }
    }




    void swing(ActorSwingSource swingsource);
    bool isDestroying();
    bool isSwinging();
    void setSwinging(bool swinging);
    int getGameType();
    void setGameType(int type);
    bool isDebugCameraActive();
    void setDebugCameraActive(bool active);
    void setAllowInsideBlockRender(bool allow);
    int getSwingProgress();
    int getOldSwingProgress();
    void setSwingProgress(int progress);
    AABB getAABB(bool normal = false);
    void setAABB(AABB& aabb);
    bool isPlayer();
    ChunkPos getChunkPos();
    glm::vec3* getPos();
    glm::vec3* getPosPrev();
    class GameMode* getGameMode();
    ActorDataFlagComponent* getActorDataFlagComponent();
    ActorWalkAnimationComponent* getWalkAnimationComponent();
    DebugCameraComponent* getDebugCameraComponent();
    CameraPresetComponent* getCameraPresetComponent();
    ActorTypeComponent* getActorTypeComponent();
    RenderPositionComponent* getRenderPositionComponent();
    int64_t getRuntimeID();
    StateVectorComponent* getStateVectorComponent();
    MoveInputComponent* getMoveInputComponent();
    RawMoveInputComponent* getRawMoveInputComponent();
    ActorRotationComponent* getActorRotationComponent();
    AABBShapeComponent* getAABBShapeComponent();
    BlockMovementSlowdownMultiplierComponent* getBlockMovementSlowdownMultiplierComponent();
    ActorUniqueIDComponent* getActorUniqueIDComponent();
    ContainerManagerModel* getContainerManagerModel();
    ActorHeadRotationComponent* getActorHeadRotationComponent();
    MobBodyRotationComponent* getMobBodyRotationComponent();
    JumpControlComponent* getJumpControlComponent();
    MobJumpComponent* getMobJumpComponent();
    CameraComponent* getCameraComponent();
    CameraDirectLookComponent* getCameraDirectLookComponent();
    MaxAutoStepComponent* getMaxAutoStepComponent();
    MobHurtTimeComponent* getMobHurtTimeComponent();
    class SimpleContainer* getArmorContainer();
    class PlayerInventory* getSupplies();
    class Level* getLevel();
    class SerializedSkinImpl* getSkin();
    void setPosition(glm::vec3 pos);
    void setPos(float x, float y, float z);
    float distanceTo(Actor* actor);
    float distanceTo(const glm::vec3& pos);
    bool wasOnGround();
    bool isOnGround();
    void setOnGround(bool);
    bool isCollidingHorizontal();
    bool isDead();
    void jumpFromGround();
    float getFallDistance();
    void setFallDistance(float distance);
    std::string getRawName();
    const std::string& getNameTag();
    void setNametag(const std::string& name);
    AttributesComponent* getAttributesComponent();
    float getMaxHealth();
    float getHealth();
    float getAbsorption();
    float getMaxAbsorption();
    AttributeInstance* getAttribute(AttributeId id);
    AttributeInstance* getAttribute(int id);
    bool isOnFire();
    std::string getLocalName();
    void setLocalName(std::string newLocalName);
    std::string getXuid();
    bool isValid();
    bool canSee(Actor* actor);
};

static_assert(sizeof(Actor) == 0x3d0, "Actor size is invalid");
