//
// Created by vastrakai on 7/5/2024.
//

#pragma once

#include <SDK/Minecraft/Inventory/CompoundTag.hpp>
#include <SDK/Minecraft/Inventory/ItemStack.hpp>
#include <SDK/Minecraft/Inventory/NetworkItemStackDescriptor.hpp>
#include <SDK/Minecraft/Network/Packets/Packet.hpp>



enum class InventorySourceType : int {
	InvalidInventory = -1,
	ContainerInventory = 0,
	GlobalInventory = 1,
	WorldInteraction = 2,
	CreativeInventory = 3,
	NonImplementedFeatureTODO = 99999,
};

class InventorySource {
public:
	// InventorySource inner types define
	enum class InventorySourceFlags : unsigned int {
		NoFlag = 0x0,
		WorldInteraction_Random = 0x1,
	};

	InventorySourceType  mType = InventorySourceType::InvalidInventory; // this+0x0
	char                 mContainerId = -1;                                     // this+0x4
	InventorySourceFlags mFlags = InventorySourceFlags::NoFlag;          // this+0x8

	inline bool operator==(InventorySource const& rhs) const {
		return ((this->mType == rhs.mType) &&
			(this->mContainerId == rhs.mContainerId) &&
			(this->mFlags == rhs.mFlags));
	}
	inline bool operator!=(InventorySource const& rhs) const {
		return !(*this == rhs);
	}

	inline bool operator<(InventorySource const& rhs) const {
		if (this->mType != rhs.mType) {
			return this->mType < rhs.mType;
		}
		if (this->mContainerId != rhs.mContainerId) {
			return this->mContainerId < rhs.mContainerId;
		}
		return this->mFlags < rhs.mFlags;
	}

	inline bool operator>(InventorySource const& rhs) const {
		return rhs < *this;
	}

};

namespace std
{
	template <>
	struct hash<InventorySource> {
		size_t operator()(InventorySource const& key) const {
			return static_cast<size_t>(key.mContainerId)
				^ (static_cast<size_t>(static_cast<unsigned int>(key.mType)) << 16);
		}
	};
}

class InventoryAction
{
public:
	InventorySource            mSource;             // this+0x0
	unsigned int               Slot;               // this+0xC
	NetworkItemStackDescriptor mItemDescriptor; // this+0x10
	NetworkItemStackDescriptor mToItemDescriptor;   // this+0x70
	ItemStack                  mItem;           // this+0xD0
	ItemStack                  mToItem;             // this+0x170

	InventoryAction(int slot, ItemStack* sourceItem, ItemStack* targetItem) {
		Slot = slot;
		if (sourceItem) mItem = *sourceItem;
		if (targetItem) mToItem = *targetItem;
		mSource = InventorySource();
		mSource.mType = InventorySourceType::ContainerInventory;
		if (sourceItem) mItemDescriptor = NetworkItemStackDescriptor(*sourceItem);
		if (targetItem) mToItemDescriptor = NetworkItemStackDescriptor(*targetItem);
	}
};

//static_assert(sizeof(InventoryAction) == 0x200);

class InventoryTransactionItemGroup {
public:
	InventoryTransactionItemGroup() = delete;

	int                                mItemId;   // this+0x0
	int                                mItemAux;  // this+0x4
	std::unique_ptr<class CompoundTag> mTag;      // this+0x8
	int                                mCount;    // this+0x10
	bool                               mOverflow; // this+0x14
};


class InventoryTransaction {
public:
	std::unordered_map<InventorySource, std::vector<InventoryAction>> mActions; // 0x0
	std::vector<InventoryTransactionItemGroup>                        mItems;   // 0x40

	void addAction(InventoryAction const& action) {
		static void* func = reinterpret_cast<void*>(SigManager::InventoryTransaction_addAction);
		using AddAction = void(__fastcall*)(InventoryTransaction*, InventoryAction const&, bool);
		reinterpret_cast<AddAction>(func)(this, action, false);
	}
};

class ComplexInventoryTransaction {
public:
	// ComplexInventoryTransaction inner types define
	enum class Type : int {
		NormalTransaction = 0x0,
		InventoryMismatch = 0x1,
		ItemUseTransaction = 0x2,
		ItemUseOnEntityTransaction = 0x3,
		ItemReleaseTransaction = 0x4,
	};

	uintptr_t** vtable; // this+0x0
	Type                 type;
	InventoryTransaction data;

	ComplexInventoryTransaction()
	{
		static uintptr_t vtable_addr = SigManager::ComplexInventoryTransaction_vtable;
		vtable = reinterpret_cast<uintptr_t**>(vtable_addr);
		type = Type::NormalTransaction;
		data = InventoryTransaction();
		data.mActions = std::unordered_map<InventorySource, std::vector<InventoryAction>>();
		data.mItems = std::vector<InventoryTransactionItemGroup>();
	};

	Type getTransacType() {
		return type;
	}
};

class ItemUseInventoryTransaction : public ComplexInventoryTransaction
{
public:
	enum class ActionType : int32_t {
		Place = 0,
		Use = 1,
		Destroy = 2,
	};

	enum class PredictedResult : int32_t
	{
		Failure,
		Success
	};

	enum class TriggerType : int8_t
	{
		Unknown,
		PlayerInput,
		SimulationTick,
	};

	ActionType mActionType{};
	TriggerType mTriggerType = TriggerType::PlayerInput;
	glm::ivec3 mBlockPos{};
	int32_t mTargetBlockRuntimeId{};
	uint32_t mFace{};
	uint32_t mSlot{};
	unsigned char mHand{}; /* :thinking:*/
	NetworkItemStackDescriptor mItemInHand{};
	glm::vec3 mPlayerPos{};
	glm::vec3 mClickPos{};
	PredictedResult mPredictedResult = PredictedResult::Success;
	PredictedResult mClientCooldownState = PredictedResult::Success;

	ItemUseInventoryTransaction()
	{
		static uintptr_t vtable_addr = SigManager::ItemUseInventoryTransaction_vtable;
		vtable = reinterpret_cast<uintptr_t**>(vtable_addr);
		type = Type::ItemUseTransaction;
		data = InventoryTransaction();
		data.mActions = std::unordered_map<InventorySource, std::vector<InventoryAction>>();
		data.mItems = std::vector<InventoryTransactionItemGroup>();
	}
};

class ItemUseOnActorInventoryTransaction : public ComplexInventoryTransaction
{
public:
	enum class ActionType : int32_t {
		Interact = 0,
		Attack = 1,
		ItemInteract = 2,
	};

	uint64_t mActorId{};
	ActionType mActionType{};
	int32_t mSlot{};
	unsigned char mHand{};
	NetworkItemStackDescriptor mItemInHand{};
	glm::vec3 mPlayerPos{};
	glm::vec3 mClickPos{};

	ItemUseOnActorInventoryTransaction()
	{
		static uintptr_t vtable_addr = SigManager::ItemUseOnActorInventoryTransaction_vtable;
		vtable = reinterpret_cast<uintptr_t**>(vtable_addr);
		type = Type::ItemUseOnEntityTransaction;
		data = InventoryTransaction();
		data.mActions = std::unordered_map<InventorySource, std::vector<InventoryAction>>();
		data.mItems = std::vector<InventoryTransactionItemGroup>();
	}
};

class ItemReleaseInventoryTransaction : public ComplexInventoryTransaction
{
public:
	enum class ActionType : int32_t {
		Release = 0,
		Use = 1,
	};

	ActionType mActionType{};
	int32_t mSlot{};
	NetworkItemStackDescriptor mItemInHand{};
	glm::vec3 mHeadPos{};

	ItemReleaseInventoryTransaction()
	{
		static uintptr_t vtable_addr = SigManager::ItemReleaseInventoryTransaction_vtable;
		vtable = reinterpret_cast<uintptr_t**>(vtable_addr);
		type = Type::ItemReleaseTransaction;
		data = InventoryTransaction();
		data.mActions = std::unordered_map<InventorySource, std::vector<InventoryAction>>();
		data.mItems = std::vector<InventoryTransactionItemGroup>();
	}
};

static_assert(sizeof(ComplexInventoryTransaction) == 104);
static_assert(sizeof(ItemUseInventoryTransaction) == 272);
static_assert(sizeof(ItemUseOnActorInventoryTransaction) == 248);
static_assert(sizeof(ItemReleaseInventoryTransaction) == 224);


enum class ContainerEnumName : signed char {
	AnvilInputContainer = 0x0,
	AnvilMaterialContainer = 0x1,
	AnvilResultPreviewContainer = 0x2,
	SmithingTableInputContainer = 0x3,
	SmithingTableMaterialContainer = 0x4,
	SmithingTableResultPreviewContainer = 0x5,
	ArmorContainer = 0x6,
	LevelEntityContainer = 0x7,
	BeaconPaymentContainer = 0x8,
	BrewingStandInputContainer = 0x9,
	BrewingStandResultContainer = 0xA,
	BrewingStandFuelContainer = 0xB,
	CombinedHotbarAndInventoryContainer = 0xC,
	CraftingInputContainer = 0xD,
	CraftingOutputPreviewContainer = 0xE,
	RecipeConstructionContainer = 0xF,
	RecipeNatureContainer = 0x10,
	RecipeItemsContainer = 0x11,
	RecipeSearchContainer = 0x12,
	RecipeSearchBarContainer = 0x13,
	RecipeEquipmentContainer = 0x14,
	RecipeBookContainer = 0x15,
	EnchantingInputContainer = 0x16,
	EnchantingMaterialContainer = 0x17,
	FurnaceFuelContainer = 0x18,
	FurnaceIngredientContainer = 0x19,
	FurnaceResultContainer = 0x1A,
	HorseEquipContainer = 0x1B,
	HotbarContainer = 0x1C,
	InventoryContainer = 0x1D,
	ShulkerBoxContainer = 0x1E,
	TradeIngredient1Container = 0x1F,
	TradeIngredient2Container = 0x20,
	TradeResultPreviewContainer = 0x21,
	OffhandContainer = 0x22,
	CompoundCreatorInput = 0x23,
	CompoundCreatorOutputPreview = 0x24,
	ElementConstructorOutputPreview = 0x25,
	MaterialReducerInput = 0x26,
	MaterialReducerOutput = 0x27,
	LabTableInput = 0x28,
	LoomInputContainer = 0x29,
	LoomDyeContainer = 0x2A,
	LoomMaterialContainer = 0x2B,
	LoomResultPreviewContainer = 0x2C,
	BlastFurnaceIngredientContainer = 0x2D,
	SmokerIngredientContainer = 0x2E,
	Trade2Ingredient1Container = 0x2F,
	Trade2Ingredient2Container = 0x30,
	Trade2ResultPreviewContainer = 0x31,
	GrindstoneInputContainer = 0x32,
	GrindstoneAdditionalContainer = 0x33,
	GrindstoneResultPreviewContainer = 0x34,
	StonecutterInputContainer = 0x35,
	StonecutterResultPreviewContainer = 0x36,
	CartographyInputContainer = 0x37,
	CartographyAdditionalContainer = 0x38,
	CartographyResultPreviewContainer = 0x39,
	BarrelContainer = 0x3A,
	CursorContainer = 0x3B,
	CreatedOutputContainer = 0x3C,
	SmithingTableTemplateContainer = 0x3D,
};


struct NormalTransactionData {
public:
	InventoryTransaction mTransaction;
};
struct InventoryMismatchData {
public:
	InventoryTransaction mTransaction;
};
class InventoryTransactionPacket : public Packet
{
public:
	static const PacketID ID = PacketID::InventoryTransaction;

	char pad[0x10]; // this+0x30
	std::vector<std::pair<ContainerEnumName, std::vector<unsigned char>>> mLegacySetItemSlots;   // this+0x40
	std::variant<NormalTransactionData, InventoryMismatchData, ItemUseInventoryTransaction, ItemUseOnActorInventoryTransaction, ItemReleaseInventoryTransaction>    mVariantTransaction;
	std::unique_ptr<ComplexInventoryTransaction>                          mTransaction;        // this+0x58
	bool                                                                  mIsClientSide = false; // this+0x60
};

static_assert(sizeof(InventoryTransactionPacket) == 384);