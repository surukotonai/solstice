// fuck you microsoft
#pragma once

#include <entt/entt.hpp>

#include "Minecraft/Actor/Components/AABBShapeComponent.hpp"
#include "Minecraft/Actor/Components/ActorDataFlagComponent.hpp"
#include "Minecraft/Actor/Components/ActorEquipmentComponent.hpp"
#include "Minecraft/Actor/Components/ActorGameTypeComponent.hpp"
#include "Minecraft/Actor/Components/ActorHeadRotationComponent.hpp"
#include "Minecraft/Actor/Components/ActorOwnerComponent.hpp"
#include "Minecraft/Actor/Components/ActorRotationComponent.hpp"
#include "Minecraft/Actor/Components/ActorTypeComponent.hpp"
#include "Minecraft/Actor/Components/ActorUniqueIDComponent.hpp"
#include "Minecraft/Actor/Components/ActorWalkAnimationComponent.hpp"
#include "Minecraft/Actor/Components/AttributesComponent.hpp"
#include "Minecraft/Actor/Components/BlockMovementSlowdownMultiplierComponent.hpp"
#include "Minecraft/Actor/Components/CameraComponent.hpp"
#include "Minecraft/Actor/Components/CameraPresetComponent.hpp"
#include "Minecraft/Actor/Components/FallDistanceComponent.hpp"
#include "Minecraft/Actor/Components/FlagComponent.hpp"
#include "Minecraft/Actor/Components/ItemUseSlowdownModifierComponent.hpp"
#include "Minecraft/Actor/Components/JumpControlComponent.hpp"
#include "Minecraft/Actor/Components/MaxAutoStepComponent.hpp"
#include "Minecraft/Actor/Components/MobBodyRotationComponent.hpp"
#include "Minecraft/Actor/Components/MobHurtTimeComponent.hpp"
#include "Minecraft/Actor/Components/MobJumpComponent.hpp"
#include "Minecraft/Actor/Components/MoveInputComponent.hpp"
#include "Minecraft/Actor/Components/RenderPositionComponent.hpp"
#include "Minecraft/Actor/Components/RuntimeIDComponent.hpp"
#include "Minecraft/Actor/Components/StateVectorComponent.hpp"

#define ENTT_HASH__(t, hash)                                      \
    template<> struct entt::type_hash<t> {                              \
        [[nodiscard]] static constexpr entt::id_type value() noexcept { return hash; } \
        [[nodiscard]] constexpr operator entt::id_type() const noexcept { return value(); } \
    }
// HAND POWER :JOY:

ENTT_HASH__(ActorGameTypeComponent, 0x88D3EDDFu);
ENTT_HASH__(ActorOwnerComponent, 0x85B93800u);
ENTT_HASH__(CameraPresetComponent, 0x0FD83AA62u);
ENTT_HASH__(ItemUseSlowdownModifierComponent, 0x867FC92Cu);
ENTT_HASH__(JumpControlComponent, 0x2F50F705u);
ENTT_HASH__(MobJumpComponent, 0xC52C8F78u);
ENTT_HASH__(MoveInputComponent, 0x018B1887u);
ENTT_HASH__(OnFireComponent, 0x7E613FF3u);
ENTT_HASH__(SetMovingFlagRequestComponent, 0x8BCE56DFu);
ENTT_HASH__(HorizontalCollisionFlagComponent, 0xD5EE0BD8u);
ENTT_HASH__(IsDeadFlagComponent, 0x710A62C4u);
ENTT_HASH__(NameableComponent, 0x97D981A9u);
ENTT_HASH__(RawMoveInputComponent, 0x3613E513u);
ENTT_HASH__(MoveRequestComponent, 0x4C8F7288u);



//by parser

//ENTT_HASH__(ClientSkin, 0x83B213ABu);
//ENTT_HASH__(EventingRequestQueueComponent, 0x9693B204u);
//ENTT_HASH__(SoundEventRequestQueueComponent, 0xBAF75BF7u);
//ENTT_HASH__(RandomComponent, 0xE4493901u);
//ENTT_HASH__(ParticleEventRequestQueueComponent, 0xDE0BF188u);
ENTT_HASH__(AllowInsideBlockRenderComponent, 0x9BB661A0u);
ENTT_HASH__(CameraComponent, 0x4F6047C7u);
ENTT_HASH__(CameraDirectLookComponent, 0xCEB578F1u);
ENTT_HASH__(CameraBobComponent, 0xC7B5D956u);
//ENTT_HASH__(CameraAttachComponent, 0xA6233058u);
ENTT_HASH__(CameraFirstPersonComponent, 0xED52B1C6u);
//ENTT_HASH__(CameraFirstPersonClimbingComponent, 0x4DE098EBu);
//ENTT_HASH__(CameraEntityStateComponent, 0x028F4DB3u);
ENTT_HASH__(CameraLookAtPositionComponent, 0x17045224u);
//ENTT_HASH__(CameraAdjustedPositionComponent, 0x86DF70DCu);
//ENTT_HASH__(CameraPerspectiveOptionComponent, 0xD5B28BF2u);
ENTT_HASH__(UpdatePlayerFromCameraComponent, 0x0E49CF3Bu);
//ENTT_HASH__(CameraSleepVignetteComponent, 0x5844CE60u);
ENTT_HASH__(CameraRenderFirstPersonObjectsComponent, 0xE15A7944u);
//ENTT_HASH__(CameraLiquidOffsetComponent, 0x94F91476u);
ENTT_HASH__(CameraOffsetComponent, 0xAD2CB566u);
//ENTT_HASH__(CameraPortalDistortionComponent, 0x2676E4F4u);
//ENTT_HASH__(CameraComfortMoveVRComponent, 0xBB08DAB0u);
//ENTT_HASH__(CameraShakeSupportComponent, 0x1605AC58u);
//ENTT_HASH__(DefaultInputCameraComponent, 0x8BCE84BEu);
//ENTT_HASH__(GameplayAffectsFovComponent, 0xCE013BB9u);
ENTT_HASH__(PlayerStateAffectsRenderingComponent, 0x21A688A4u);
ENTT_HASH__(CameraOrbitComponent, 0x2F0FC33Fu);
ENTT_HASH__(CameraThirdPersonComponent, 0xAB29C993u);
ENTT_HASH__(CameraAvoidanceComponent, 0x4D1D154Du);
//ENTT_HASH__(CameraLookAtComponent, 0xE33F5E3Du);
ENTT_HASH__(CameraRenderPlayerModelComponent, 0x838D12E1u);
//ENTT_HASH__(DeathCameraComponent, 0x1641604Bu);
//ENTT_HASH__(CameraTargetSettingsComponent, 0x95CB5E8Bu);
ENTT_HASH__(TargetCameraSetInitialOrientationComponent, 0xDFE20EA4u);
//ENTT_HASH__(TargetCameraOrientationComponent, 0x48E639F0u);
ENTT_HASH__(RedirectCameraInputComponent, 0xA8F0A7EBu);
ENTT_HASH__(StationaryCameraComponent, 0xA563B3A1u);
ENTT_HASH__(ExtendPlayerRenderingComponent, 0x7C6FF885u);
//ENTT_HASH__(CameraThirdPersonBoomComponent, 0xEF14FB9Au);
//ENTT_HASH__(CameraStartingValuesComponent, 0xA31E79D9u);
//ENTT_HASH__(CameraLocalSpaceRotationComponent, 0xF5B4EB5Cu);
//ENTT_HASH__(CameraThirdPersonFixedBoomComponent, 0x9442AD10u);
//ENTT_HASH__(FixedBoomOrientationComponent, 0x48FC16FDu);
//ENTT_HASH__(CameraBlendStateComponent, 0x7935F153u);
ENTT_HASH__(RenderCameraComponent, 0x119E772Bu);
ENTT_HASH__(GameCameraComponent, 0x9EC7D9E5u);
ENTT_HASH__(DebugCameraComponent, 0x20BC5340u);
ENTT_HASH__(CameraFlyMoveComponent, 0x1EB64CAFu);
//ENTT_HASH__(SynchedActorDataComponent, 0xE642016Bu);
ENTT_HASH__(ActorDataFlagComponent, 0xC67426F3u);
//ENTT_HASH__(ActorDataDirtyFlagsComponent, 0xC131F6A8u);
ENTT_HASH__(StateVectorComponent, 0x1B5D5238u);
ENTT_HASH__(AABBShapeComponent, 0xBAC1B3CFu);
ENTT_HASH__(ActorRotationComponent, 0x75DF36B7u);
ENTT_HASH__(ActorWalkAnimationComponent, 0x666777C6u);
//ENTT_HASH__(ActorDefinitionIdentifierComponent, 0xDEB6534Fu);
ENTT_HASH__(ActorTypeComponent, 0x4F6BA419u);
ENTT_HASH__(ActorUniqueIDComponent, 0x18F957AFu);
ENTT_HASH__(AttributesComponent, 0xFD3B0613u);
ENTT_HASH__(BlockMovementSlowdownMultiplierComponent, 0xF6091F58u);
//ENTT_HASH__(DimensionTypeComponent, 0xAF993816u);
ENTT_HASH__(FallDistanceComponent, 0xCE6B34F6u);
ENTT_HASH__(MaxAutoStepComponent, 0x9AAE5D7Fu);
//ENTT_HASH__(MobEffectsComponent, 0xE6A1B550u);
//ENTT_HASH__(MovementAttributesComponent, 0xA795A68Cu);
//ENTT_HASH__(MovementSoundComponent, 0x387529D2u);
//ENTT_HASH__(CanMakeAudibleSoundsComponent, 0x7A0369AAu);
//ENTT_HASH__(PostTickPositionDeltaComponent, 0xF96968B0u);
ENTT_HASH__(RuntimeIDComponent, 0xFC0DBBB5u);
//ENTT_HASH__(StepSoundFrequencyComponent, 0xB0051187u);
//ENTT_HASH__(SwimAmountComponent, 0xCF19787Cu);
ENTT_HASH__(IsFishableFlagComponent, 0x8052842Cu);
//ENTT_HASH__(PortalCooldownDurationComponent, 0x94211021u);
//ENTT_HASH__(TintColorComponent, 0x0098062Eu);
//ENTT_HASH__(InsideBlockComponent, 0xC1C8FB69u);
//ENTT_HASH__(ChunkPositionComponent, 0x7CEEAC38u);
//ENTT_HASH__(DepenetrationComponent, 0x256B41F6u);
ENTT_HASH__(OnGroundFlagComponent, 0xC29078A0u);
ENTT_HASH__(SubBBsComponent, 0x0B0822D1u);
ENTT_HASH__(WasOnGroundFlagComponent, 0x85C63FFDu);
ENTT_HASH__(ActorEquipmentComponent, 0xB06141A9u);
ENTT_HASH__(ActorIsFirstTickFlagComponent, 0x43A31676u);
//ENTT_HASH__(WalkDistComponent, 0xCF59BFCFu);
//ENTT_HASH__(OffsetsComponent, 0xDE21C316u);
ENTT_HASH__(RenderPositionComponent, 0xE53C7221u);
//ENTT_HASH__(RenderRotationComponent, 0xD15944E2u);
//ENTT_HASH__(ActorDataSeatOffsetComponent, 0x29C70BD3u);
//ENTT_HASH__(ActorDataControllingSeatIndexComponent, 0x45ECC051u);
//ENTT_HASH__(ActorDataBoundingBoxComponent, 0x5ACD5A3Eu);
//ENTT_HASH__(MovementInterpolatorComponent, 0x02BC1330u);
//ENTT_HASH__(DeathTickingComponent, 0x3E3ACACBu);
//ENTT_HASH__(MobAnimationComponent, 0xFF0A6FE8u);
ENTT_HASH__(MobHurtTimeComponent, 0xD7A3585Cu);
//ENTT_HASH__(BodyControlComponent, 0x293C76FDu);
ENTT_HASH__(ActorHeadRotationComponent, 0xBABE7211u);
//ENTT_HASH__(ActorInWallDetectionComponent, 0xB0B4BB1Bu);
//ENTT_HASH__(JumpTicksComponent, 0xAC923948u);
ENTT_HASH__(MobBodyRotationComponent, 0xD7F64BBAu);

//parser v2
/*
ENTT_HASH__(AABBDimensionsComponent, 0xDEFBA925u);
ENTT_HASH__(AABBRelativeSizeUpdateComponent, 0x615CEE62u);
ENTT_HASH__(AABBShapeComponent, 0xBAC1B3CFu);
ENTT_HASH__(AbilitiesComponent, 0x68B75D48u);
ENTT_HASH__(AbilitiesDirtyComponent, 0xC751A82Eu);
ENTT_HASH__(AbilitiesRequestComponent, 0xC3436209u);
ENTT_HASH__(AbsoluteSizeUpdateComponent, 0xBE91FCC3u);
ENTT_HASH__(ActorAddedFlagComponent, 0x8BDD2519u);
ENTT_HASH__(ActorChunkMoveFlagComponent, 0x6AF81C07u);
ENTT_HASH__(ActorComponent, 0xCA3C2CF9u);
ENTT_HASH__(ActorDataBoundingBoxComponent, 0x5ACD5A3Eu);
ENTT_HASH__(ActorDataControllingSeatIndexComponent, 0x45ECC051u);
ENTT_HASH__(ActorDataDirtyFlagsComponent, 0xC131F6A8u);
ENTT_HASH__(ActorDataFlagComponent, 0xC67426F3u);
ENTT_HASH__(ActorDataHorseFlagComponent, 0x8D94DB14u);
ENTT_HASH__(ActorDataHorseTypeComponent, 0xB471FC1Au);
ENTT_HASH__(ActorDataJumpDurationComponent, 0x5E1FD06Du);
ENTT_HASH__(ActorDataSeatOffsetComponent, 0x29C70BD3u);
ENTT_HASH__(ActorDefinitionIdentifierComponent, 0xDEB6534Fu);
ENTT_HASH__(ActorDiedComponent, 0x51E0E2EFu);
ENTT_HASH__(ActorEquipmentComponent, 0xB06141A9u);
ENTT_HASH__(ActorGameTypeComponent, 0x88D3EDDFu);
ENTT_HASH__(ActorHeadInWaterFlagComponent, 0x89718A63u);
ENTT_HASH__(ActorHeadRotationComponent, 0xBABE7211u);
ENTT_HASH__(ActorHeadWasInWaterFlagComponent, 0xF53D4C8Au);
ENTT_HASH__(ActorInBubbleColumnComponent, 0x26113B38u);
ENTT_HASH__(ActorInWallDetectionComponent, 0xB0B4BB1Bu);
ENTT_HASH__(ActorIsBeingDestroyedFlagComponent, 0xE88B4C85u);
ENTT_HASH__(ActorIsFirstTickFlagComponent, 0x43A31676u);
ENTT_HASH__(ActorIsImmobileFlagComponent, 0xAB4E40CBu);
ENTT_HASH__(ActorIsKnockedBackOnDeathFlagComponent, 0x89856A52u);
ENTT_HASH__(ActorItemCooldownsComponent, 0xC099C998u);
ENTT_HASH__(ActorLimitedLifetimeComponent, 0x41D72D2Eu);
ENTT_HASH__(ActorLinkQueueComponent, 0x5E5FAA10u);
ENTT_HASH__(ActorLocalPlayerEntityMovedFlagComponent, 0xE09D6AEFu);
ENTT_HASH__(ActorMovementTickNeededComponent, 0x94154CCEu);
ENTT_HASH__(ActorOwnerComponent, 0x85B93800u);
ENTT_HASH__(ActorRemovedFlagComponent, 0x4434E84Fu);
ENTT_HASH__(ActorRotationComponent, 0x75DF36B7u);
ENTT_HASH__(ActorSetPositionRequestComponent, 0x5E3CA211u);
ENTT_HASH__(ActorTickedComponent, 0x3DC2FEEDu);
ENTT_HASH__(ActorTickNeededComponent, 0x2744AA41u);
ENTT_HASH__(ActorTypeComponent, 0x4F6BA419u);
ENTT_HASH__(ActorUniqueIDComponent, 0x18F957AFu);
ENTT_HASH__(ActorWalkAnimationComponent, 0x666777C6u);
ENTT_HASH__(AddRiderComponent, 0x2CC42C73u);
ENTT_HASH__(AddToLeashedEntitiesRequestComponent, 0x97AE7814u);
ENTT_HASH__(AdmireItemComponent, 0xC4ED7BE7u);
ENTT_HASH__(AdultRidingHeightOffsetComponent, 0x2B518EB1u);
ENTT_HASH__(AgeableComponent, 0x9A06FF03u);
ENTT_HASH__(AgentCommandComponent, 0xAFB93E42u);
ENTT_HASH__(AgentFlagComponent, 0x8B8972D7u);
ENTT_HASH__(AgentVariableIndexComponent, 0x7E5F21B5u);
ENTT_HASH__(AirSpeedComponent, 0x9B8F9061u);
ENTT_HASH__(AirTravelFlagComponent, 0xB147B030u);
ENTT_HASH__(AllowOffHandItemComponent, 0xD953F8C0u);
ENTT_HASH__(AmbientSoundComponent, 0xE4630E59u);
ENTT_HASH__(AmbientSoundServerComponent, 0x8AD6C668u);
ENTT_HASH__(AngerLevelComponent, 0xE60F4325u);
ENTT_HASH__(AngryComponent, 0x2AFB99CDu);
ENTT_HASH__(AntiCheatRewindFlagComponent, 0x412013A4u);
ENTT_HASH__(ApplyGravityComponent, 0x48C5D5FEu);
ENTT_HASH__(ApplyKnockbackRulesComponent, 0x823739D8u);
ENTT_HASH__(ApplyRestitutionComponent, 0x7DF54114u);
ENTT_HASH__(AreaAttackComponent, 0x66E56DDFu);
ENTT_HASH__(ArmorFlyEnabledFlagComponent, 0xFA93038Fu);
ENTT_HASH__(ArmorItemComponent, 0xD26DCAA6u);
ENTT_HASH__(ArmorStandPoseIndexComponent, 0x86D744F2u);
ENTT_HASH__(ArmorStandVariableIndexComponent, 0x070151D7u);
ENTT_HASH__(AssignSynchedActorDataComponent, 0xE98C1DA0u);
ENTT_HASH__(AtmosphereIdentifierComponent, 0x5DAF251Du);
ENTT_HASH__(AtomicEntityAnimationContextComponent, 0xE884A0C9u);
ENTT_HASH__(AtomicEntityAnimStateComponent, 0xAB5555D2u);
ENTT_HASH__(AtomicEntityComponent, 0x35CA8E76u);
ENTT_HASH__(AtomicEntityInitDataComponent, 0x81B3FD80u);
ENTT_HASH__(AtomicEntityLocatorComponent, 0x818AF3BAu);
ENTT_HASH__(AtomicEntityMolangVariablesComponent, 0xB6A07C77u);
ENTT_HASH__(AtomicEntityMotionComponent, 0x0FB5CF74u);
ENTT_HASH__(AtomicEntityNeedsInitializationComponent, 0x16D7C84Fu);
ENTT_HASH__(AtomicEntityParticleTrackingComponent, 0x0C02184Bu);
ENTT_HASH__(AtomicEntityTransformComponent, 0xB2A9DDE8u);
ENTT_HASH__(AttackAnimationComponent, 0xB5659F20u);
ENTT_HASH__(AttackCooldownComponent, 0x58EFE4BFu);
ENTT_HASH__(AttributeRequestComponent, 0x4AD4B57Fu);
ENTT_HASH__(AttributesComponent, 0xFD3B0613u);
ENTT_HASH__(AudioEmitterComponent, 0xE575DE9Cu);
ENTT_HASH__(AutoClimbTravelFlagComponent, 0x777A5678u);
ENTT_HASH__(AutonomousActorComponent, 0x7EE81405u);
ENTT_HASH__(AutoStepRequestFlagComponent, 0xBAA9695Au);
ENTT_HASH__(AxisAlignedComponent, 0x55EED527u);
ENTT_HASH__(BalloonableComponent, 0x2A953483u);
ENTT_HASH__(BalloonComponent, 0x8841907Bu);
ENTT_HASH__(BarterComponent, 0xD3717658u);
ENTT_HASH__(BaseGameVersionComponent, 0x75C382E5u);
ENTT_HASH__(BatFlagComponent, 0xC2A6EC29u);
ENTT_HASH__(BeeFlagComponent, 0x62886B5Cu);
ENTT_HASH__(BehaviorComponent, 0x34EE3662u);
ENTT_HASH__(BiomeTagComponent, 0x85575A9Cu);
ENTT_HASH__(BlazeFlagComponent, 0x1C555660u);
ENTT_HASH__(BlockBreakSensorComponent, 0xD2B0CE62u);
ENTT_HASH__(BlockClimberComponent, 0xDEC6D40Fu);
ENTT_HASH__(BlockCollisionEvaluationQueueComponent, 0xEF62451Au);
ENTT_HASH__(BlockComponentFactory, 0x1A1DDB79u);
ENTT_HASH__(BlockComponentGroupDescription, 0x7CC5F512u);
ENTT_HASH__(BlockCustomComponentsComponentDescription, 0xCCE250BAu);
ENTT_HASH__(BlockEntityFallOnConfigurationComponentDescription, 0xC2429586u);
ENTT_HASH__(BlockLootComponentDescription, 0x394A652Fu);
ENTT_HASH__(BlockMovementSlowdownAppliedComponent, 0xE315E68Eu);
ENTT_HASH__(BlockMovementSlowdownImmunityComponent, 0x8340EC7Fu);
ENTT_HASH__(BlockMovementSlowdownMultiplierComponent, 0xF6091F58u);
ENTT_HASH__(BlockPosTrackerComponent, 0xA9482F13u);
ENTT_HASH__(BlockPrecipitationInteractionsComponentDescription, 0xA5FA050Fu);
ENTT_HASH__(BlockSourceComponent, 0xA2E26A5Au);
ENTT_HASH__(BlockTickConfigurationComponentDescription, 0xA84D8024u);
ENTT_HASH__(BoatFlagComponent, 0x3EB91730u);
ENTT_HASH__(BoatMovementComponent, 0x9671BA31u);
ENTT_HASH__(BoatPaddleComponent, 0x86FCCB26u);
ENTT_HASH__(BodyControlComponent, 0x293C76FDu);
ENTT_HASH__(BoostableComponent, 0xACD04D73u);
ENTT_HASH__(BossComponent, 0xF54C2A4Bu);
ENTT_HASH__(BounceComponent, 0x5A31ED98u);
ENTT_HASH__(BounceGravityCorrectionComponent, 0x7F176DF4u);
ENTT_HASH__(BreakBlocksComponent, 0x02531A9Du);
ENTT_HASH__(BreakDoorAnnotationComponent, 0xF8E6BFD8u);
ENTT_HASH__(BreaksFallingBlocksFlagComponent, 0xBEC43653u);
ENTT_HASH__(BreathableComponent, 0x74BA435Eu);
ENTT_HASH__(BreedableComponent, 0x283C18ECu);
ENTT_HASH__(BribeableComponent, 0x8F990EF0u);
ENTT_HASH__(BrushEffectsCooldownComponent, 0xD0D19369u);
ENTT_HASH__(BucketableComponent, 0x7FEE0A2Eu);
ENTT_HASH__(BundleInteractionItemComponent, 0xFD7084CBu);
ENTT_HASH__(BuoyancyComponent, 0xFEB9120Eu);
ENTT_HASH__(BuoyancyFloatRequestComponent, 0xC9535337u);
ENTT_HASH__(BurnsInDaylightComponent, 0xAA5EC233u);
ENTT_HASH__(CamelFlagComponent, 0x4AE91E52u);
ENTT_HASH__(CameraAimAssistActorPriorityClientComponent, 0x4D09F845u);
ENTT_HASH__(CameraAimAssistActorPriorityServerComponent, 0x2410B419u);
ENTT_HASH__(CameraAimAssistAllowedFlagComponent, 0xDCE60989u);
ENTT_HASH__(CameraAimAssistBlockTargetsComponent, 0x3F0E08F8u);
ENTT_HASH__(CameraAimAssistCachedDataComponent, 0xDB55E891u);
ENTT_HASH__(CameraAimAssistCachedFrustumComponent, 0xA20A51FFu);
ENTT_HASH__(CameraAimAssistCachedPositionDataComponent, 0x9967E238u);
ENTT_HASH__(CameraAimAssistCategoryUpdaterComponent, 0xE38AC3F4u);
ENTT_HASH__(CameraAimAssistComponent, 0x15374807u);
ENTT_HASH__(CameraAimAssistDataRegistryComponent, 0xD73AB3E2u);
ENTT_HASH__(CameraAimAssistDataRegistryDirtyComponent, 0x77E141B8u);
ENTT_HASH__(CameraAimAssistEntityExcludedStatusComponent, 0xFB767716u);
ENTT_HASH__(CameraAimAssistEntityTargetComponent, 0xC1627E35u);
ENTT_HASH__(CameraAimAssistPresetComponent, 0x4339D8A2u);
ENTT_HASH__(CameraAimAssistRegistryComponent, 0xB3A6D8BAu);
ENTT_HASH__(CameraAimAssistRequestComponent, 0x69CA9E04u);
ENTT_HASH__(CameraAimAssistResetEntityExcludedStatusFlagComponent, 0x4C68A08Du);
ENTT_HASH__(CameraAimAssistResultComponent, 0x62A60B9Cu);
ENTT_HASH__(CameraAimAssistRotationOverrideComponent, 0x31A824EDu);
ENTT_HASH__(CameraAimAssistSettingsComponent, 0x7B64B040u);
ENTT_HASH__(CameraAimAssistTargetComponent, 0xED090BFCu);
ENTT_HASH__(CameraAimAssistTickComponent, 0xFA8CD650u);
ENTT_HASH__(CameraAPIComponent, 0xAA49A319u);
ENTT_HASH__(CameraClientInstanceComponent, 0xD5D07309u);
ENTT_HASH__(CameraOutOfRangeWarningSentComponent, 0x87FD7AD9u);
ENTT_HASH__(CameraShakeComponent, 0x84246E07u);
ENTT_HASH__(CameraSplineDataRegistryComponent, 0x2E0151A7u);
ENTT_HASH__(CanAlwaysAutoStepFlagComponent, 0x91E56036u);
ENTT_HASH__(CanBeHijackedByPassengerComponent, 0xB9F32703u);
ENTT_HASH__(CanDestroyInCreativeItemComponent, 0x543CBE87u);
ENTT_HASH__(CanJoinRaidComponent, 0xAF0B3EA8u);
ENTT_HASH__(CanMakeAudibleSoundsComponent, 0x7A0369AAu);
ENTT_HASH__(CanSeeInvisibleFlagComponent, 0xA74DE0E8u);
ENTT_HASH__(CanStandOnPowderSnowComponent, 0xB639C3B7u);
ENTT_HASH__(CanStandOnPowderSnowFromEquipmentComponent, 0x4EAC501Fu);
ENTT_HASH__(CanVehicleSprintFlagComponent, 0x37364548u);
ENTT_HASH__(CatVariableIndexComponent, 0x793C70ECu);
ENTT_HASH__(CelebrateHuntComponent, 0xD1E5283Eu);
ENTT_HASH__(CerealItemComponentFactory, 0x22D35115u);
ENTT_HASH__(ChargeableItemComponentLegacyFactoryData, 0xC8179924u);
ENTT_HASH__(ChickenFlagComponent, 0x2BFC01D5u);
ENTT_HASH__(ChickenVariableIndexComponent, 0x2654859Fu);
ENTT_HASH__(ChunkPositionComponent, 0x7CEEAC38u);
ENTT_HASH__(ckPosComponent, SlimeWasOnGroundPreNormalTickComponent, WitherBossPreAIStepResultComponent > , 0xA5553960u);
ENTT_HASH__(ClientAcceptanceThresholdsComponent, 0x759E3440u);
ENTT_HASH__(ClientFireActorEventComponent, 0xEAF7317Cu);
ENTT_HASH__(ClientFireSoundEventComponent, 0xA99974FEu);
ENTT_HASH__(ClientInputLockComponent, 0x27770608u);
ENTT_HASH__(ClientInputLockLastComponent, 0x4A1723ECu);
ENTT_HASH__(ClientParticleInitializationComponent, 0x5EB4E8FBu);
ENTT_HASH__(ClientParticleTerminationComponent, 0x9A1BD725u);
ENTT_HASH__(ClientParticleTrackingComponent, 0x6C14CA9Cu);
ENTT_HASH__(ClientPredictionSyncTimerComponent, 0x6B53A2F0u);
ENTT_HASH__(ClientPushDimensionLoadingScreenComponent, 0xACF57B35u);
ENTT_HASH__(ClientSynchedActorEventComponent, 0x6206ACD0u);
ENTT_HASH__(ClientSynchedSoundEventComponent, 0xFD37A0A2u);
ENTT_HASH__(ClientVibrationComponent, 0x07A20C57u);
ENTT_HASH__(ClimbingLadderBlockComponent, 0xA09EEB16u);
ENTT_HASH__(CodebuilderComponent, 0x8B13E7AEu);
ENTT_HASH__(CollidableMobFlagComponent, 0xA492DB71u);
ENTT_HASH__(CollidableMobNearFlagComponent, 0x36572A4Bu);
ENTT_HASH__(CollisionBoxComponent, 0x9667787Fu);
ENTT_HASH__(CollisionFlagComponent, 0xF3F3A3CCu);
ENTT_HASH__(ColorGradingIdentifierComponent, 0x6DA1F536u);
ENTT_HASH__(CombatRegenerationComponent, 0xB1AAC801u);
ENTT_HASH__(CommandBlockComponent, 0x42D5DE32u);
ENTT_HASH__(CompanionFirstPersonComponent, 0x0959B7C3u);
ENTT_HASH__(CompanionFirstPersonStateComponent, 0x8E65D134u);
ENTT_HASH__(CompanionFollowComponent, 0x3FB1108Fu);
ENTT_HASH__(CompanionOwnerComponent, 0xFF930803u);
ENTT_HASH__(CompanionOwnerRefComponent, 0x1446C194u);
ENTT_HASH__(ComponentItem, 0x4017F40Fu);
ENTT_HASH__(ComponentItemComponentData_v1_20_30, 0xBE1933C9u);
ENTT_HASH__(ComponentItemComponentData_v1_20_40, 0x3C253316u);
ENTT_HASH__(ComponentItemData_v1_19_83, 0x709707DCu);
ENTT_HASH__(ComponentItemData_v1_20, 0x3130DF18u);
ENTT_HASH__(ComponentItemData_v1_20_20, 0xDDB6107Fu);
ENTT_HASH__(ComponentItemData_v1_20_30, 0xD7B3C876u);
ENTT_HASH__(ComponentItemData_v1_20_40, 0xD9A6FFA9u);
ENTT_HASH__(ComponentItemData_v1_20_50, 0xD3A4B7A0u);
ENTT_HASH__(ComponentItemData_v1_20_60, 0x65AC593Bu);
ENTT_HASH__(ComponentItemData_v1_20_80, 0xE1C52155u);
ENTT_HASH__(ComponentItemData_v1_21_10, 0xAAFEBDA5u);
ENTT_HASH__(ComponentItemData_v1_21_110, 0xBE022986u);
ENTT_HASH__(ComponentItemData_v1_21_30, 0xB7034DB7u);
ENTT_HASH__(ComponentItemData_v1_21_40, 0xACF1F4D8u);
ENTT_HASH__(ComponentItemData_v1_21_50, 0x32F50661u);
ENTT_HASH__(ComponentItemData_v1_21_60, 0x38F74E6Au);
ENTT_HASH__(ComponentItemData_v1_21_80, 0x34E83D94u);
ENTT_HASH__(ComponentItemData_v1_21_90, 0x3AEA859Du);
ENTT_HASH__(ComponentItemData_v1_26_0, 0x91AF4CEDu);
ENTT_HASH__(ComponentItemDataAll_Latest, 0x7F86BF24u);
ENTT_HASH__(CompostableItemComponent, 0x00E11102u);
ENTT_HASH__(ConditionalBandwidthOptimizationComponent, 0x62A584C8u);
ENTT_HASH__(ContainerComponent, 0x1779E2C7u);
ENTT_HASH__(ContainerScreenContextComponent, 0x744A4D6Au);
ENTT_HASH__(ControlledByLocalInstanceComponent, 0x9C970E15u);
ENTT_HASH__(ControlSchemeComponent, 0x02C74480u);
ENTT_HASH__(ControlSchemeSetByCommandComponent, 0x8820A70Au);
ENTT_HASH__(CooldownItemComponent, 0x580C7252u);
ENTT_HASH__(CurrentlyImmuneToFallDamageComponent, 0xA89D24C8u);
ENTT_HASH__(CurrentlyStandingOnBlockComponent, 0x8B187408u);
ENTT_HASH__(CurrentTickComponent, 0x5FDB6D9Au);
ENTT_HASH__(CushionFlagComponent, 0xDA9AB2D1u);
ENTT_HASH__(CushionSurvivalComponent, 0xC08A99E5u);
ENTT_HASH__(CustomDepenetrationMagnitudeComponent, 0xF6501D97u);
ENTT_HASH__(CustomSizeUpdateComponent, 0x42637D8Du);
ENTT_HASH__(CuttableLeashComponent, 0x4FCC7A49u);
ENTT_HASH__(DamageItemComponent, 0xA65F480Au);
ENTT_HASH__(DamageNearbyMobsComponent, 0x832B4523u);
ENTT_HASH__(DamageOverTimeComponent, 0x3E888746u);
ENTT_HASH__(DamageSensorComponent, 0xAF9A1D7Du);
ENTT_HASH__(DanceComponent, 0x5EEC70FBu);
ENTT_HASH__(DashActionComponent, 0xA8D965EAu);
ENTT_HASH__(DashCooldownTimerComponent, 0x5FA23EB4u);
ENTT_HASH__(DashJumpFlagComponent, 0x223D499Au);
ENTT_HASH__(DealKineticDamageComponent, 0x6B006DFEu);
ENTT_HASH__(DeathTickingComponent, 0x3E3ACACBu);
ENTT_HASH__(DebugCameraIsActiveComponent, 0x25D8BF40u);
ENTT_HASH__(DepenetrationComponent, 0x256B41F6u);
ENTT_HASH__(DespawnComponent, 0xB1457044u);
ENTT_HASH__(DiggerItemComponent, 0x1DB2D393u);
ENTT_HASH__(DiggerItemComponentLegacyFactoryData, 0x75E60082u);
ENTT_HASH__(DimensionBoundComponent, 0x4DFA2194u);
ENTT_HASH__(DimensionStateComponent, 0x9557C713u);
ENTT_HASH__(DimensionTransferTelemetryComponent, 0xD9CC5FB2u);
ENTT_HASH__(DimensionTransitionComponent, 0x39C58D8Bu);
ENTT_HASH__(DimensionTypeComponent, 0xAF993816u);
ENTT_HASH__(DiscardFrictionFlagComponent, 0x40BED7F4u);
ENTT_HASH__(DisplayEntityComponent, 0xC1137A49u);
ENTT_HASH__(DisplayNameItemComponent, 0xB8C67030u);
ENTT_HASH__(DisplayObjectMessageRequestComponent, 0x99360655u);
ENTT_HASH__(DoesServerAuthOnlyDismountFlagComponent, 0xA6E0605Fu);
ENTT_HASH__(DolphinFlagComponent, 0xCBD360FCu);
ENTT_HASH__(DryingOutTimerComponent, 0x1363B132u);
ENTT_HASH__(DurabilityItemComponent, 0xDEABF1C0u);
ENTT_HASH__(DwellerComponent, 0x629EF917u);
ENTT_HASH__(DyeableItemComponent, 0xDDB617B9u);
ENTT_HASH__(DynamicPropertiesComponent, 0xBEF5AAF6u);
ENTT_HASH__(DynamicRenderOffsetComponent, 0x68B69EC0u);
ENTT_HASH__(EatAnimationComponent, 0x90F18778u);
ENTT_HASH__(EconomyTradeableComponent, 0xED58C0E2u);
ENTT_HASH__(EcsEventDispatcherComponent, 0xA11037FEu);
ENTT_HASH__(EditorActorPausedComponent, 0x0A6AE8F2u);
ENTT_HASH__(EditorActorPauseTickNeededComponent, 0x4BF5C6D0u);
ENTT_HASH__(EditorActorUnpausableComponent, 0x4BCA3F98u);
ENTT_HASH__(EditorWidgetDisplayEntityComponent, 0x021F1044u);
ENTT_HASH__(EditorWidgetDisplayEntitySelectableComponent, 0x4220448Cu);
ENTT_HASH__(EjectedByActivatorRailFlagComponent, 0x132ABCC2u);
ENTT_HASH__(ElytraFlightTimeTicksComponent, 0xD5FCBE52u);
ENTT_HASH__(EmitParticleRequestComponent, 0xF07F5258u);
ENTT_HASH__(EmotePlayedTelemetryDataComponent, 0x5CE92802u);
ENTT_HASH__(EnchantableItemComponent, 0x1B04BC60u);
ENTT_HASH__(EnderDragonFlagComponent, 0xA9F3CCC7u);
ENTT_HASH__(EnderManFlagComponent, 0x4D4C5624u);
ENTT_HASH__(EntitiesPendingEnterVolumeComponent, 0x1E1C6FBAu);
ENTT_HASH__(EntityArmorEquipmentSlotMappingComponent, 0x461D2D06u);
ENTT_HASH__(EntityNeedsInitializeFlagComponent, 0x3723BF96u);
ENTT_HASH__(EntityPlacerItemComponent, 0x6C5F1C85u);
ENTT_HASH__(EntityPlacerItemComponentLegacyFactoryData, 0x1604CC28u);
ENTT_HASH__(EntitySensorComponent, 0x8E52AB7Bu);
ENTT_HASH__(EntityStorageKeyComponent, 0x9739CD15u);
ENTT_HASH__(entMovementComponent, SkipAiStepComponent, SkipNormalTickComponent, SkipMobTravelComponent > , 0x69C4D4B8u);
ENTT_HASH__(EnvironmentSensorComponent, 0xED5D421Bu);
ENTT_HASH__(EquipItemComponent, 0xFF40DE33u);
ENTT_HASH__(EquippableComponent, 0x88F64E44u);
ENTT_HASH__(EventingDispatcherComponent, 0x9814D403u);
ENTT_HASH__(EventingRequestQueueComponent, 0x9693B204u);
ENTT_HASH__(ExecuteEntityEventRequestComponent, 0xD4FDCB95u);
ENTT_HASH__(ExecuteEventOnBlockRequestComponent, 0x7C0CBE6Eu);
ENTT_HASH__(ExhaustionComponent, 0xC9266A48u);
ENTT_HASH__(ExitFromPassengerFlagComponent, 0xAE2A71E8u);
ENTT_HASH__(ExperienceOrbFlagComponent, 0x2D4868D7u);
ENTT_HASH__(ExperienceRewardComponent, 0x7D118A85u);
ENTT_HASH__(ExplodeComponent, 0xEBB59495u);
ENTT_HASH__(ExternalDataComponent, 0xA8A30F19u);
ENTT_HASH__(EyeOfEnderFlagComponent, 0x956B1A6Cu);
ENTT_HASH__(FallDamageResultComponent, 0xC02D500Fu);
ENTT_HASH__(FallDistanceComponent, 0xCE6B34F6u);
ENTT_HASH__(FallFlyTicksComponent, 0x488C0DF4u);
ENTT_HASH__(FallingBlockFlagComponent, 0x0928AFDEu);
ENTT_HASH__(FireAnimationTrackerComponent, 0xE44BA1DAu);
ENTT_HASH__(FireEventCaravanChangedRequestComponent, 0x501EA7A1u);
ENTT_HASH__(FireResistantItemComponent, 0xCD7AF43Eu);
ENTT_HASH__(FireworksRocketFlagComponent, 0x11641AA2u);
ENTT_HASH__(FishAnimationComponent, 0x63B81BF6u);
ENTT_HASH__(FishFlagComponent, 0x1B803BE8u);
ENTT_HASH__(FishingHookFlagComponent, 0xDEB3F423u);
ENTT_HASH__(FishVariableIndexComponent, 0x8DDC1CB0u);
ENTT_HASH__(FlockingComponent, 0xD6F20AD9u);
ENTT_HASH__(FlopVelocityFactorComponent, 0x8B3CF80Bu);
ENTT_HASH__(FogCommandComponent, 0x81576D3Bu);
ENTT_HASH__(FoodItemComponent, 0x0337E001u);
ENTT_HASH__(FoodItemComponentData_v1_20_30, 0x5BF71FD4u);
ENTT_HASH__(FoodItemComponentLegacyFactoryData, 0xE15454ECu);
ENTT_HASH__(ForceSendMotionPacketComponent, 0x147BBA17u);
ENTT_HASH__(FreeCameraControlledComponent, 0xC9989695u);
ENTT_HASH__(FreezingComponent, 0x47E62980u);
ENTT_HASH__(FreezingImmuneComponent, 0x11C35AFBu);
ENTT_HASH__(FreezingImmuneFromEquipmentComponent, 0x578B6D03u);
ENTT_HASH__(FreezingVulnerableComponent, 0x2C8F0870u);
ENTT_HASH__(FrictionModifierOverrideComponent, 0x0CBB7191u);
ENTT_HASH__(FromAllEntitiesSystem<ActorMovementTickNeededComponent, InterpolateMovementNeededComponent>, 0x170001CBu);
ENTT_HASH__(FuelItemComponent, 0xED8CED1Du);
ENTT_HASH__(GainedRaidOmenAtPositionComponent, 0x17099221u);
ENTT_HASH__(GallopSoundCounterComponent, 0xB5D97C0Au);
ENTT_HASH__(GameEventListenerComponent, 0x232C54ACu);
ENTT_HASH__(GameEventMovementTrackingComponent, 0x966A4DD4u);
ENTT_HASH__(GeneticsComponent, 0xCD3E60E0u);
ENTT_HASH__(GetAttachPositionViewsComponent, 0x7CDC45B4u);
ENTT_HASH__(GhastVariableIndexComponent, 0xE01D2B65u);
ENTT_HASH__(GiveableComponent, 0x48D7C703u);
ENTT_HASH__(GlidingCollisionDamageComponent, 0x02E4577Du);
ENTT_HASH__(GlidingTravelFlagComponent, 0x27A011EEu);
ENTT_HASH__(GlintItemComponent, 0xB0377AB7u);
ENTT_HASH__(GlobalActorComponent, 0x8DAB9612u);
ENTT_HASH__(GlobalActorRenderComponent, 0x3890AFF6u);
ENTT_HASH__(GlobalPauseComponent, 0x12510ED7u);
ENTT_HASH__(GlobalTextureGroupStateComponent, 0xDC313768u);
ENTT_HASH__(GoalSelectorComponent, 0xADEC332Eu);
ENTT_HASH__(GoatVariableIndexComponent, 0xD827EB6Du);
ENTT_HASH__(GroundTravelFlagComponent, 0xE1CA9E6Bu);
ENTT_HASH__(GroupSizeComponent, 0x5BC3B8A0u);
ENTT_HASH__(GrowsCropComponent, 0xAC232764u);
ENTT_HASH__(GuardianFlagComponent, 0x0F08CDD7u);
ENTT_HASH__(HandEquippedItemComponent, 0x4785DE8Du);
ENTT_HASH__(HangingActorFlagComponent, 0x89BEED7Du);
ENTT_HASH__(HasAutoSteppedComponent, 0x37C138FAu);
ENTT_HASH__(HasTeleportedFlagComponent, 0x42CB24CAu);
ENTT_HASH__(HealableComponent, 0x471DE162u);
ENTT_HASH__(HeartbeatClientComponent, 0xEB459B47u);
ENTT_HASH__(HeartbeatServerComponent, 0xE35AF72Bu);
ENTT_HASH__(HideComponent, 0x2EB18FA8u);
ENTT_HASH__(HijackMountNavigationComponent, 0x1870AFEBu);
ENTT_HASH__(HitboxComponent, 0x9B97C2B2u);
ENTT_HASH__(HitResultComponent, 0x5AF5CF0Eu);
ENTT_HASH__(HomeComponent, 0xA8CCD03Du);
ENTT_HASH__(HopperComponent, 0x2C01093Au);
ENTT_HASH__(HorizontalCollisionFlagComponent, 0xD5EE0BD8u);
ENTT_HASH__(HorseAnimationComponent, 0x312528C3u);
ENTT_HASH__(HorseFlagComponent, 0x5A7992D7u);
ENTT_HASH__(HorseLandedOnGroundFlagComponent, 0xB35E1CA1u);
ENTT_HASH__(HorseStandCounterComponent, 0x23EC0E39u);
ENTT_HASH__(HorseVariableIndexComponent, 0x044D81B5u);
ENTT_HASH__(HorseWasOnGroundPreTravelComponent, 0x8D506F49u);
ENTT_HASH__(HoverTextColorItemComponent, 0x5A86FC51u);
ENTT_HASH__(HumanoidMonsterAttackStateComponent, 0x8ECABE40u);
ENTT_HASH__(HurtOnConditionComponent, 0x87FA4911u);
ENTT_HASH__(IconItemComponent, 0x01EC103Au);
ENTT_HASH__(IconItemComponentLegacyFactoryData, 0x55F5A559u);
ENTT_HASH__(IgnoreCannotBeAttackedComponent, 0x42AD0D9Fu);
ENTT_HASH__(IgnoreHeadInWaterForSpawnSoundComponent, 0x8E298085u);
ENTT_HASH__(IgnoresEntityInsideFlagComponent, 0x105AE458u);
ENTT_HASH__(IllagerBeastBlockedComponent, 0xAE3E627Du);
ENTT_HASH__(IllagerBeastFlagComponent, 0x9D1F2973u);
ENTT_HASH__(ImitateMobSoundsComponent, 0x462EC81Fu);
ENTT_HASH__(ImmuneToLavaDragComponent, 0xDD2DA6E4u);
ENTT_HASH__(InsideBlockComponent, 0xC1C8FB69u);
ENTT_HASH__(InsideBlockNotifierComponent, 0x9E9050DBu);
ENTT_HASH__(InsideBlockWithPosAndBlockComponent<CactusBlockFlag>, 0x67858013u);
ENTT_HASH__(InsideBlockWithPosAndBlockComponent<EndPortalBlockFlag>, 0x5603C16Du);
ENTT_HASH__(InsideBlockWithPosAndBlockComponent<HoneyBlockFlag>, 0xC83BBC35u);
ENTT_HASH__(InsideBlockWithPosAndBlockComponent<PowderSnowBlockFlag>, 0xDEEBD21Au);
ENTT_HASH__(InsideBlockWithPosAndBlockComponent<SweetBerryBushBlockFlag>, 0x3A26E826u);
ENTT_HASH__(InsideBlockWithPosAndBlockComponent<WebBlockFlag>, 0xDD5AFFB4u);
ENTT_HASH__(InsideBlockWithPosComponent<WaterlilyBlockFlag>, 0x61218717u);
ENTT_HASH__(InsideBubbleColumnBlockComponent, 0x8C1D39F1u);
ENTT_HASH__(InsideGenericBlockComponent, 0x860E2312u);
ENTT_HASH__(InsideOnewayBlockComponent, 0x9A5E12C6u);
ENTT_HASH__(InsideSlowingSweetBerryBushBlockComponent, 0x03ABF17Eu);
ENTT_HASH__(InsomniaComponent, 0xB8990E08u);
ENTT_HASH__(InstantDespawnComponent, 0xAB97E0C7u);
ENTT_HASH__(InteractButtonItemComponent, 0xD91624A7u);
ENTT_HASH__(InteractComponent, 0xA352344Au);
ENTT_HASH__(InteractPreventDefaultFlagComponent, 0xE34861C1u);
ENTT_HASH__(InterpolateMovementNeededComponent, 0x91A67F13u);
ENTT_HASH__(InvalidChunkFoundWhileTeleportingFlagComponent, 0x2AAB7E92u);
ENTT_HASH__(IronGolemVariableIndexComponent, 0x0905297Au);
ENTT_HASH__(IsBeingTeleportedFlagComponent, 0x2D854C1Bu);
ENTT_HASH__(IsChasingDuringPlayFlagComponent, 0x44AEDE4Au);
ENTT_HASH__(IsDeadFlagComponent, 0x710A62C4u);
ENTT_HASH__(IsFishableFlagComponent, 0x8052842Cu);
ENTT_HASH__(IsHorizontalPoseFlagComponent, 0x2430E499u);
ENTT_HASH__(IsNearDolphinsFlagComponent, 0x5DFF502Bu);
ENTT_HASH__(IsOnHotBlockFlagComponent, 0x15EC0D85u);
ENTT_HASH__(IsPanickingFlagComponent, 0x5B05B508u);
ENTT_HASH__(IsShowingCreditsFlagComponent, 0x7A30D89Fu);
ENTT_HASH__(IsSolidMobComponent, 0x3B207669u);
ENTT_HASH__(IsSolidMobNearbyComponent, 0x96B71D6Cu);
ENTT_HASH__(ItemActorFlagComponent, 0x2151BD4Cu);
ENTT_HASH__(ItemComponent, 0x5C0BE1F5u);
ENTT_HASH__(ItemInUseComponent, 0x05B90AEFu);
ENTT_HASH__(ItemInUseTicksDuringMovementComponent, 0x9B80C0C9u);
ENTT_HASH__(ItemStackNetManagerEnabledComponent, 0xD4B6B3C4u);
ENTT_HASH__(ItemUseSlowdownModifierComponent, 0x867FC92Cu);
ENTT_HASH__(JoinRaidQueuedFlagComponent, 0x769A7CD5u);
ENTT_HASH__(JumpControlComponent, 0x2F50F705u);
ENTT_HASH__(JumpFromGroundRequestComponent, 0x4EA8C276u);
ENTT_HASH__(JumpPendingScaleComponent, 0x4BA3CA4Du);
ENTT_HASH__(JumpRidingScaleComponent, 0xFA484B91u);
ENTT_HASH__(JumpTicksComponent, 0xAC923948u);
ENTT_HASH__(KeepRidingEvenIfTooLargeForVehicleFlagComponent, 0xCDBE8827u);
ENTT_HASH__(KineticWeaponItemComponent, 0x36AB5FA2u);
ENTT_HASH__(LavaSlimeFlagComponent, 0x16B2C49Eu);
ENTT_HASH__(LavaSlimeJumpRequestComponent, 0x18BA6395u);
ENTT_HASH__(LavaTravelFlagComponent, 0xE195F66Cu);
ENTT_HASH__(LeashableComponent, 0xEB23849Du);
ENTT_HASH__(LeashableToComponent, 0xF6F3E86Eu);
ENTT_HASH__(LeashedEntitiesComponent, 0x12220BBFu);
ENTT_HASH__(LeashKnotFlagComponent, 0x8AD033ADu);
ENTT_HASH__(LegacyActorArmorListenerContainerOwnerComponent, 0xD6448867u);
ENTT_HASH__(LegacyMolangVariableComponent, 0x78D05959u);
ENTT_HASH__(LegacyTradeableComponent, 0x9338D653u);
ENTT_HASH__(lEntitiesSystem<TriggerJumpRequestComponent, PowerJumpFlagComponent, DashJumpFlagComponent>, 0xF85B292Eu);
ENTT_HASH__(LevelComponent, 0x5649B5F8u);
ENTT_HASH__(LevelTickTrackingComponent, 0x060EB180u);
ENTT_HASH__(LevitateTravelFlagComponent, 0xFE3B5CE4u);
ENTT_HASH__(LieDownAnimationComponent, 0x3069067Cu);
ENTT_HASH__(LightingIdentifierComponent, 0xF3F13E51u);
ENTT_HASH__(LiquidClippedItemComponent, 0x055CE25Au);
ENTT_HASH__(LiquidTravelFlagComponent, 0x3E7D1356u);
ENTT_HASH__(LlamaVariableIndexComponent, 0x78285705u);
ENTT_HASH__(LoadedChunksComponent, 0x0D1FA129u);
ENTT_HASH__(LoadingScreenPacketSenderComponent, 0x378CB8D9u);
ENTT_HASH__(LoadingScreenStateChangeComponent, 0x7F6E400Bu);
ENTT_HASH__(LoadingStateComponent, 0x48F5D1E7u);
ENTT_HASH__(LocalConstBlockSourceFactoryComponent, 0xC695B914u);
ENTT_HASH__(LocalMoveVelocityComponent, 0x10257C61u);
ENTT_HASH__(LocalPlayerComponent, 0xACB47B38u);
ENTT_HASH__(LocalPlayerDimensionWaitComponent, 0xE115DC31u);
ENTT_HASH__(LocalPlayerJumpRequestComponent, 0xDA6293F1u);
ENTT_HASH__(LocalPlayerPrePlayerTravelComponent, 0x856A9636u);
ENTT_HASH__(LocalSpatialEntityFetcherFactoryComponent, 0x5C4C91CFu);
ENTT_HASH__(LodestoneCompassComponent, 0xF48187D3u);
ENTT_HASH__(LookControlComponent, 0xCC327B76u);
ENTT_HASH__(LookedAtComponent, 0x26103101u);
ENTT_HASH__(MakesLavaStepSoundComponent, 0x0754B25Au);
ENTT_HASH__(ManagedWanderingTraderComponent, 0xE5FD420Cu);
ENTT_HASH__(MaxAutoStepComponent, 0x9AAE5D7Fu);
ENTT_HASH__(MaxStackSizeItemComponent, 0xD95523C4u);
ENTT_HASH__(MinecartFlagComponent, 0xFF6FF7BDu);
ENTT_HASH__(MinecartPreNormalTickBlockPosComponent, 0x1212D2C9u);
ENTT_HASH__(MinecraftGameShimComponent, 0x8798EAD2u);
ENTT_HASH__(MingleComponent, 0xEB8EF15Eu);
ENTT_HASH__(MobAllowStandSlidingFlagComponent, 0x403A4505u);
ENTT_HASH__(MobAnimationComponent, 0xFF0A6FE8u);
ENTT_HASH__(MobBodyRotationComponent, 0xD7F64BBAu);
ENTT_HASH__(MobEffectComponent, 0xBB893C63u);
ENTT_HASH__(MobEffectImmunityComponent, 0xE36ADD6Du);
ENTT_HASH__(MobEffectsComponent, 0xE6A1B550u);
ENTT_HASH__(MobFlagComponent, 0x14EA24A2u);
ENTT_HASH__(MobHurtTimeComponent, 0xD7A3585Cu);
ENTT_HASH__(MobIsImmobileFlagComponent, 0xA1BC775Au);
ENTT_HASH__(MobIsJumpingFlagComponent, 0x8FD20E98u);
ENTT_HASH__(MobIsSuffocatingFlagComponent, 0x421E5D37u);
ENTT_HASH__(MobJumpComponent, 0xC52C8F78u);
ENTT_HASH__(MobOnPlayerJumpRequestComponent, 0x787C10F9u);
ENTT_HASH__(MobRotationComponent, 0x66E7134Au);
ENTT_HASH__(MobTravelComponent, 0x39CF8D64u);
ENTT_HASH__(MobVariableIndexComponent, 0x056FA3F6u);
ENTT_HASH__(MonsterFlagComponent, 0x6FA87086u);
ENTT_HASH__(MountTamingComponent, 0xBA113F43u);
ENTT_HASH__(MoveControlComponent, 0x15AE4A44u);
ENTT_HASH__(MovedOnSpawnComponent, 0xC5413093u);
ENTT_HASH__(MoveInputComponent, 0x018B1887u);
ENTT_HASH__(MovementAbilitiesComponent, 0x6DE78DC5u);
ENTT_HASH__(MovementAttributesComponent, 0xA795A68Cu);
ENTT_HASH__(MovementCorrectionTelemetryComponent, 0x602D12F2u);
ENTT_HASH__(MovementEffectsComponent, 0x5C92321Du);
ENTT_HASH__(MovementInterpolatorComponent, 0x02BC1330u);
ENTT_HASH__(MovementSoundComponent, 0x387529D2u);
ENTT_HASH__(MovementSpeedComponent, 0x1268662Eu);
ENTT_HASH__(MovementWasCorrectedComponent, 0x8A0C2797u);
ENTT_HASH__(MoveRequestComponent, 0x4C8F7288u);
ENTT_HASH__(MoveTowardsClosestSpaceFlagComponent, 0xE387CDF4u);
ENTT_HASH__(NameableComponent, 0x97D981A9u);
ENTT_HASH__(NavigationComponent, 0xBB725EBEu);
ENTT_HASH__(NeedSetPreviousPositionFlagComponent, 0x9F14535Eu);
ENTT_HASH__(NeedsUpgradeToBodySlotFlagComponent, 0xE02CED08u);
ENTT_HASH__(NetEventCallbackComponent, 0x13C4D576u);
ENTT_HASH__(NetworkComponent, 0xD2342560u);
ENTT_HASH__(NeverChangesSizeFlagComponent, 0xFF648BACu);
ENTT_HASH__(NoActionTimeComponent, 0x4125A80Cu);
ENTT_HASH__(NpcComponent, 0xC5B76C7Fu);
ENTT_HASH__(OcelotVariableIndexComponent, 0x7C67B876u);
ENTT_HASH__(ockWithPosComponent<WaterlilyBlockFlag>, InsideBlockWithPosAndBlockComponent<WebBlockFlag >> , 0x12C9952Au);
ENTT_HASH__(OfferFlowerTickComponent, 0x993046C6u);
ENTT_HASH__(OffsetsComponent, 0xDE21C316u);
ENTT_HASH__(omAllEntitiesSystem<StandOnSpeedAlteringBlockFlagComponent, StandOnOtherBlockFlagComponent>, 0x0F9105B7u);
ENTT_HASH__(onent, LavaSlimeJumpRequestComponent, SquidJumpRequestComponent, OtherJumpRequestComponent > , 0x358EE821u);
ENTT_HASH__(OnEquipmentChangedComponent, 0x769A382Bu);
ENTT_HASH__(OnFireComponent, 0x7E613FF3u);
ENTT_HASH__(OnGroundFlagComponent, 0xC29078A0u);
ENTT_HASH__(OnUseItemComponent, 0x099C72D3u);
ENTT_HASH__(OnUseOnItemComponentLegacyFactoryData, 0x85CD9FDBu);
ENTT_HASH__(OpenDoorAnnotationComponent, 0x2DC83487u);
ENTT_HASH__(OtherJumpRequestComponent, 0xDCCA6EF9u);
ENTT_HASH__(OutOfControlComponent, 0xDBE1CF72u);
ENTT_HASH__(OverflowTickComponent, 0xFDBC0BC1u);
ENTT_HASH__(OverlayAlphaComponent, 0xDC8596C0u);
ENTT_HASH__(PaintingFlagComponent, 0x15A3BFB2u);
ENTT_HASH__(PandaFlagComponent, 0x212D7B30u);
ENTT_HASH__(ParrotFlagComponent, 0xD0EBC272u);
ENTT_HASH__(ParticleEventDispatcherComponent, 0x6D00FC8Fu);
ENTT_HASH__(ParticleEventRequestQueueComponent, 0xDE0BF188u);
ENTT_HASH__(PassengerComponent, 0x98E40C0Eu);
ENTT_HASH__(PassengerRenderingRidingOffsetComponent, 0x33675BF2u);
ENTT_HASH__(PassengersChangedFlagComponent, 0xDF31AAFDu);
ENTT_HASH__(PassengersToPositionComponent, 0x724FA78Du);
ENTT_HASH__(PassengerYRotLimitComponent, 0xE94C0109u);
ENTT_HASH__(PeekComponent, 0x2014C3ADu);
ENTT_HASH__(PendingRemovePassengersComponent, 0x39BFBFA8u);
ENTT_HASH__(PermanentSkipMobAiStepComponent, 0xBBCAEC57u);
ENTT_HASH__(PermanentSkipMobTravelComponent, 0x33A3A48Fu);
ENTT_HASH__(PermanentSkipNormalTickComponent, 0x35DD9377u);
ENTT_HASH__(PermissionFlyFlagComponent, 0xEB223E90u);
ENTT_HASH__(PersistentComponent, 0xFAD8D24Fu);
ENTT_HASH__(PersistSitComponent, 0x1EF58718u);
ENTT_HASH__(PhysicsComponent, 0x142CC0C1u);
ENTT_HASH__(PickComponent, 0x699267C7u);
ENTT_HASH__(PiercingWeaponItemComponent, 0x570A3FD8u);
ENTT_HASH__(PillagerPiglinVariableIndexComponent, 0xB1C195A9u);
ENTT_HASH__(PlanterItemComponent, 0x544D68B5u);
ENTT_HASH__(PlanterItemComponentLegacyFactoryData, 0x4F1EBBD8u);
ENTT_HASH__(PlayerActionComponent, 0x3000F399u);
ENTT_HASH__(PlayerBobComponent, 0x21AB4526u);
ENTT_HASH__(PlayerChangeDimensionRequestComponent, 0x5BE67A98u);
ENTT_HASH__(PlayerComponent, 0xF95D258Fu);
ENTT_HASH__(PlayerDestroyProgressCacheComponent, 0x2764DD80u);
ENTT_HASH__(PlayerDimensionTransferSaveSuspensionComponent, 0xFE64A7F6u);
ENTT_HASH__(PlayerFlyingTravelComponent, 0x42910726u);
ENTT_HASH__(PlayerInputModeComponent, 0xBD68C2E2u);
ENTT_HASH__(PlayerInputRequestComponent, 0x6B04A058u);
ENTT_HASH__(PlayerInteractionModelComponent, 0xA6EFAB90u);
ENTT_HASH__(PlayerIsSleepingFlagComponent, 0xB13F037Au);
ENTT_HASH__(PlayerLoadingScreenComponent, 0x76CA0C67u);
ENTT_HASH__(PlayerMovementSettingsComponent, 0xB212EF87u);
ENTT_HASH__(PlayerPositionModeComponent, 0x324D52CBu);
ENTT_HASH__(PlayerPreMobTravelComponent, 0x2FC5A8D0u);
ENTT_HASH__(PlayerSaveSuspensionComponent, 0xC1E354A3u);
ENTT_HASH__(PoiManagerComponent, 0xE5C48909u);
ENTT_HASH__(PolarBearFlagComponent, 0xF042D78Au);
ENTT_HASH__(PortalCooldownDurationComponent, 0x94211021u);
ENTT_HASH__(PositionPassengerRequestComponent, 0x55DCA772u);
ENTT_HASH__(PostGameEventRequestComponent, 0x73740547u);
ENTT_HASH__(PostImpulseFallDamagePreventionComponent, 0x84225779u);
ENTT_HASH__(PostSplashGameEventRequestComponent, 0x453FBA3Eu);
ENTT_HASH__(PostTickPositionDeltaComponent, 0xF96968B0u);
ENTT_HASH__(PowerJumpFlagComponent, 0x706F184Fu);
ENTT_HASH__(PredictedMovementComponent, 0x18513471u);
ENTT_HASH__(PreferredPathComponent, 0xEC4AC350u);
ENTT_HASH__(PreviousBreathTickComponent, 0x3262916Au);
ENTT_HASH__(PreviousDefinitionsComponent, 0xF6813C1Du);
ENTT_HASH__(PreviousDimensionTypeComponent, 0x45C4901Bu);
ENTT_HASH__(PreviousLeashHolderComponent, 0x34A55CC2u);
ENTT_HASH__(PrevPosRotSetThisTickFlagComponent, 0x8CC439DDu);
ENTT_HASH__(PrimedTntFlagComponent, 0xD53E514Bu);
ENTT_HASH__(ProfanityFilterComponent, 0x06650C98u);
ENTT_HASH__(ProjectileComponent, 0x94488499u);
ENTT_HASH__(ProjectileFlagComponent, 0x6B353F83u);
ENTT_HASH__(ProjectileItemComponent, 0x0096CE0Cu);
ENTT_HASH__(PropertyComponent, 0x86E1F2B7u);
ENTT_HASH__(PufferfishVariableIndexComponent, 0xCDF5E738u);
ENTT_HASH__(PushableByBlockComponent, 0x0DC5E610u);
ENTT_HASH__(PushableByEntityComponent, 0xE0F57B82u);
ENTT_HASH__(PushActorsRequestComponent, 0x124F2E4Bu);
ENTT_HASH__(PushedByComponent, 0xBE9C0F2Cu);
ENTT_HASH__(QueuedMovementInterpolationComponent, 0x7EF19E44u);
ENTT_HASH__(RabbitVariableIndexComponent, 0x4BB270C6u);
ENTT_HASH__(RaidBossComponent, 0x4FA50C6Fu);
ENTT_HASH__(RaidTriggerComponent, 0xA49B6DF2u);
ENTT_HASH__(RailActivatorComponent, 0x3563DB4Fu);
ENTT_HASH__(RailMovementComponent, 0xABC7E2CBu);
ENTT_HASH__(RaiseArmAnimationComponent, 0x24925076u);
ENTT_HASH__(RandomComponent, 0xE4493901u);
ENTT_HASH__(RandomReferenceComponent, 0x76ADC152u);
ENTT_HASH__(RarityItemComponent, 0xB22B22FCu);
ENTT_HASH__(RawMoveInputComponent, 0x3613E513u);
ENTT_HASH__(RecalculateControlledByLocalInstanceRequestComponent, 0xF30F8CB5u);
ENTT_HASH__(RecordItemComponent, 0x7DA4641Eu);
ENTT_HASH__(RelativeShadowOffsetComponent, 0x7FD7A655u);
ENTT_HASH__(RemotePlayerComponent, 0x80C5C301u);
ENTT_HASH__(RemoveAllPassengersRequestComponent, 0x505E5269u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ActorChunkMoveFlagComponent>, 0x7CCD56F8u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ActorDiedComponent>, 0x8F9BFCAEu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ActorTickedComponent>, 0x28C3E70Cu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<AutoStepRequestFlagComponent>, 0x9B4196D1u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<BlockMovementSlowdownAppliedComponent>, 0x9C8AA8B3u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<BuoyancyFloatRequestComponent>, 0xFF90F5D0u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<DisplayObjectMessageRequestComponent>, 0x216871F4u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<EditorActorPausedComponent>, 0xBB178EB9u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<EditorActorPauseTickNeededComponent>, 0x72063099u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<EmitParticleRequestComponent>, 0xE208B08Fu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ExecuteEventOnBlockRequestComponent>, 0x04BE3D53u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<FallDamageResultComponent>, 0x80D9E6B8u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<FrictionModifierOverrideComponent>, 0xE8893392u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ItemUseSlowdownModifierComponent>, 0x36274B37u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<JumpFromGroundRequestComponent>, 0x3524CE9Du);
ENTT_HASH__(RemoveFromAllEntitiesSystem<MobIsImmobileFlagComponent>, 0x6E81B049u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<MovedOnSpawnComponent>, 0x621E141Cu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<MovementWasCorrectedComponent>, 0x914228DCu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<MoveRequestComponent>, 0x0EC8AD0Fu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<MoveTowardsClosestSpaceFlagComponent>, 0xE0F03ED3u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<PlayerInputRequestComponent>, 0x76EE7125u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<PositionPassengerRequestComponent>, 0xF686098Bu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<PostGameEventRequestComponent>, 0xB0ED86F8u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ResetTargetRequestComponent>, 0x518852BAu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<RewindCollisionShapesComponent>, 0xB07B1C4Eu);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ServerCatchupMovementTrackerComponent>, 0x385B03B7u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<SetHomePositionRequestComponent>, 0x2C8AC3B8u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<ShouldPlayMovementSoundComponent, ShouldPlayStepSoundComponent>, 0xA6FB5351u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<SnapOnRailComponent>, 0x036CC008u);
ENTT_HASH__(RemoveFromAllEntitiesSystem<TriggerJumpRequestComponent>, 0xB0BAC318u);
ENTT_HASH__(RemoveFromLeashedEntitiesRequestComponent, 0xC24F0084u);
ENTT_HASH__(RemoveInPeacefulFlagComponent, 0xE58A1108u);
ENTT_HASH__(RemovePassengersComponent, 0x358A69D7u);
ENTT_HASH__(RenderOffsetsItemComponent, 0x90B059E3u);
ENTT_HASH__(RenderPositionComponent, 0xE53C7221u);
ENTT_HASH__(RenderRotationComponent, 0xD15944E2u);
ENTT_HASH__(RepairableItemComponent, 0xD50D699Eu);
ENTT_HASH__(ReplayStateComponent, 0x9FC78512u);
ENTT_HASH__(ReplayStateLenderFlagComponent, 0x1D8200E6u);
ENTT_HASH__(ReplayStateTrackerComponent, 0xE19E1B4Cu);
ENTT_HASH__(ReplayStateValidFrameSupportComponent, 0xEFE55A9Au);
ENTT_HASH__(ResetTargetRequestComponent, 0x79EB209Du);
ENTT_HASH__(RewindCollisionShapesComponent, 0xEDFF7217u);
ENTT_HASH__(RideableComponent, 0x80AAE216u);
ENTT_HASH__(RidingHeightComponent, 0x332D837Eu);
ENTT_HASH__(RidingPrevIDComponent, 0xAE5B853Fu);
ENTT_HASH__(RiptideTridentSpinAttackComponent, 0x12DE8C2Fu);
ENTT_HASH__(RollCounterComponent, 0x17F5049Du);
ENTT_HASH__(RuntimeIDComponent, 0xFC0DBBB5u);
ENTT_HASH__(SaveSurroundingChunksComponent, 0xC6F2808Fu);
ENTT_HASH__(ScaleByAgeComponent, 0x888A93A6u);
ENTT_HASH__(ScanForDolphinFlagComponent, 0x13F1244Au);
ENTT_HASH__(ScanForDolphinTimerComponent, 0xB8B9C219u);
ENTT_HASH__(SchedulePlayerLoadingScreenComponent, 0x42F40FBAu);
ENTT_HASH__(SchedulerComponent, 0x740A9399u);
ENTT_HASH__(ScriptingInputInfoComponent, 0x62F39711u);
ENTT_HASH__(SendMotionToServerComponent, 0xBC6E18D2u);
ENTT_HASH__(SendPacketsComponent, 0x91DE0257u);
ENTT_HASH__(ServerActiveCameraComponent, 0x698462CEu);
ENTT_HASH__(ServerAnticipateClientLoadingScreenComponent, 0x7E9107C2u);
ENTT_HASH__(ServerCameraAllowedControlSchemesComponent, 0x3CE7AE43u);
ENTT_HASH__(ServerCameraDefaultControlSchemesComponent, 0x62A984B0u);
ENTT_HASH__(ServerCameraInstructionComponent, 0xF552384Eu);
ENTT_HASH__(ServerCameraStatesComponent, 0xAF2106FEu);
ENTT_HASH__(ServerCatchupMovementTrackerComponent, 0xF2AB58D6u);
ENTT_HASH__(ServerPlayerComponent, 0x122C9226u);
ENTT_HASH__(ServerPlayerCurrentMovementComponent, 0xAF78DFA4u);
ENTT_HASH__(ServerPlayerInitialLoadingComponent, 0x9D4A61A6u);
ENTT_HASH__(ServerPlayerInteractComponent, 0xCC68CD1Cu);
ENTT_HASH__(ServerPlayerInventoryTransactionComponent, 0xF824923Eu);
ENTT_HASH__(ServerPlayerMovementComponent, 0x70CA8F01u);
ENTT_HASH__(ServerPlayerMovementSyncComponent, 0x133AAFB4u);
ENTT_HASH__(ServerPlayerTeleportingFlagComponent, 0x8DAFFE3Du);
ENTT_HASH__(ServerScriptInputPacketQueueComponent, 0x83AF99E9u);
ENTT_HASH__(ServerSideForceSendAllPlayersSpatialActorNetworkDataComponent, 0x02FCE669u);
ENTT_HASH__(SetHomePositionRequestComponent, 0x2E31B8EBu);
ENTT_HASH__(SetMovingFlagRequestComponent, 0x8BCE56DFu);
ENTT_HASH__(ShareableComponent, 0xDDFFCB9Fu);
ENTT_HASH__(SheepFlagComponent, 0x1CB4423Du);
ENTT_HASH__(ShieldFlickerComponent, 0x6FB619B3u);
ENTT_HASH__(ShooterComponent, 0x1792E3C2u);
ENTT_HASH__(ShooterItemComponent, 0xF0343B0Fu);
ENTT_HASH__(ShooterItemComponentLegacyFactoryData, 0x60271DA6u);
ENTT_HASH__(ShouldAwardWhoNeedsRocketsAchievementFlagComponent, 0xC963A91Fu);
ENTT_HASH__(ShouldBeSimulatedComponent, 0x72DDE456u);
ENTT_HASH__(ShouldDespawnItemComponent, 0x469C619Au);
ENTT_HASH__(ShouldPlayMovementSoundComponent, 0xFCC428DFu);
ENTT_HASH__(ShouldPlayStepSoundComponent, 0x4E217A10u);
ENTT_HASH__(ShouldStopEmotingRequestComponent, 0xDA7B99A1u);
ENTT_HASH__(ShouldUpdateBoundingBoxRequestComponent, 0x752C8E04u);
ENTT_HASH__(ShulkerBulletFlagComponent, 0xD27838D8u);
ENTT_HASH__(ShulkerFlagComponent, 0xC1D99198u);
ENTT_HASH__(ShulkerPeekAmountComponent, 0x171621E3u);
ENTT_HASH__(ShulkerVariableIndexComponent, 0x7DF339E0u);
ENTT_HASH__(SimulatedPlayerFlagComponent, 0xA83D07F5u);
ENTT_HASH__(SitComponent, 0x3FFB2C3Au);
ENTT_HASH__(SkipAiStepComponent, 0x1137A471u);
ENTT_HASH__(SkipBodySlotUpgradeFlagComponent, 0x82E00363u);
ENTT_HASH__(SkipMobTravelComponent, 0xBFF17DEFu);
ENTT_HASH__(SkipNormalTickComponent, 0x60CA7057u);
ENTT_HASH__(SkipPlayerTickSystemFlagComponent, 0xA2E29390u);
ENTT_HASH__(SkipRedFlashComponent, 0x420989B8u);
ENTT_HASH__(SkyboxIdentifierComponent, 0xE2A3E407u);
ENTT_HASH__(SleepCounterComponent, 0xD4328ADBu);
ENTT_HASH__(SlimeFlagComponent, 0xD7A44890u);
ENTT_HASH__(SlimeWasOnGroundPreNormalTickComponent, 0xDFF74110u);
ENTT_HASH__(SlotDropChancesComponent, 0x85FB4DF0u);
ENTT_HASH__(SnapOnRailComponent, 0xB834FEDFu);
ENTT_HASH__(SneakingComponent, 0x8918332Cu);
ENTT_HASH__(SneezeComponent, 0x28D4DE72u);
ENTT_HASH__(SoulSpeedEnchantFlagComponent, 0x6DA32DD7u);
ENTT_HASH__(SoundEventPlayerComponent, 0x09C4093Cu);
ENTT_HASH__(SoundEventRequestQueueComponent, 0xBAF75BF7u);
ENTT_HASH__(SpawnActorComponent, 0x42B89BA4u);
ENTT_HASH__(SpawnEggInteractComponent, 0x5497240Au);
ENTT_HASH__(SpawnExperienceOrbRequestQueueComponent, 0x779E338Cu);
ENTT_HASH__(SpawnOnDeathComponent, 0xA8C01C54u);
ENTT_HASH__(SpinAttackResultsComponent, 0x27D9E4B4u);
ENTT_HASH__(SquidFlagComponent, 0xDC9A12DEu);
ENTT_HASH__(SquidJumpRequestComponent, 0x830513D5u);
ENTT_HASH__(SquidVariableIndexComponent, 0x7FEAB292u);
ENTT_HASH__(StackedByDataItemComponent, 0xD4DCA587u);
ENTT_HASH__(StandAnimationComponent, 0x3FDD6D36u);
ENTT_HASH__(StandOnOtherBlockFlagComponent, 0x48294962u);
ENTT_HASH__(StandOnSpeedAlteringBlockFlagComponent, 0x7069C117u);
ENTT_HASH__(StateVectorComponent, 0x1B5D5238u);
ENTT_HASH__(StepSoundFrequencyComponent, 0xB0051187u);
ENTT_HASH__(StopMovementRequestComponent, 0x113FC464u);
ENTT_HASH__(StopRidingRequestComponent, 0xFE184424u);
ENTT_HASH__(StorageItemComponent, 0x30D94100u);
ENTT_HASH__(StorageWeightLimitItemComponent, 0x8244A9ADu);
ENTT_HASH__(StorageWeightModifierItemComponent, 0x7AEA6713u);
ENTT_HASH__(SubBBsComponent, 0x0B0822D1u);
ENTT_HASH__(SuspectTrackingComponent, 0x86DE391Eu);
ENTT_HASH__(SwellComponent, 0xC523F8FDu);
ENTT_HASH__(SwiftSneakEnchantComponent, 0xCDD62A2Cu);
ENTT_HASH__(SwimAmountComponent, 0xCF19787Cu);
ENTT_HASH__(SwimSpeedMultiplierComponent, 0x60FC5A9Au);
ENTT_HASH__(SwingDurationItemComponent, 0x857D9AA1u);
ENTT_HASH__(SwingSoundsItemComponent, 0x16241571u);
ENTT_HASH__(SwitchingVehiclesFlagComponent, 0x00FEA82Bu);
ENTT_HASH__(SyncedClientOptionsComponent, 0x5C46A711u);
ENTT_HASH__(SynchedActorDataComponent, 0xE642016Bu);
ENTT_HASH__(TagsComponent<IDType<LevelTagSetIDType>>, 0x89ABB47Bu);
ENTT_HASH__(TagsItemComponent, 0xD58DA36Au);
ENTT_HASH__(TameableComponent, 0x6A786FC3u);
ENTT_HASH__(TargetNearbyComponent, 0xCDB1EF0Eu);
ENTT_HASH__(TeleportComponent, 0x2173960Du);
ENTT_HASH__(TeleportToRequestComponent, 0x2A473F9Bu);
ENTT_HASH__(teRequestComponent, PostSplashGameEventRequestComponent, WaterSplashEffectRequestComponent > , 0x27FCC346u);
ENTT_HASH__(ThrowableItemComponent, 0x1AE591FBu);
ENTT_HASH__(ThrowableItemComponentLegacyFactoryData, 0x0F5AE11Au);
ENTT_HASH__(ThrownTridentFlagComponent, 0x9DB0AE12u);
ENTT_HASH__(TickDeathNeededComponent, 0x43FA6822u);
ENTT_HASH__(TickWorldComponent, 0x88F8EB8Fu);
ENTT_HASH__(TimerComponent, 0xE7368D41u);
ENTT_HASH__(TintColorComponent, 0x0098062Eu);
ENTT_HASH__(TradeResupplyComponent, 0xE00F2E1Au);
ENTT_HASH__(TrailComponent, 0xE098E11Eu);
ENTT_HASH__(TransformationComponent, 0xF65FE25Fu);
ENTT_HASH__(TransientComponent, 0xDE678118u);
ENTT_HASH__(TriggerJumpRequestComponent, 0xF37EFB0Fu);
ENTT_HASH__(TripodCameraActivateComponent, 0xE3470506u);
ENTT_HASH__(TripodCameraActivatedComponent, 0x8C22B8D8u);
ENTT_HASH__(TripodCameraVariableIndexComponent, 0xEE223851u);
ENTT_HASH__(TropicalFishFlagComponent, 0x3341820Cu);
ENTT_HASH__(TropicalFishVariableIndexComponent, 0x487D5694u);
ENTT_HASH__(TrustComponent, 0x8D862070u);
ENTT_HASH__(TrustingComponent, 0x58D5CB06u);
ENTT_HASH__(tyMovedFlagComponent, SkipAiStepComponent, SkipNormalTickComponent, SkipMobTravelComponent > , 0x41FD7A64u);
ENTT_HASH__(UnderWaterMountBreathingComponent, 0x14151C9Cu);
ENTT_HASH__(UnleashRequestComponent, 0x39E0A8CFu);
ENTT_HASH__(UnloadedChunkTimerComponent, 0x7E791BDCu);
ENTT_HASH__(UnlockedRecipesClientComponent, 0xEB4CEE0Bu);
ENTT_HASH__(UnlockedRecipesServerComponent, 0x174BE3D7u);
ENTT_HASH__(UpdateAndRenderThrottleComponent, 0x20B90080u);
ENTT_HASH__(UpdateWaterStateRequestComponent, 0x4238F6E8u);
ENTT_HASH__(UseAnimationItemComponent, 0x869EE734u);
ENTT_HASH__(UseModifiersItemComponent, 0x7D773434u);
ENTT_HASH__(UseModifiersItemComponentLegacyFactoryData, 0x6DBBF99Fu);
ENTT_HASH__(UserEntityIdentifierComponent, 0x0B845379u);
ENTT_HASH__(UsesDefaultStepSoundComponent, 0x9274E0CEu);
ENTT_HASH__(UsesLegacyAmbientSoundsComponent, 0x0C1E4A6Du);
ENTT_HASH__(UsesMobTravelComponent, 0x5B28C284u);
ENTT_HASH__(VanillaCameraAPIComponent, 0xBD843710u);
ENTT_HASH__(VanillaClientGameplayComponent, 0xA406686Eu);
ENTT_HASH__(VanillaOffsetComponent, 0xACD368EEu);
ENTT_HASH__(VariableMaxAutoStepComponent, 0x630D515Fu);
ENTT_HASH__(VehicleComponent, 0x161F61EAu);
ENTT_HASH__(VehicleInputIntentComponent, 0x52CBB06Eu);
ENTT_HASH__(VehicleRenderingRidingOffsetComponent, 0xE21DBC36u);
ENTT_HASH__(VerticalCollisionFlagComponent, 0xC6A02A9Au);
ENTT_HASH__(VerticalMovementActionComponent, 0x739893AFu);
ENTT_HASH__(VexFlagComponent, 0x52857D3Du);
ENTT_HASH__(VibrationDamperComponent, 0x949E93EBu);
ENTT_HASH__(VibrationDataComponent, 0x0BB05AF4u);
ENTT_HASH__(VibrationListenerComponent, 0x2DEB1388u);
ENTT_HASH__(VillageManagerComponent, 0xD4726491u);
ENTT_HASH__(VillagerV2FlagComponent, 0xC66E4A94u);
ENTT_HASH__(VillagerVariableIndexComponent, 0x8AFF04D0u);
ENTT_HASH__(VisibilityCacheComponent, 0xDE833580u);
ENTT_HASH__(VolumeBoundsComponent, 0xE02B30A9u);
ENTT_HASH__(VolumeCreationDataComponent, 0xA6C29C9Du);
ENTT_HASH__(WalkDistComponent, 0xCF59BFCFu);
ENTT_HASH__(WardenSpawnTrackerComponent, 0xCBDC1C08u);
ENTT_HASH__(WasControlledByLocalInstanceComponent, 0x8AB4706Eu);
ENTT_HASH__(WasHandledBySculkCatalystFlagComponent, 0xF735AB3Du);
ENTT_HASH__(WasInLavaFlagComponent, 0x832A2768u);
ENTT_HASH__(WasInWaterFlagComponent, 0x78E89F39u);
ENTT_HASH__(WasOnGroundFlagComponent, 0x85C63FFDu);
ENTT_HASH__(WasStopRidingServerInitiatedFlagComponent, 0xD133DFE2u);
ENTT_HASH__(WaterAnimalFlagComponent, 0x10048581u);
ENTT_HASH__(WaterIdentifierComponent, 0x6A087B1Eu);
ENTT_HASH__(WaterMovementComponent, 0xF465B380u);
ENTT_HASH__(WaterSplashEffectRequestComponent, 0x4A592ED2u);
ENTT_HASH__(WaterTravelFlagComponent, 0x2802839Du);
ENTT_HASH__(WaterWalkSpeedEnchantComponent, 0xC00616A0u);
ENTT_HASH__(WeaponItemComponent, 0x900F5379u);
ENTT_HASH__(WearableItemComponent, 0x86AC8284u);
ENTT_HASH__(WearableItemComponentLegacyFactoryData, 0xB35E1A2Fu);
ENTT_HASH__(WingFlapDataComponent, 0xE81DCC8Cu);
ENTT_HASH__(WingFlapVerticalDragComponent, 0x72563330u);
ENTT_HASH__(WitchFlagComponent, 0xB0104271u);
ENTT_HASH__(WitchVariableIndexComponent, 0x88CEE5FBu);
ENTT_HASH__(WitherBossFlagComponent, 0xEBD2BBD0u);
ENTT_HASH__(WitherBossPreAIStepResultComponent, 0x2F899244u);
ENTT_HASH__(WitherSkullFlagComponent, 0xDABC5564u);
ENTT_HASH__(WolfFlagComponent, 0x1D2977CEu);*/
// by parser v3 (DONT TRUST)
// _26_20::BlockDefinition::NoCollisionSnowLogConstraint, cereal::ComponentStorageConstraint>  (0xE82D166Bu)
// _Simple_types<SharedTypes::v1_21_80::ReplaceBiomesBiomeJsonComponent::BiomeReplacement>>>  (0x8136D13Au)
// _string<char>, SharedTypes::v1_26_20::BlockDefinition::GeometryComponent::DetailedGeometry>  (0xB8E8074Bu)
// _Vector_val<std::_Simple_types<SharedTypes::v1_20_50::ShooterItemComponent::Ammunition>>>  (0xB98D40FCu)
// AgentComponents::ActionDetails  (0xFA3B7EEAu)
// AgentComponents::ActionQueue  (0xDC874D63u)
// AgentComponents::Agent  (0x4E7AB4B3u)
// AgentComponents::Animating  (0x959FA636u)
// AgentComponents::AnimationArmSwing  (0x94CE7C98u)
// AgentComponents::AnimationComplete  (0x5A7BB1CBu)
// AgentComponents::AnimationShrug  (0x409D584Bu)
// AgentComponents::CommandCooldown  (0x6C173462u)
// AgentComponents::Destroy  (0xC85ADDB8u)
// AgentComponents::DetectObstacle  (0xA2E84490u)
// AgentComponents::DetectRedstone  (0x0ADA4845u)
// AgentComponents::Executing  (0x475CFA2Eu)
// AgentComponents::Initializing  (0x0AB291BFu)
// AgentComponents::Inspect  (0xB44F805Au)
// AgentComponents::Interact  (0x66F5F248u)
// AgentComponents::LegacyCommand  (0xD86223B2u)
// AgentComponents::Move  (0x467C51F3u)
// akTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerBreakAfterEvent>  (0xC59A7A8Au)
// allocator<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>>  (0xEED489CCu)
// allocator<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>>  (0x53DD4A9Au)
// ar>, SharedTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent::MaterialInstance>>  (0x59FAD5C1u)
// aredTypes::v1_26_20::BlockDefinition::DestructibleByExplosionComponent::DetailedResistance>  (0x0B07F967u)
// ariant<bool, SharedTypes::v1_26_20::BlockDefinition::FlammableComponent::DetailedFlammable>  (0x8E1BBE66u)
// ated<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentEntity>>  (0xB89597D3u)
// ated<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentSpline>>  (0x038FDAB9u)
// B, SharedTypes::v1_21_100::GrassAppearanceClientBiomeJsonComponent::GrassColorMapContainer>  (0xE1981B08u)
// B, SharedTypes::v1_21_40::GrassAppearanceClientBiomeJsonComponent::GrassColorMapContainer>>  (0x47DE3191u)
// BlockCollisionBoxComponentDescriptor::BlockCollisionBoxProxy  (0x471174E7u)
// BlockCollisionsSystem::BlockCollisionResolutionVectorComponent  (0x2462ED53u)
// BlockComponentGroupDescription::Components  (0x37461812u)
// BlockDefinition::NoContainerIfCraftingTableConstraint, cereal::ComponentStorageConstraint>  (0x8BBAAAECu)
// BlockQueuedTickingComponentDescriptor::Proxy  (0x7EECE4ECu)
// BlockSelectionBoxComponentDescriptor::Proxy  (0xF7038C4Fu)
// BlockTickConfigurationComponentDescriptor::Proxy  (0xF98D2061u)
// cated<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGizmo>>  (0xD5E93C65u)
// cator<SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedBiomeName>  (0x664E2097u)
// cator<SharedTypes::v1_26_20::BlockDefinition::PlacementFilterComponent::PlacementCondition>  (0x710465DFu)
// cereal::ComponentStorage  (0x18000479u)
// cereal::ComponentStorageConstraint  (0xE5F27276u)
// cereal::internal::DeprecatedComponentTagT  (0x1A53B9E4u)
// ClientRewind::ApplyReplayStateTrackerRequestComponent  (0xBC781A07u)
// Color255RGB, SharedTypes::v1_26_20::BlockDefinition::MapColorComponent::DetailedMapColor>  (0x7E54A85Bu)
// ColorExpr, SharedTypes::v1_20_80::ParticleAppearanceTintingComponentHelper::ColorProxy>  (0xE9ACBD05u)
// Component::GrassTint, SharedTypes::v1_21_100::CustomMapTintBiomeJsonComponent::GrassNoise>>  (0xB5F8C959u)
// cripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentVolumeOutline>  (0xE267C8F5u)
// cripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponentContainer>  (0x160CC756u)
// cripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentUseEvent>  (0xE6750536u)
// cripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementAmphibiousComponent>  (0x9CFB1F95u)
// cripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptUnderwaterMovementComponent>  (0x482367D9u)
// cripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cone>  (0xDE4848A6u)
// cripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Disc>  (0x07487ADCu)
// cripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Line>  (0x51B13C7Du)
// cripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPotionContainerComponentV010>  (0x2822A584u)
// cripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentHitEntityEvent>  (0x0B70185Eu)
// cripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentMineBlockEvent>  (0xBD2C5C6Cu)
// cripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptPlayerInventoryComponentContainer>  (0x78EE96AAu)
// cripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentUseOnEvent>  (0xF3F8B48Eu)
// ctor_val<std::_Simple_types<BlockCollisionBoxComponentDescriptor::BlockCollisionBoxProxy>>>  (0xF4C85507u)
// d::_Simple_types<SharedTypes::v1_26_0::ReplaceBiomesBiomeJsonComponent::BiomeReplacement>>>  (0x78B91A8Du)
// d::optional<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>>  (0x058D3D2Fu)
// d<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentClipboard>>  (0x9CC5A220u)
// DiggerItemComponent::BlockInfo  (0xD22A4200u)
// ditor::Network::WidgetPrimComponentCone, Editor::Network::WidgetPrimComponentWireframeMesh>  (0xA26E8E36u)
// dTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedTemperatureCategory>>  (0x1755CDEAu)
// dTypes::v1_20_60::SurfaceMaterialAdjustmentsBiomeJsonComponent::SurfaceMaterialAdjustment>>  (0xE13DC7F1u)
// e_list<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>>  (0xEFD51FEDu)
// e_list<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>>  (0x1DB5F260u)
// eakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_AxialSphere>  (0xA4603298u)
// eakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentBlockBreakAfterEvent>  (0xF6B2FFD3u)
// eakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentRandomTickAfterEvent>  (0x3A6DF841u)
// ecated<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>>  (0xB0FADDF1u)
// ecated<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGrid>>  (0x0C243EB8u)
// ecated<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentText>>  (0xB9C8E8B3u)
// ectHandle<Editor::ScriptModule::ScriptWidgetComponentBoundingBoxStateChangeEventParameters>  (0xAD4D6A71u)
// ector<SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedBiomeName>  (0x8BA78CA7u)
// ector<SharedTypes::v1_26_20::BlockDefinition::PlacementFilterComponent::PlacementCondition>  (0xE4A5496Fu)
// Editor::Network::WidgetAddBoundingBoxComponentPayload  (0xAD08A1EDu)
// Editor::Network::WidgetAddClipboardComponentPayload  (0x0FB6119Eu)
// Editor::Network::WidgetAddEntityComponentPayload  (0x497E9ADDu)
// Editor::Network::WidgetAddGizmoComponentPayload  (0xD3F8EA22u)
// Editor::Network::WidgetAddGridComponentPayload  (0xCF9AE74Eu)
// Editor::Network::WidgetAddGuideSensorComponentPayload  (0x6DEDFA82u)
// Editor::Network::WidgetAddRenderPlaneComponentPayload  (0x5DFC799Au)
// Editor::Network::WidgetAddRenderPrimComponentPayload  (0x36BAF652u)
// Editor::Network::WidgetAddSplineComponentPayload  (0xBA186D67u)
// Editor::Network::WidgetAddTextComponentPayload  (0x0479E129u)
// Editor::Network::WidgetAddVolumeOutlineComponentPayload  (0x37AC3168u)
// Editor::Network::WidgetChangeRenderPrimComponentPayload  (0x6083A7BDu)
// Editor::Network::WidgetComponentBasePayload  (0x23C46B9Au)
// Editor::Network::WidgetComponentStateChangePayload  (0x245AC43Cu)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateBase  (0xA8CEC14Du)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateBoundingBox  (0x46A01761u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateClipboard  (0xF0A44466u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateEntity  (0x27D56DD3u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateGizmo  (0x46403DC6u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateGrid  (0x1DF59BA8u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateNULL  (0x73C368A5u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateRenderPlane  (0x065D3D1Au)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateSpline  (0x63000F09u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateText  (0x23AE0A4Fu)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateVolumeOutline  (0x1AC0A8B4u)
// Editor::Network::WidgetComponentStateChangePayload::ComponentStateVolumeOutlineVolumeUpdate  (0x6B0BA9EFu)
// Editor::Network::WidgetComponentStateChangePayload::WidgetComponentStateVariantType  (0x4262E35Du)
// Editor::Network::WidgetDeleteComponentPayload  (0x6F9DF9A6u)
// Editor::Network::WidgetPrimComponentAxialSphere  (0x560A005Fu)
// Editor::Network::WidgetPrimComponentBox  (0x02CF1C72u)
// Editor::Network::WidgetPrimComponentCone  (0x80D233AAu)
// Editor::Network::WidgetPrimComponentCuboid  (0xBC29E523u)
// Editor::Network::WidgetPrimComponentCylinder  (0x38F49E2Fu)
// Editor::Network::WidgetPrimComponentDisc  (0xE36AF24Cu)
// Editor::Network::WidgetPrimComponentEllipsoid  (0xBA0D869Eu)
// Editor::Network::WidgetPrimComponentLine  (0xD7341C67u)
// Editor::Network::WidgetPrimComponentPyramid  (0xF7E31327u)
// Editor::Network::WidgetPrimComponentWireframeMesh  (0x8998423Cu)
// Editor::ScriptModule::ScriptWidgetComponentBase  (0x486C8232u)
// Editor::ScriptModule::ScriptWidgetComponentBaseOptions  (0xF7BABB9Cu)
// Editor::ScriptModule::ScriptWidgetComponentBoundingBox  (0xB1CB3CA4u)
// Editor::ScriptModule::ScriptWidgetComponentBoundingBoxLimit  (0x60081FF7u)
// Editor::ScriptModule::ScriptWidgetComponentBoundingBoxOptions  (0xED6A463Au)
// Editor::ScriptModule::ScriptWidgetComponentBoundingBoxStateChangeEventParameters  (0x237D062Bu)
// Editor::ScriptModule::ScriptWidgetComponentClipboard  (0x042740D7u)
// Editor::ScriptModule::ScriptWidgetComponentClipboardOptions  (0xD98026C3u)
// Editor::ScriptModule::ScriptWidgetComponentEntity  (0x13644E58u)
// Editor::ScriptModule::ScriptWidgetComponentEntityOptions  (0xE1164586u)
// Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent  (0x395780A5u)
// Editor::ScriptModule::ScriptWidgetComponentGizmo  (0x0CCB17B7u)
// Editor::ScriptModule::ScriptWidgetComponentGizmoOptions  (0xF1C0DFE3u)
// Editor::ScriptModule::ScriptWidgetComponentGizmoStateChangeEventParameters  (0x57F0EFDCu)
// Editor::ScriptModule::ScriptWidgetComponentGrid  (0x00562F03u)
// Editor::ScriptModule::ScriptWidgetComponentGridOptions  (0x21442077u)
// Editor::ScriptModule::ScriptWidgetComponentGuideSensor  (0xC9126083u)
// Editor::ScriptModule::ScriptWidgetComponentGuideSensorOptions  (0x0312A8F7u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPlane  (0x130AD8BBu)
// Editor::ScriptModule::ScriptWidgetComponentRenderPlaneOptions  (0x57D3047Fu)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrim  (0x8BC08C8Fu)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimOptions  (0xB38B0E0Bu)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_AxialSphere  (0x22307800u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Box  (0x04BB08F1u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cone  (0x6C76ED4Bu)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cuboid  (0x76A4AB22u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cylinder  (0x45711736u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Disc  (0x98981AADu)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Ellipsoid  (0x00EEB845u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Line  (0x3ABF2562u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Pyramid  (0x2B332D94u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_WireframeMesh  (0x2CE81E47u)
// Editor::ScriptModule::ScriptWidgetComponentRenderPrimTypeBase  (0xEA61379Au)
// Editor::ScriptModule::ScriptWidgetComponentSpline  (0xA73BB24Eu)
// Editor::ScriptModule::ScriptWidgetComponentSplineOptions  (0x70CDE960u)
// Editor::ScriptModule::ScriptWidgetComponentText  (0x0CF20BB8u)
// Editor::ScriptModule::ScriptWidgetComponentTextOptions  (0xF4B9E526u)
// Editor::ScriptModule::ScriptWidgetComponentVolumeOutline  (0xC8E338C9u)
// Editor::ScriptModule::ScriptWidgetComponentVolumeOutlineOptions  (0xD1C754B1u)
// Editor::Widgets::WidgetComponentType  (0xC3A20FCCu)
// edObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentBlockStateChangeAfterEvent>  (0x55D6FF1Du)
// edObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentBeforeDurabilityDamageEvent>  (0x6646C5ECu)
// edTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedTemperatureCategory>  (0x2E9546B9u)
// edTypes::v1_20_60::SurfaceMaterialAdjustmentsBiomeJsonComponent::SurfaceMaterialAdjustment>  (0xAB652914u)
// enderPlaneGridResolution, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x2483A27Fu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentBoundingBoxLimit>  (0x9B2C56ABu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentBoundingBoxOptions>  (0x41EFE08Cu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentClipboardOptions>  (0x3FD53F87u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentEntityOptions>  (0x0864EEE8u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentGizmoOptions>  (0x89D0BE27u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentGridOptions>  (0xC8EEC62Bu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentGuideSensorOptions>  (0x0CACB8ABu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPlaneOptions>  (0xF3BBAF93u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimOptions>  (0x006E0BAFu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_AxialSphere>  (0x98A13ADAu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Box>  (0xE8354D1Du)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cone>  (0xD11CAB6Fu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cuboid>  (0x25641E54u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cylinder>  (0xC0E2BAD8u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Disc>  (0x508465A9u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Ellipsoid>  (0x4BEFAFE1u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Line>  (0xA00BBD14u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Pyramid>  (0x0FDD3DDEu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_WireframeMesh>  (0x0DF9B8BBu)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentSplineOptions>  (0xB2B34F3Au)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentTextOptions>  (0xCCE95808u)
// entt::type_list<Editor::ScriptModule::ScriptWidgetComponentVolumeOutlineOptions>  (0x3695495Du)
// ets::WidgetComponentType, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x1BF924AEu)
// eVolumeListBlockVolume>>, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0xDA72551Du)
// g::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentTickAfterEvent>  (0x040D26ADu)
// g::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_AxialSphere>  (0x5CA08D6Eu)
// g::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentBlockBreakAfterEvent>  (0x9EB16B6Du)
// g::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentRandomTickAfterEvent>  (0x909A19FBu)
// g::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Pyramid>  (0x28F5CC4Au)
// g::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentStepOnAfterEvent>  (0x88F8EFA4u)
// g::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponentContainerV010>  (0xBA32B26Eu)
// GB, SharedTypes::v1_21_40::GrassAppearanceClientBiomeJsonComponent::GrassColorMapContainer>  (0x7FE24B32u)
// gTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_WireframeMesh>  (0xAD01E2F3u)
// gTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentEntityFallOnAfterEvent>  (0xDA9D96B4u)
// gTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerPlaceBeforeEvent>  (0x49E3A908u)
// har>, SharedTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent::MaterialInstance>  (0xE86AA2B7u)
// haredTypes::v1_21_40::FoliageAppearanceClientBiomeJsonComponent::FoliageColorMapContainer>>  (0x97385A92u)
// haredTypes::v1_21_70::FoliageAppearanceClientBiomeJsonComponent::FoliageColorMapContainer>>  (0x7B5330E3u)
// haredTypes::v1_26_20::BlockDefinition::DestructibleByExplosionComponent::DetailedResistance  (0x89E2CD51u)
// IItemComponentLegacyFactoryData::Components  (0xE375C981u)
// ing::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Box>  (0x41B5BACFu)
// ing::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimTypeBase>  (0x7DAB4EB2u)
// ing::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockWaterContainerComponentV010>  (0x2DE121EDu)
// ing::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Ellipsoid>  (0x6C1A4FD8u)
// ing::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentTickAfterEvent>  (0xE3AD008Bu)
// ional<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>>>  (0x2324059Bu)
// ipting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentUseOnEvent>  (0x5177E808u)
// ipting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cuboid>  (0x531E753Eu)
// ipting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentActorAfterEvent>  (0x4A5156A6u)
// ipting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemBlockDynamicPropertiesComponent>  (0xC2B3DD53u)
// ipting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentCompleteUseEvent>  (0x43E6904Du)
// ipting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockDynamicPropertiesComponent>  (0xE4AA18E4u)
// ipting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockLavaContainerComponentV010>  (0x7FE24750u)
// ipting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockSnowContainerComponentV010>  (0xFCCF6603u)
// ipting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentConsumeEvent>  (0x1D1DA045u)
// iptModule::ScriptWidget>, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0xE13493C7u)
// iptModuleMinecraft::ScriptActorComponent>>, ScriptModuleMinecraft::ScriptInvalidActorError>  (0xA2C3E2F1u)
// iptModuleMinecraft::ScriptFacing>, ScriptModuleMinecraft::ScriptBlockInvalidComponentError>  (0xD096A060u)
// ItemRegistryPacketAnon::ServerItemComponentsConstraint  (0xAFDBBA98u)
// kTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_WireframeMesh>  (0xF2BDE1FFu)
// kTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentEntityFallOnAfterEvent>  (0xCDC4E6B0u)
// kTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerPlaceBeforeEvent>  (0x564D1744u)
// le_types<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>>>>  (0xA8407FD6u)
// MinecraftCamera::ActiveCameraComponent  (0x113040A1u)
// MinecraftCamera::AllowInsideBlockRenderComponent  (0x9BB661A0u)
// MinecraftCamera::CameraActivationRequestComponent  (0x6F10D144u)
// MinecraftCamera::CameraAdjustedPositionComponent  (0x86DF70DCu)
// MinecraftCamera::CameraAnimationDataComponent  (0x1552B1A5u)
// MinecraftCamera::CameraAnimationStorageComponent  (0xBF1D79DEu)
// MinecraftCamera::CameraAttachComponent  (0xA6233058u)
// MinecraftCamera::CameraAttachToEntityComponent  (0x6D9880F2u)
// MinecraftCamera::CameraAvoidanceComponent  (0x4D1D154Du)
// MinecraftCamera::CameraBlendStateComponent  (0x7935F153u)
// MinecraftCamera::CameraCalculateAnimationComponent  (0x7FAE6849u)
// MinecraftCamera::CameraComponent  (0x4F6047C7u)
// MinecraftCamera::CameraCustomFovComponent  (0x55495881u)
// MinecraftCamera::CameraCustomFovEaseComponent  (0xBC7BB827u)
// MinecraftCamera::CameraDirectLookComponent  (0xCEB578F1u)
// MinecraftCamera::CameraEntityStateComponent  (0x028F4DB3u)
// MinecraftCamera::CameraFadeEffectComponent  (0x2636F71Eu)
// MinecraftCamera::CameraFirstPersonClimbingComponent  (0x4DE098EBu)
// MinecraftCamera::CameraFirstPersonComponent  (0xED52B1C6u)
// MinecraftCamera::CameraFlyMoveComponent  (0x1EB64CAFu)
// MinecraftCamera::CameraGlobalInstructionComponent  (0xCB9E5E68u)
// MinecraftCamera::CameraGlobalSplineComponent  (0x78A551DDu)
// MinecraftCamera::CameraIgnoreInstructionValuesComponent  (0x654F22DBu)
// MinecraftCamera::CameraIgnoreStartingValuesComponent  (0x27457BA3u)
// MinecraftCamera::CameraInstructionComponent  (0x0A91C987u)
// MinecraftCamera::CameraInstructionsComponent  (0x0378044Cu)
// MinecraftCamera::CameraLiquidOffsetComponent  (0x94F91476u)
// MinecraftCamera::CameraLocalSpaceRotationComponent  (0xF5B4EB5Cu)
// MinecraftCamera::CameraLookAtComponent  (0xE33F5E3Du)
// MinecraftCamera::CameraLookAtPositionComponent  (0x17045224u)
// MinecraftCamera::CameraOffsetComponent  (0xAD2CB566u)
// MinecraftCamera::CameraOrbitComponent  (0x2F0FC33Fu)
// MinecraftCamera::CameraPerspectiveOptionComponent  (0xD5B28BF2u)
// MinecraftCamera::CameraPresetComponent  (0xFD83AA62u)
// MinecraftCamera::CameraRenderFirstPersonObjectsComponent  (0xE15A7944u)
// MinecraftCamera::CameraRenderPlayerModelComponent  (0x838D12E1u)
// MinecraftCamera::CameraSetUpAnimationComponent  (0xAA570358u)
// MinecraftCamera::CameraShakeSupportComponent  (0x1605AC58u)
// MinecraftCamera::CameraStartingValuesComponent  (0xA31E79D9u)
// MinecraftCamera::CameraTargetComponent  (0x98E6B7BCu)
// MinecraftCamera::CameraTargetSettingsComponent  (0x95CB5E8Bu)
// MinecraftCamera::CameraThirdPersonBoomComponent  (0xEF14FB9Au)
// MinecraftCamera::CameraThirdPersonComponent  (0xAB29C993u)
// MinecraftCamera::CameraThirdPersonFixedBoomComponent  (0x9442AD10u)
// MinecraftCamera::CameraTimeComponent  (0x88731FECu)
// MinecraftCamera::CameraTimeOverrideComponent  (0x696E389Cu)
// MinecraftCamera::CameraUsageComponent  (0xEE050B4Au)
// MinecraftCamera::CameraWorldSpaceRotationComponent  (0x213C67CFu)
// MinecraftCamera::CurrentInputCameraComponent  (0xF6C60B46u)
// MinecraftCamera::DeathCameraComponent  (0x1641604Bu)
// MinecraftCamera::DebugCameraComponent  (0x20BC5340u)
// MinecraftCamera::DefaultInputCameraComponent  (0x8BCE84BEu)
// MinecraftCamera::ExtendPlayerRenderingComponent  (0x7C6FF885u)
// MinecraftCamera::FixedBoomOrientationComponent  (0x48FC16FDu)
// MinecraftCamera::GameCameraComponent  (0x9EC7D9E5u)
// MinecraftCamera::GameplayAffectsFovComponent  (0xCE013BB9u)
// MinecraftCamera::OverrideCameraComponent  (0xDDCBBC57u)
// MinecraftCamera::PlayerAudioListenerComponent  (0xE66C48F7u)
// MinecraftCamera::PlayerStateAffectsRenderingComponent  (0x21A688A4u)
// MinecraftCamera::RedirectCameraInputComponent  (0xA8F0A7EBu)
// MinecraftCamera::RenderCameraComponent  (0x119E772Bu)
// MinecraftCamera::SeatCameraRelaxDistanceSmoothingOverrideComponent  (0xB8DFEB0Bu)
// MinecraftCamera::SeatThirdPersonCameraRadiusOverrideComponent  (0xA8F5F552u)
// MinecraftCamera::SpecialCameraModeComponent  (0x35B01C21u)
// MinecraftCamera::StationaryCameraComponent  (0xA563B3A1u)
// MinecraftCamera::TargetCameraOrientationComponent  (0x48E639F0u)
// MinecraftCamera::TargetCameraOutOfRangeComponent  (0xC296C0CEu)
// MinecraftCamera::TargetCameraRotationLimitComponent  (0x90DC8AC5u)
// MinecraftCamera::TargetCameraRotationSpeedComponent  (0x950473C5u)
// MinecraftCamera::TargetCameraSetInitialOrientationComponent  (0xDFE20EA4u)
// ModuleMinecraft::ScriptBlockCustomComponentReloadNewComponentError, Scripting::EngineError>  (0xD543A7EBu)
// MovementDataExtractionUtility::ImmutableMovementComponentsSnapshot  (0x47BF7360u)
// MovementDataExtractionUtility::MovementSnapshotComponent  (0x9DFB86B5u)
// nComponent::GrassTint, SharedTypes::v1_21_100::CustomMapTintBiomeJsonComponent::GrassNoise>  (0xDAEE1F09u)
// nderPrimType_Cone, Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_WireframeMesh>  (0x2326604Cu)
// ng::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cone>  (0xC2C511F6u)
// ng::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Disc>  (0x5168158Cu)
// ng::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Line>  (0xE568E50Du)
// ng::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPotionContainerComponentV010>  (0xBB1688D4u)
// ng::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentHitEntityEvent>  (0xD957C12Eu)
// ng::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentMineBlockEvent>  (0xC2571C7Cu)
// ng::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptPlayerInventoryComponentContainer>  (0xB288015Au)
// ng::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentRedstoneUpdateEvent>  (0x7226D068u)
// ng::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPrecipitationInteractionsComponent>  (0x57501030u)
// ng::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cuboid>  (0xA15093ECu)
// ng::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentActorAfterEvent>  (0x2E079C74u)
// ng::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemBlockDynamicPropertiesComponent>  (0x81B17DF1u)
// ng::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentCompleteUseEvent>  (0x0D7E1B2Bu)
// ng::WidgetGizmoScaleMode, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x9D3968C1u)
// ngTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerBreakAfterEvent>  (0x5ABE25C3u)
// NpcComponents::LeaveMenuCountdown  (0x0337764Bu)
// ntStateGrid, Editor::Network::WidgetComponentStateChangePayload::ComponentStateRenderPlane>  (0x15D7DEA1u)
// ocator<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>>  (0xBADB23B3u)
// ocator<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>>  (0xAF2518B6u)
// ongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_AxialSphere>  (0x6FDF9779u)
// ongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentBlockBreakAfterEvent>  (0x7A4F919Eu)
// ongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentRandomTickAfterEvent>  (0x0EEE38C0u)
// optional<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>>  (0x3CE1DA1Du)
// or_val<std::_Simple_types<SharedTypes::v1_21_130::AddRiderComponentDefinition::RiderData>>>  (0xD654F387u)
// orInvalidComponent, Editor::ScriptModule::ScriptWidgetErrorInvalidObject, Scripting::Error>  (0x49F0D5DAu)
// orldBoundsError, ScriptModuleMinecraft::ScriptBlockInvalidComponentError, Scripting::Error>  (0xCFDD18C2u)
// pedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGizmoStateChangeEventParameters>  (0x34FD3B16u)
// pes<SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedBiomeName>>>  (0xC08E6EBEu)
// pes<SharedTypes::v1_26_20::BlockDefinition::PlacementFilterComponent::PlacementCondition>>>  (0xDA3EB346u)
// PlayerPositionModeComponent::PositionMode  (0xCE3CD62Bu)
// ple_types<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>>>>  (0x3EFD7BB2u)
// pting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRecordPlayerComponentV010>  (0x552C4547u)
// pting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRedstoneProducerComponent>  (0xAF108ED8u)
// pting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsHiddenWhenInvisibleComponent>  (0x8BE8CEA0u)
// pting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Pyramid>  (0x68565247u)
// pting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentStepOnAfterEvent>  (0xC2010DA9u)
// pting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponentContainerV010>  (0x96F0F063u)
// pting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Box>  (0xF417CFDCu)
// pting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimTypeBase>  (0x5D6DC101u)
// pting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockWaterContainerComponentV010>  (0x1B07E5B6u)
// r<SharedTypes::v1_26_20::BlockDefinition::DestructibleByMiningComponent::ItemSpecificSpeed>  (0x71596744u)
// r<SharedTypes::v1_26_30::ApplyKnockbackRulesComponentDefinition::ApplyKnockbackRulesPreset>  (0x93A4A126u)
// r>, SharedTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent::MaterialInstance>>>  (0x2AE0E892u)
// r_val<std::_Simple_types<SharedTypes::v1_20_50::RepairableItemComponent::RepairItemEntry>>>  (0x3119EB28u)
// r_val<std::_Simple_types<SharedTypes::v1_26_50::MountTamingComponentDefinition::FeedItem>>>  (0x76614829u)
// redTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedTemperatureCategory  (0x731186EDu)
// redTypes::v1_20_60::SurfaceMaterialAdjustmentsBiomeJsonComponent::SurfaceMaterialAdjustment  (0xFDE38EB2u)
// redTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent::MaterialInstanceConstraint  (0x95EB3C03u)
// Result<Scripting::Axis, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x2AFB0B1Au)
// Result<Scripting::Plane, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x74301E0Du)
// ripting::Result<Rotation, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x7F4EDED5u)
// ripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentVolumeOutline>>  (0xC6531168u)
// ripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockFluidContainerComponent>  (0xCEA98FFAu)
// ripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentTickAfterEvent>  (0x66BE5150u)
// ripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRecordPlayerComponentV010>  (0xDC76A4D3u)
// ripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRedstoneProducerComponent>  (0x8F05FBB4u)
// ripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsHiddenWhenInvisibleComponent>  (0x3B83E834u)
// rongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentRedstoneUpdateEvent>  (0x540E0435u)
// rongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPrecipitationInteractionsComponent>  (0x7FC414C9u)
// s<SharedTypes::Legacy::ApplyKnockbackRulesComponentDefinition::ApplyKnockbackRulesPreset>>>  (0xDB6D9E0Au)
// ScriptHandleComponent<ScriptModuleMinecraft::ScriptActor>  (0x9D56DD93u)
// Scripting::internal::BaseScriptComponent  (0x68E12CDCu)
// Scripting::internal::PointerStorageComponent<Editor::API::EditorExtension>  (0xB9435CAFu)
// Scripting::internal::PointerStorageComponent<Editor::API::EditorExtensionContext>  (0x8A1F9804u)
// Scripting::internal::PointerStorageComponent<Editor::API::EditorExtensionServiceProvider>  (0x1D9DF2CFu)
// Scripting::internal::PointerStorageComponent<ScriptModuleGameTest::ScriptGameTestHelper>  (0x2C11F9F2u)
// Scripting::internal::PointerStorageComponent<ScriptModuleGameTest::ScriptGameTestSequence>  (0xDEE7D511u)
// Scripting::Result<bool, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0xC0A61F75u)
// Scripting::Result<float, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x297DC43Du)
// Scripting::Result<int, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x7447DBB0u)
// Scripting::Result<int, ScriptModuleMinecraft::ScriptBlockInvalidComponentError>  (0x635458DEu)
// Scripting::Result<Mirror, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0xFD3388A4u)
// Scripting::Result<Vec2, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x577796DDu)
// Scripting::Result<Vec3, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x60B5DB94u)
// Scripting::Result<void, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0xE57005EBu)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>  (0x10395F03u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBoundingBox>  (0xD7F387DFu)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBoundingBox>>  (0xD55EE733u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentClipboard>  (0x6F67AE56u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentEntity>  (0x6102F4BDu)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGizmo>  (0x689AF67Au)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGrid>  (0x436A415Cu)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGuideSensor>  (0x313FECCEu)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGuideSensor>>  (0x77A1FDD0u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPlane>  (0x0523E622u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPlane>>  (0x33833E14u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrim>  (0x7E660564u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrim>>  (0x549A6CAEu)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentSpline>  (0x05D1D3E7u)
// Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentText>  (0x4C0903C5u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::AttributeScriptActorComponent>  (0x4E560B67u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>  (0x8BA9FE10u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::MovementScriptActorComponent>  (0x3170BD64u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::NavigationScriptActorComponent>  (0xA0A0C73Du)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>  (0x1CAB6267u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptAddRiderComponent>  (0xCB91FDA9u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptAgeableComponent>  (0x99DDEB0Du)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockComponentRegistry>  (0x542439AAu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponent>  (0xBB4DF300u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInstrumentComponent>  (0x39F5AA5Eu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponent>  (0x9EF1474Fu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockMapColorComponent>  (0x0F2BD7C6u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockMovableComponent>  (0x482DFF31u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPistonComponent>  (0xBE3DA23Au)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRecordPlayerComponent>  (0x162726BBu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockSignComponent>  (0xD404225Eu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBookItemComponent>  (0xD8F069BEu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBreathableComponent>  (0xC4BCF176u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptCanClimbComponent>  (0x39B70FEFu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptCanFlyComponent>  (0xCB48F10Bu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptCanPowerJumpComponent>  (0x79DC08EBu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptColor2Component>  (0x040ECCFFu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptColorComponent>  (0x4766AB91u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptComponent>  (0xA82B1C04u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptCursorInventoryComponent>  (0x3A744E6Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptCustomComponentParameters>  (0xF220E5BFu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptEnderInventoryComponent>  (0x8FD5C242u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptEquippableComponent>  (0x3C52D9FCu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptExhaustionComponent>  (0xF2A7A7F0u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptFireImmuneComponent>  (0x92407839u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptFloatsInLiquidComponent>  (0xFD7F4FDCu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptFlyingSpeedComponent>  (0x37D9F3B4u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptFoodComponent>  (0x0F24817Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptFrictionModifierComponent>  (0x584EF48Fu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptGroundOffsetComponent>  (0x80909B58u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptHealableComponent>  (0xAF45CEFAu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptHealthComponent>  (0x638EED26u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptHungerComponent>  (0x45489D87u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponent>  (0x3F0FC71Eu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsBabyComponent>  (0x2F265CE4u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsChargedComponent>  (0x3331B3B2u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsChestedComponent>  (0x8C565CE6u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsDyeableComponent>  (0x6539BB04u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsIgnitedComponent>  (0x78B9BDE8u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsIllagerCaptainComponent>  (0x2BC7824Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsSaddledComponent>  (0xEF4E929Fu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsShakingComponent>  (0xAEB998C3u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsShearedComponent>  (0x3D93115Eu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsStackableComponent>  (0xDE9B3732u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsStunnedComponent>  (0x2B4B0DF5u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptIsTamedComponent>  (0x3087CDF5u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemActorComponent>  (0x965A42C6u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>  (0x7D805113u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponentRegistry>  (0x22958D92u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCompostableComponent>  (0xBF850388u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCooldownComponent>  (0x88CB7C26u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponent>  (0x936B4768u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemDurabilityComponent>  (0xFDACA634u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemDyeableComponent>  (0x533EF3ADu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemEnchantmentComponent>  (0xEF2290BEu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemInventoryComponent>  (0x1D2464F7u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemPotionComponent>  (0xB1BFA70Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptLavaMovementComponent>  (0x6C15FE8Fu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptLeashableComponent>  (0x05102597u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMarkVariantComponent>  (0xCE6A67E0u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMountTamingComponent>  (0x02F2575Du)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementBasicComponent>  (0xB521183Fu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementComponent>  (0xA8662B59u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementFlyComponent>  (0xD0E78A0Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementGenericComponent>  (0x498DD97Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementGlideComponent>  (0xD94C9A2Cu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementHoverComponent>  (0xCB512BE3u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementJumpComponent>  (0x7B7FDFC1u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementSkipComponent>  (0x1E3F1DDAu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementSwayComponent>  (0x6DBFCCD9u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationClimbComponent>  (0xD96CE191u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationFloatComponent>  (0xDACF1836u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationFlyComponent>  (0xAE0D7FB9u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationGenericComponent>  (0xB81144E1u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationHoverComponent>  (0x7D9A0456u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationWalkComponent>  (0x110501D7u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptNpcComponent>  (0x6B6CD101u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptOnFireComponent>  (0x93939B51u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptProjectileComponent>  (0xD169AF8Fu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptPushThroughComponent>  (0x00764DB3u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptRideableComponent>  (0xEA19903Au)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptRidingComponent>  (0xAB9AC2D9u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptSaturationComponent>  (0xC53E63B0u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptScaleComponent>  (0xD5641664u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptSkinIdComponent>  (0xAE4444E0u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptStrengthComponent>  (0xD0A8E9CDu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptTameableComponent>  (0x073FB92Du)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptTypeFamilyComponent>  (0xCF501474u)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptVariantComponent>  (0xC88DF03Bu)
// Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptWantsJockeyComponent>  (0xF83CA90Au)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>  (0xBA4C3AE8u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBoundingBox>  (0xCDDE217Au)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentClipboard>  (0x7276A107u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentEntity>  (0xF7E5ECAEu)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGizmo>  (0x40AF2FA7u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGrid>  (0x318B4073u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGuideSensor>  (0xE12A02B3u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPlane>  (0x8142864Bu)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrim>  (0x8E64B017u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Box>  (0x6B9E6191u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimTypeBase>  (0xAF4D4838u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentSpline>  (0xE0039E94u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentText>  (0xC48639B6u)
// Scripting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentVolumeOutline>  (0xEA725D39u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::AttributeScriptActorComponent>  (0x5FD28666u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>  (0x2F02CEDFu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::MovementScriptActorComponent>  (0xAC965F1Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::NavigationScriptActorComponent>  (0xAAA25AFAu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>  (0x0E1F5670u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptAddRiderComponent>  (0x96F52D90u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptAgeableComponent>  (0xF8B9B962u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockComponentRegistry>  (0x19FB8985u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponent>  (0x7BCFFD17u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockDynamicPropertiesComponent>  (0x05BE6E36u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockFluidContainerComponent>  (0x98D0FDCBu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInstrumentComponent>  (0x6A08F4B5u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponent>  (0xC2D305AEu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockLavaContainerComponentV010>  (0xF16EE9AEu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockMapColorComponent>  (0xDD0EFAC1u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockMovableComponent>  (0x162914D8u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPistonComponent>  (0x82D8D3E9u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRecordPlayerComponent>  (0x916566A4u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRecordPlayerComponentV010>  (0x86220319u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRedstoneProducerComponent>  (0xE0337F72u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockSignComponent>  (0xD8D62F2Du)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockSnowContainerComponentV010>  (0xB4288915u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockWaterContainerComponentV010>  (0x5E702183u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBookItemComponent>  (0x36DE4DA3u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBreathableComponent>  (0x8B7DBD1Fu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptCanClimbComponent>  (0x9067769Au)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptCanFlyComponent>  (0x65826B56u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptCanPowerJumpComponent>  (0x4D49AA1Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptColor2Component>  (0x21447AFAu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptColorComponent>  (0x0A65F3CAu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptComponent>  (0x8823A80Du)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptCursorInventoryComponent>  (0x7AA387E7u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptCustomComponentParameters>  (0x44643762u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptEnderInventoryComponent>  (0x9955DD93u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptEquippableComponent>  (0xFE147625u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptExhaustionComponent>  (0x4A3A2015u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptFireImmuneComponent>  (0x88CB4C74u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptFloatsInLiquidComponent>  (0xF47288BDu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptFlyingSpeedComponent>  (0x2677704Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptFoodComponent>  (0x196ABFFDu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptFrictionModifierComponent>  (0xBC1CBB2Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptGroundOffsetComponent>  (0x456E8B5Du)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptHealableComponent>  (0x38D84C3Fu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptHealthComponent>  (0x31F95A6Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptHungerComponent>  (0x810F960Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponent>  (0x2F2CCF61u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponentContainer>  (0x8BC46512u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsBabyComponent>  (0x30B7EAEDu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsChargedComponent>  (0x06BA3FC1u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsChestedComponent>  (0x53A76EE1u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsDyeableComponent>  (0xC0FD26F3u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsHiddenWhenInvisibleComponent>  (0x70807B02u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsIgnitedComponent>  (0xF9B49757u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsIllagerCaptainComponent>  (0x026296F5u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsSaddledComponent>  (0x3DF09020u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsShakingComponent>  (0x1DBB6758u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsShearedComponent>  (0x4EBFBCFDu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsStackableComponent>  (0x6C398565u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsStunnedComponent>  (0x71D5596Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptIsTamedComponent>  (0x286A926Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemActorComponent>  (0x651F1B51u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>  (0xE800B99Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponentRegistry>  (0x2BC71A47u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCompostableComponent>  (0xDBBE2537u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCooldownComponent>  (0x626DCAB7u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponent>  (0xFC2000BDu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentConsumeEvent>  (0x4594B75Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentUseEvent>  (0xB10BEE5Au)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentUseOnEvent>  (0xC250C09Fu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemDurabilityComponent>  (0x10321405u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemDyeableComponent>  (0x406F6542u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemEnchantmentComponent>  (0x1639DA69u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemInventoryComponent>  (0xC42FAEB8u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptItemPotionComponent>  (0xF835A079u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptLavaMovementComponent>  (0x54DB3126u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptLeashableComponent>  (0x9E65EDF0u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMarkVariantComponent>  (0xAF72BB3Fu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMountTamingComponent>  (0xE27C467Au)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementAmphibiousComponent>  (0xBDB92251u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementBasicComponent>  (0x33A793F0u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementComponent>  (0x569691E0u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementFlyComponent>  (0xBFB21E13u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementGenericComponent>  (0x0CDDF24Fu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementGlideComponent>  (0x7891F28Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementHoverComponent>  (0xC52A6450u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementJumpComponent>  (0x7B8B7A4Cu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementSkipComponent>  (0xA878D69Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptMovementSwayComponent>  (0x719E0EDCu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationClimbComponent>  (0xD242983Au)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationFloatComponent>  (0x4844375Du)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationFlyComponent>  (0x54A54676u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationGenericComponent>  (0xE6C50C3Au)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationHoverComponent>  (0x7CF98D75u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationWalkComponent>  (0x9A624A4Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptNpcComponent>  (0x13428782u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptOnFireComponent>  (0x4AEAE504u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptProjectileComponent>  (0xEF0C164Eu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptPushThroughComponent>  (0x5F5991B8u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptRideableComponent>  (0xA20B0113u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptRidingComponent>  (0x0F4B3CB0u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptSaturationComponent>  (0xE33955E5u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptScaleComponent>  (0x4616975Bu)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptSkinIdComponent>  (0x77DCE045u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptStrengthComponent>  (0xFB27CB20u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptTameableComponent>  (0x7FC624D4u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptTypeFamilyComponent>  (0x9470B0D1u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptUnderwaterMovementComponent>  (0x6EC822C5u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptVariantComponent>  (0x016B9AE0u)
// Scripting::TypedObjectHandle<ScriptModuleMinecraft::ScriptWantsJockeyComponent>  (0x7C1D498Du)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>  (0x763A5728u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBoundingBox>  (0x5666E3BAu)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentClipboard>  (0x38A8E047u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentEntity>  (0xFB68E6EEu)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGizmo>  (0xB27B19E7u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGrid>  (0xDA8700B3u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentGuideSensor>  (0x442F07F3u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPlane>  (0x134DD78Bu)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrim>  (0x240BFA57u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentSpline>  (0x9DFAD2D4u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentText>  (0x543544F6u)
// Scripting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentVolumeOutline>  (0x02054D79u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::AttributeScriptActorComponent>  (0xA3410DA6u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>  (0xE706D31Fu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::MovementScriptActorComponent>  (0x1852205Bu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::NavigationScriptActorComponent>  (0x725BA43Au)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>  (0x185622B0u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptAddRiderComponent>  (0x05A463D0u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptAgeableComponent>  (0x1EDABDA2u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockComponentRegistry>  (0xF63A1CC5u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponent>  (0xAA5B7557u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockFluidContainerComponent>  (0xF3BEF70Bu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInstrumentComponent>  (0x331E02F5u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponent>  (0xD80B45EEu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockMapColorComponent>  (0x7003F201u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockMovableComponent>  (0xD5158F18u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPistonComponent>  (0x60821E29u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockRecordPlayerComponent>  (0xA091B1E4u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockSignComponent>  (0xC6DE2C6Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBookItemComponent>  (0x802781E3u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBreathableComponent>  (0xFF89055Fu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptCanClimbComponent>  (0x589403DAu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptCanFlyComponent>  (0x17702496u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptCanPowerJumpComponent>  (0x5C04025Eu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptColor2Component>  (0x548306BAu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptColorComponent>  (0xD2E8850Au)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptComponent>  (0x812C164Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptCursorInventoryComponent>  (0x9B3E7127u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptCustomComponentParameters>  (0xF96C63A2u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptEnderInventoryComponent>  (0x4B8D26D3u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptEquippableComponent>  (0xFC224765u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptExhaustionComponent>  (0x1C7A7D55u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptFireImmuneComponent>  (0x1A2B47B4u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptFloatsInLiquidComponent>  (0x970DFFFDu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptFlyingSpeedComponent>  (0x9C9BB78Bu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptFoodComponent>  (0xC796ED3Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptFrictionModifierComponent>  (0xE09EE16Eu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptGroundOffsetComponent>  (0x90C2AC9Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptHealableComponent>  (0x5C724C7Fu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptHealthComponent>  (0xCB9AAAABu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptHungerComponent>  (0x28CAC14Eu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponent>  (0x39090EA1u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponentContainer>  (0x9C62CE52u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptInventoryComponentContainer>>  (0x9B8AF404u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsBabyComponent>  (0x01FDEC2Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsChargedComponent>  (0xADB31901u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsChestedComponent>  (0x84A6C521u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsDyeableComponent>  (0x25EC3C33u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsIgnitedComponent>  (0x297E7197u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsIllagerCaptainComponent>  (0x71245735u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsSaddledComponent>  (0x1C24F860u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsShakingComponent>  (0x55C8E398u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsShearedComponent>  (0xD529B43Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsStackableComponent>  (0x4E0FE8A5u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsStunnedComponent>  (0x0532EFAEu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptIsTamedComponent>  (0x3F29A5AEu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemActorComponent>  (0x993BEC91u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>  (0x189FCBDEu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponentRegistry>  (0xF347DA87u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCompostableComponent>  (0xDF4D3E77u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCooldownComponent>  (0x85B50FF7u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponent>  (0x1169EBFDu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentUseEvent>  (0xB823469Au)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemDurabilityComponent>  (0xFD169945u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemDyeableComponent>  (0x2D83E482u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemEnchantmentComponent>  (0x364B61A9u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemInventoryComponent>  (0x06610DF8u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemPotionComponent>  (0x6B6588B9u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptLavaMovementComponent>  (0xE7D35966u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptLeashableComponent>  (0x52A0B530u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMarkVariantComponent>  (0x181F777Fu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMountTamingComponent>  (0x295556BAu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementAmphibiousComponent>  (0x1662D791u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementBasicComponent>  (0x2B618630u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementComponent>  (0xA9CFCF20u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementFlyComponent>  (0xBD205853u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementGenericComponent>  (0xF937088Fu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementGlideComponent>  (0x015BC2CBu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementHoverComponent>  (0x3EAE5490u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementJumpComponent>  (0x63E9188Cu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementSkipComponent>  (0xC969F6DBu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptMovementSwayComponent>  (0xF9EEE01Cu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationClimbComponent>  (0x62BBA57Au)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationFloatComponent>  (0x22EDB49Du)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationFlyComponent>  (0x787788B6u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationGenericComponent>  (0x4D98497Au)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationHoverComponent>  (0xFF00EDB5u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNavigationWalkComponent>  (0x1457838Eu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptNpcComponent>  (0xA17F52C2u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptOnFireComponent>  (0x305E5644u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptProjectileComponent>  (0x2EE3408Eu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptPushThroughComponent>  (0xF3EDAEF8u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptRideableComponent>  (0x0DA7F053u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptRidingComponent>  (0x733BDDF0u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptSaturationComponent>  (0x9DC16925u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptScaleComponent>  (0xB58D719Bu)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptSkinIdComponent>  (0xC98A0D85u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptStrengthComponent>  (0x1A1B8D60u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptTameableComponent>  (0x60D49014u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptTypeFamilyComponent>  (0x096AA711u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptUnderwaterMovementComponent>  (0x451CB505u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptVariantComponent>  (0xF771DC20u)
// Scripting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptWantsJockeyComponent>  (0x298709CDu)
// ScriptModuleMinecraft::AttributeScriptActorComponent  (0xE9731D60u)
// ScriptModuleMinecraft::BaseScriptBlockComponent  (0x277DF7B7u)
// ScriptModuleMinecraft::BaseScriptBlockLiquidContainerComponentV010  (0x65F318F5u)
// ScriptModuleMinecraft::ClientScriptPrimitiveShapesDataComponent  (0x451FD093u)
// ScriptModuleMinecraft::MovementScriptActorComponent  (0x0D3EB07Bu)
// ScriptModuleMinecraft::NavigationScriptActorComponent  (0x901C1914u)
// ScriptModuleMinecraft::ScriptActorComponent  (0x3C1F9392u)
// ScriptModuleMinecraft::ScriptActorInvalidComponentError  (0x87AB8519u)
// ScriptModuleMinecraft::ScriptAddRiderComponent  (0xC185F98Au)
// ScriptModuleMinecraft::ScriptAgeableComponent  (0x1789020Cu)
// ScriptModuleMinecraft::ScriptBlockComponentRegistry  (0x84EA79C5u)
// ScriptModuleMinecraft::ScriptBlockCustomComponent  (0x3512E7C7u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentActorAfterEvent  (0xC8CA660Au)
// ScriptModuleMinecraft::ScriptBlockCustomComponentAlreadyRegisteredError  (0xB42B7EA9u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentBlockBreakAfterEvent  (0xC59E52BDu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentBlockStateChangeAfterEvent  (0x72A5AA33u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentEntityFallOnAfterEvent  (0x034F4BCAu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentInterface  (0x2D0EFC76u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentOnPlaceAfterEvent  (0xEECCA0DBu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerBreakAfterEvent  (0xF5818BEBu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerInteractAfterEvent  (0x2F77548Eu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerPlaceBeforeEvent  (0x827664DEu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentRandomTickAfterEvent  (0x907E1FA3u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentRedstoneUpdateEvent  (0x8760F09Eu)
// ScriptModuleMinecraft::ScriptBlockCustomComponentReloadNewComponentError  (0x5AA68527u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentReloadNewEventError  (0xEA3F9116u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentReloadVersionError  (0x4D5D54C4u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentStepOffAfterEvent  (0x5F256448u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentStepOnAfterEvent  (0xB31B15D6u)
// ScriptModuleMinecraft::ScriptBlockCustomComponentTickAfterEvent  (0x4F9B9034u)
// ScriptModuleMinecraft::ScriptBlockDynamicPropertiesComponent  (0xC3983BE0u)
// ScriptModuleMinecraft::ScriptBlockFluidContainerComponent  (0x86455EB3u)
// ScriptModuleMinecraft::ScriptBlockInstrumentComponent  (0xE277D235u)
// ScriptModuleMinecraft::ScriptBlockInvalidComponentError  (0xB31EF2EDu)
// ScriptModuleMinecraft::ScriptBlockInventoryComponent  (0xE5149280u)
// ScriptModuleMinecraft::ScriptBlockInventoryComponentContainerV010  (0x817F9B68u)
// ScriptModuleMinecraft::ScriptBlockLavaContainerComponentV010  (0x715109F0u)
// ScriptModuleMinecraft::ScriptBlockMapColorComponent  (0x572CA4F9u)
// ScriptModuleMinecraft::ScriptBlockMovableComponent  (0xB5185D7Au)
// ScriptModuleMinecraft::ScriptBlockPistonComponent  (0x02CB8059u)
// ScriptModuleMinecraft::ScriptBlockPotionContainerComponentV010  (0xE85350D9u)
// ScriptModuleMinecraft::ScriptBlockPrecipitationInteractionsComponent  (0x227C82B6u)
// ScriptModuleMinecraft::ScriptBlockRecordPlayerComponent  (0x9CBA50BEu)
// ScriptModuleMinecraft::ScriptBlockRecordPlayerComponentV010  (0x951145E1u)
// ScriptModuleMinecraft::ScriptBlockRedstoneProducerComponent  (0x6064822Cu)
// ScriptModuleMinecraft::ScriptBlockSignComponent  (0x39285325u)
// ScriptModuleMinecraft::ScriptBlockSnowContainerComponentV010  (0xCF348FFDu)
// ScriptModuleMinecraft::ScriptBlockWaterContainerComponentV010  (0x4685376Bu)
// ScriptModuleMinecraft::ScriptBookItemComponent  (0x79842CE3u)
// ScriptModuleMinecraft::ScriptBreathableComponent  (0x431C2577u)
// ScriptModuleMinecraft::ScriptCanClimbComponent  (0x04F3BF24u)
// ScriptModuleMinecraft::ScriptCanFlyComponent  (0x46CAD320u)
// ScriptModuleMinecraft::ScriptCanPowerJumpComponent  (0x71391470u)
// ScriptModuleMinecraft::ScriptColor2Component  (0x57E540D4u)
// ScriptModuleMinecraft::ScriptColorComponent  (0x682B6D2Cu)
// ScriptModuleMinecraft::ScriptComponent  (0xEA7B379Du)
// ScriptModuleMinecraft::ScriptCursorInventoryComponent  (0xF8E614A7u)
// ScriptModuleMinecraft::ScriptCustomComponentInvalidRegistryError  (0xF5373FBAu)
// ScriptModuleMinecraft::ScriptCustomComponentNameError  (0x50FD59CBu)
// ScriptModuleMinecraft::ScriptCustomComponentNameError::Reason  (0x9EC425DFu)
// ScriptModuleMinecraft::ScriptCustomComponentParameters  (0xE0984DD4u)
// ScriptModuleMinecraft::ScriptEnderInventoryComponent  (0x5483B70Bu)
// ScriptModuleMinecraft::ScriptEquippableComponent  (0x9C36E2A5u)
// ScriptModuleMinecraft::ScriptExhaustionComponent  (0xB4DC10ADu)
// ScriptModuleMinecraft::ScriptFireImmuneComponent  (0x16B44B76u)
// ScriptModuleMinecraft::ScriptFloatsInLiquidComponent  (0xE497821Du)
// ScriptModuleMinecraft::ScriptFlyingSpeedComponent  (0x7D2B64A3u)
// ScriptModuleMinecraft::ScriptFoodComponent  (0xBE7CC3CDu)
// ScriptModuleMinecraft::ScriptFrictionModifierComponent  (0xFB639E28u)
// ScriptModuleMinecraft::ScriptGroundOffsetComponent  (0x620AE2EDu)
// ScriptModuleMinecraft::ScriptHealableComponent  (0xDFB069E7u)
// ScriptModuleMinecraft::ScriptHealthComponent  (0xCC406E4Bu)
// ScriptModuleMinecraft::ScriptHungerComponent  (0xE1B285F0u)
// ScriptModuleMinecraft::ScriptInventoryComponent  (0xDAB5C319u)
// ScriptModuleMinecraft::ScriptInventoryComponentContainer  (0x8451744Cu)
// ScriptModuleMinecraft::ScriptIsBabyComponent  (0x4CB826DDu)
// ScriptModuleMinecraft::ScriptIsChargedComponent  (0xB1A51EC1u)
// ScriptModuleMinecraft::ScriptIsChestedComponent  (0x48161879u)
// ScriptModuleMinecraft::ScriptIsDyeableComponent  (0x3D68BB63u)
// ScriptModuleMinecraft::ScriptIsHiddenWhenInvisibleComponent  (0x82CBFC74u)
// ScriptModuleMinecraft::ScriptIsIgnitedComponent  (0x0F9746FFu)
// ScriptModuleMinecraft::ScriptIsIllagerCaptainComponent  (0xC5323795u)
// ScriptModuleMinecraft::ScriptIsSaddledComponent  (0xDC5A86DAu)
// ScriptModuleMinecraft::ScriptIsShakingComponent  (0xFE7C21DAu)
// ScriptModuleMinecraft::ScriptIsShearedComponent  (0xE9DA659Du)
// ScriptModuleMinecraft::ScriptIsStackableComponent  (0x616AEB35u)
// ScriptModuleMinecraft::ScriptIsStunnedComponent  (0x8FB395D8u)
// ScriptModuleMinecraft::ScriptIsTamedComponent  (0x3D0B0648u)
// ScriptModuleMinecraft::ScriptItemActorComponent  (0x04C09BE1u)
// ScriptModuleMinecraft::ScriptItemBlockDynamicPropertiesComponent  (0x9DF75FDDu)
// ScriptModuleMinecraft::ScriptItemComponent  (0x2DC1E928u)
// ScriptModuleMinecraft::ScriptItemComponentRegistry  (0x3738C82Fu)
// ScriptModuleMinecraft::ScriptItemCompostableComponent  (0x9A4CDE3Fu)
// ScriptModuleMinecraft::ScriptItemCooldownComponent  (0x099FF0AFu)
// ScriptModuleMinecraft::ScriptItemCustomComponent  (0xD105B4E5u)
// ScriptModuleMinecraft::ScriptItemCustomComponentAlreadyRegisteredError  (0xCA4A92D3u)
// ScriptModuleMinecraft::ScriptItemCustomComponentBeforeDurabilityDamageEvent  (0x5CFD8D10u)
// ScriptModuleMinecraft::ScriptItemCustomComponentCompleteUseEvent  (0xE020324Fu)
// ScriptModuleMinecraft::ScriptItemCustomComponentConsumeEvent  (0xB2C79DFBu)
// ScriptModuleMinecraft::ScriptItemCustomComponentHitEntityEvent  (0x30CBEE33u)
// ScriptModuleMinecraft::ScriptItemCustomComponentInterface  (0xA86B2630u)
// ScriptModuleMinecraft::ScriptItemCustomComponentMineBlockEvent  (0x379BF521u)
// ScriptModuleMinecraft::ScriptItemCustomComponentReloadNewComponentError  (0x28942E6Du)
// ScriptModuleMinecraft::ScriptItemCustomComponentReloadNewEventError  (0xD1755010u)
// ScriptModuleMinecraft::ScriptItemCustomComponentReloadVersionError  (0xB10DE086u)
// ScriptModuleMinecraft::ScriptItemCustomComponentUseEvent  (0xECB938ACu)
// ScriptModuleMinecraft::ScriptItemCustomComponentUseOnEvent  (0x0FCF8677u)
// ScriptModuleMinecraft::ScriptItemDurabilityComponent  (0x59DCA7BDu)
// ScriptModuleMinecraft::ScriptItemDyeableComponent  (0x76607A74u)
// ScriptModuleMinecraft::ScriptItemEnchantmentComponent  (0x0B997269u)
// ScriptModuleMinecraft::ScriptItemInventoryComponent  (0xD145CB82u)
// ScriptModuleMinecraft::ScriptItemPotionComponent  (0x6579CA51u)
// ScriptModuleMinecraft::ScriptLavaMovementComponent  (0x07A97D08u)
// ScriptModuleMinecraft::ScriptLeashableComponent  (0xDFCE0AF2u)
// ScriptModuleMinecraft::ScriptMarkVariantComponent  (0x73C59F5Fu)
// ScriptModuleMinecraft::ScriptMountTamingComponent  (0xB635DFDCu)
// ScriptModuleMinecraft::ScriptMovementAmphibiousComponent  (0xE50FB3A9u)
// ScriptModuleMinecraft::ScriptMovementBasicComponent  (0x584ADEB2u)
// ScriptModuleMinecraft::ScriptMovementComponent  (0xAC2DE1BAu)
// ScriptModuleMinecraft::ScriptMovementFlyComponent  (0x2DCA3263u)
// ScriptModuleMinecraft::ScriptMovementGenericComponent  (0xC572C0CFu)
// ScriptModuleMinecraft::ScriptMovementGlideComponent  (0x2FD4FA8Bu)
// ScriptModuleMinecraft::ScriptMovementHoverComponent  (0xC9B53ADAu)
// ScriptModuleMinecraft::ScriptMovementJumpComponent  (0xD75BA286u)
// ScriptModuleMinecraft::ScriptMovementSkipComponent  (0x038741E3u)
// ScriptModuleMinecraft::ScriptMovementSwayComponent  (0xACF8606Eu)
// ScriptModuleMinecraft::ScriptNavigationClimbComponent  (0x191BBD84u)
// ScriptModuleMinecraft::ScriptNavigationFloatComponent  (0x12F6A8C5u)
// ScriptModuleMinecraft::ScriptNavigationFlyComponent  (0xAF34E100u)
// ScriptModuleMinecraft::ScriptNavigationGenericComponent  (0x20BC9A44u)
// ScriptModuleMinecraft::ScriptNavigationHoverComponent  (0xE0F46145u)
// ScriptModuleMinecraft::ScriptNavigationWalkComponent  (0x49CC7270u)
// ScriptModuleMinecraft::ScriptNpcComponent  (0x58CBAFE4u)
// ScriptModuleMinecraft::ScriptOnFireComponent  (0xB9AE86FEu)
// ScriptModuleMinecraft::ScriptPlayerInventoryComponentContainer  (0x486B145Bu)
// ScriptModuleMinecraft::ScriptPrimitiveShapesDataComponent  (0x33024B18u)
// ScriptModuleMinecraft::ScriptProjectileComponent  (0x96937B88u)
// ScriptModuleMinecraft::ScriptPushThroughComponent  (0xF0484992u)
// ScriptModuleMinecraft::ScriptRideableComponent  (0x03FF152Bu)
// ScriptModuleMinecraft::ScriptRidingComponent  (0x68093BE2u)
// ScriptModuleMinecraft::ScriptSaturationComponent  (0x952E0E0Du)
// ScriptModuleMinecraft::ScriptScaleComponent  (0x32189C6Bu)
// ScriptModuleMinecraft::ScriptSkinIdComponent  (0x950A7385u)
// ScriptModuleMinecraft::ScriptStrengthComponent  (0x4AF000B2u)
// ScriptModuleMinecraft::ScriptTameableComponent  (0x244543D6u)
// ScriptModuleMinecraft::ScriptTypeFamilyComponent  (0x48F2F579u)
// ScriptModuleMinecraft::ScriptUnderwaterMovementComponent  (0x335661FDu)
// ScriptModuleMinecraft::ScriptVariantComponent  (0x3C3D8DEAu)
// ScriptModuleMinecraft::ScriptWantsJockeyComponent  (0x6C556E7Du)
// ScriptSimpleBlockVolume>, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x1E3AC79Bu)
// SharedTypes::Beta::AllowOffHandItemComponent  (0xC0C68232u)
// SharedTypes::Beta::AtomicClientEntity::AABBShapeComponentDefinition  (0x6B7F049Du)
// SharedTypes::Beta::BiomeComponents  (0xA6F15685u)
// SharedTypes::Beta::DurabilitySensorItemComponent  (0xC6397298u)
// SharedTypes::Beta::ItemComponents  (0xBA9C188Cu)
// SharedTypes::Beta::RecordItemComponent  (0xF79655E0u)
// SharedTypes::Beta::SurfaceBuilderBiomeJsonComponent  (0xF9A5E36Cu)
// SharedTypes::Beta::SwingSoundsItemComponent  (0x704C42DFu)
// SharedTypes::Beta::UseModifiersItemComponent  (0x8F744532u)
// SharedTypes::Legacy::ApplyKnockbackRulesComponentDefinition  (0x9F559032u)
// SharedTypes::Legacy::ApplyKnockbackRulesComponentDefinition::ApplyKnockbackRulesPreset  (0x0DBDBF1Bu)
// SharedTypes::Legacy::ComponentItemData  (0x77C00112u)
// SharedTypes::Legacy::OnCompleteTriggerItemComponent  (0xFC5F384Eu)
// SharedTypes::Legacy::OnConsumeTriggerItemComponent  (0x7BA22A0Du)
// SharedTypes::Legacy::OnHitActorTriggerItemComponent  (0x3F79C92Bu)
// SharedTypes::Legacy::OnHitBlockTriggerItemComponent  (0xE9755A8Bu)
// SharedTypes::Legacy::OnHurtActorTriggerItemComponent  (0x12A1C375u)
// SharedTypes::Legacy::OnUseOnTriggerItemComponent  (0x680D6785u)
// SharedTypes::Legacy::OnUseTriggerItemComponent  (0x5BA85244u)
// SharedTypes::Legacy::RenderOffsetsItemComponent  (0x2A215628u)
// SharedTypes::Legacy::RenderOffsetsItemComponent::ItemTransforms  (0x3AE9E5DAu)
// SharedTypes::Legacy::RenderOffsetsItemComponent::TRS  (0xB28B63CFu)
// SharedTypes::v1_20_30::ItemDeprecatedComponentData  (0x8E0C2CA0u)
// SharedTypes::v1_20_40::ItemDeprecatedComponentData  (0xF6C4B4CDu)
// SharedTypes::v1_20_50::AllowOffHandItemComponent  (0x6E3A07B0u)
// SharedTypes::v1_20_50::CanDestroyInCreativeItemComponent  (0xD73DB677u)
// SharedTypes::v1_20_50::ComponentItemComponentData  (0x05E921CAu)
// SharedTypes::v1_20_50::CooldownItemComponent  (0x601AD942u)
// SharedTypes::v1_20_50::DamageItemComponent  (0xA85C731Au)
// SharedTypes::v1_20_50::DiggerItemComponent  (0x9E80DC83u)
// SharedTypes::v1_20_50::DiggerItemComponent::BlockInfo  (0x21760F90u)
// SharedTypes::v1_20_50::DisplayNameItemComponent  (0x5DA1EFC0u)
// SharedTypes::v1_20_50::DurabilityItemComponent  (0x0057AC10u)
// SharedTypes::v1_20_50::EnchantableItemComponent  (0xFF2E2C70u)
// SharedTypes::v1_20_50::EntityPlacerItemComponent  (0xDEC7A875u)
// SharedTypes::v1_20_50::FoodItemComponent  (0xD9CFE591u)
// SharedTypes::v1_20_50::FuelItemComponent  (0x14A80D4Du)
// SharedTypes::v1_20_50::GlintItemComponent  (0x2A9DB247u)
// SharedTypes::v1_20_50::HandEquippedItemComponent  (0x6EAEC29Du)
// SharedTypes::v1_20_50::HoverTextColorItemComponent  (0x0179DD61u)
// SharedTypes::v1_20_50::IconItemComponent  (0x105ADACAu)
// SharedTypes::v1_20_50::InteractButtonItemComponent  (0xC14A2037u)
// SharedTypes::v1_20_50::ItemDeprecatedComponentData  (0x727E65AAu)
// SharedTypes::v1_20_50::LiquidClippedItemComponent  (0xFB7C860Au)
// SharedTypes::v1_20_50::MaxStackSizeItemComponent  (0x3910C974u)
// SharedTypes::v1_20_50::PlanterItemComponent  (0xE56ADB45u)
// SharedTypes::v1_20_50::ProjectileItemComponent  (0x9373963Cu)
// SharedTypes::v1_20_50::RecordItemComponent  (0xCE5C3D2Eu)
// SharedTypes::v1_20_50::RepairableItemComponent  (0x08418DCEu)
// SharedTypes::v1_20_50::RepairableItemComponent::RepairItemEntry  (0xD9CC1DECu)
// SharedTypes::v1_20_50::ShooterItemComponent  (0x2D87B31Fu)
// SharedTypes::v1_20_50::ShooterItemComponent::Ammunition  (0x2132CCB8u)
// SharedTypes::v1_20_50::ShouldDespawnItemComponent  (0x8A9626AAu)
// SharedTypes::v1_20_50::StackedByDataItemComponent  (0x2271CC37u)
// SharedTypes::v1_20_50::TagsItemComponent  (0x76BB917Au)
// SharedTypes::v1_20_50::ThrowableItemComponent  (0xC961774Bu)
// SharedTypes::v1_20_50::UseAnimationItemComponent  (0x38FAE9E4u)
// SharedTypes::v1_20_50::UseModifiersItemComponent  (0xBAE7E604u)
// SharedTypes::v1_20_50::WearableItemComponent  (0x9F46C0D4u)
// SharedTypes::v1_20_60::ClimateBiomeJsonComponent  (0xFE5F0710u)
// SharedTypes::v1_20_60::ComponentItemComponentData  (0xF7A2B2D9u)
// SharedTypes::v1_20_60::CreatureSpawnProbabilityBiomeJsonComponent  (0xB21737F8u)
// SharedTypes::v1_20_60::IconItemComponent  (0x2FEF2AA7u)
// SharedTypes::v1_20_60::MountainParametersBiomeJsonComponent  (0x229BFF64u)
// SharedTypes::v1_20_60::MountainParametersBiomeJsonComponent::SteepMaterial  (0xC4EFEE12u)
// SharedTypes::v1_20_60::MountainParametersBiomeJsonComponent::TopSlideSettings  (0x7B0CC801u)
// SharedTypes::v1_20_60::MultinoiseGenerationRulesBiomeJsonComponent  (0xF11C84CDu)
// SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent  (0x354E48FCu)
// SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedBiomeName  (0xCD8B93D4u)
// SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedBiomeNameVector  (0x460628B3u)
// SharedTypes::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedBiomeNameVector>  (0xC8B1D5F7u)
// SharedTypes::v1_20_60::OverworldHeightBiomeJsonComponent  (0xED896D1Au)
// SharedTypes::v1_20_60::OverworldHeightBiomeJsonComponent::NoiseType  (0xD806D240u)
// SharedTypes::v1_20_60::SurfaceMaterialAdjustmentsBiomeJsonComponent  (0x46D8D269u)
// SharedTypes::v1_20_60::TagsBiomeJsonComponent  (0xD94ED53Eu)
// SharedTypes::v1_20_80::ComponentItemComponentData  (0x2192E253u)
// SharedTypes::v1_20_80::CustomComponentsItemComponent  (0x2FF64523u)
// SharedTypes::v1_20_80::EmitterInitialExpressionComponent  (0x4126D563u)
// SharedTypes::v1_20_80::EmitterLifetimeEventsComponent  (0xE2465C1Fu)
// SharedTypes::v1_20_80::EmitterLifetimeEventsComponentHelper::Proxy  (0x3AD43585u)
// SharedTypes::v1_20_80::EmitterLifetimeExpressionComponent  (0x5CE141BAu)
// SharedTypes::v1_20_80::EmitterLifetimeLoopingComponent  (0xACDDDC6Cu)
// SharedTypes::v1_20_80::EmitterLifetimeOnceComponent  (0xEA9A701Fu)
// SharedTypes::v1_20_80::EmitterLocalSpaceComponent  (0x93E2F68Cu)
// SharedTypes::v1_20_80::EmitterLocalSpaceComponentHelper::Proxy  (0x3EE6DB10u)
// SharedTypes::v1_20_80::EmitterRateInstantComponent  (0xBBB15AFCu)
// SharedTypes::v1_20_80::EmitterRateManualComponent  (0x8E0EF1C5u)
// SharedTypes::v1_20_80::EmitterRateSteadyComponent  (0x4159EEC5u)
// SharedTypes::v1_20_80::EmitterShapeBoxComponent  (0x8FAF3517u)
// SharedTypes::v1_20_80::EmitterShapeCustomComponent  (0xFC113603u)
// SharedTypes::v1_20_80::EmitterShapeDiscComponent  (0xBAC3638Du)
// SharedTypes::v1_20_80::EmitterShapeEntityAABBComponent  (0x1A75CFE9u)
// SharedTypes::v1_20_80::EmitterShapePointComponent  (0xB945AD6Au)
// SharedTypes::v1_20_80::EmitterShapeSphereComponent  (0x10CD03B1u)
// SharedTypes::v1_20_80::ParticleAppearanceBillboardComponent  (0x9077E762u)
// SharedTypes::v1_20_80::ParticleAppearanceLightingComponent  (0xE0925FA7u)
// SharedTypes::v1_20_80::ParticleAppearanceTintingComponent  (0xD8C66572u)
// SharedTypes::v1_20_80::ParticleAppearanceTintingComponentHelper::ColorProxy  (0x9FB2CED3u)
// SharedTypes::v1_20_80::ParticleEffectComponents  (0xD7817A27u)
// SharedTypes::v1_20_80::ParticleInitialExpressionComponent  (0xB75E3A27u)
// SharedTypes::v1_20_80::ParticleInitialSpeedComponent  (0xB0CB5A28u)
// SharedTypes::v1_20_80::ParticleInitialSpinComponent  (0xC104CA11u)
// SharedTypes::v1_20_80::ParticleLifetimeEventsComponent  (0x6193088Bu)
// SharedTypes::v1_20_80::ParticleLifetimeEventsComponentHelper::Proxy  (0x52AEA109u)
// SharedTypes::v1_20_80::ParticleLifetimeExpireIfInBlocksComponent  (0x9039C72Fu)
// SharedTypes::v1_20_80::ParticleLifetimeExpireIfNotInBlocksComponent  (0x08D50386u)
// SharedTypes::v1_20_80::ParticleLifetimeExpressionComponent  (0x5167607Eu)
// SharedTypes::v1_20_80::ParticleLifetimeKillPlaneComponent  (0x12365DBCu)
// SharedTypes::v1_20_80::ParticleMotionCollisionComponent  (0x72AEB3C3u)
// SharedTypes::v1_20_80::ParticleMotionDynamicComponent  (0x8128ACF8u)
// SharedTypes::v1_20_80::ParticleMotionParametricComponent  (0xC68B43E5u)
// SharedTypes::v1_20_80::TintingComponentColor  (0xB507C2A5u)
// SharedTypes::v1_21_100::ClientBiomeJsonDocument::ClientBiomeJsonObject::ComponentMap  (0x489AE019u)
// SharedTypes::v1_21_100::CustomHumidityBiomeJsonComponent  (0xC2F686CBu)
// SharedTypes::v1_21_100::CustomMapTintBiomeJsonComponent  (0x0E8907C3u)
// SharedTypes::v1_21_100::CustomMapTintBiomeJsonComponent::GrassNoise  (0xB51E96DBu)
// SharedTypes::v1_21_100::CustomMapTintBiomeJsonComponent::GrassTint  (0x19A14CA2u)
// SharedTypes::v1_21_100::CustomMapTintBiomeJsonComponent::GrassType  (0xE3FC3557u)
// SharedTypes::v1_21_100::FrozenNoiseBasedBiomeJsonComponent  (0x36D3D476u)
// SharedTypes::v1_21_100::GrassAppearanceClientBiomeJsonComponent  (0x583B1056u)
// SharedTypes::v1_21_100::GrassAppearanceClientBiomeJsonComponent::GrassColorMapContainer  (0xE28C746Au)
// SharedTypes::v1_21_100::GrassAppearanceClientBiomeJsonComponent::GrassColorMapContainer>>  (0x01B36326u)
// SharedTypes::v1_21_100::SurfaceBuilderBiomeJsonComponent  (0x5F072647u)
// SharedTypes::v1_21_10::ComponentItemComponentData  (0x3AC444C3u)
// SharedTypes::v1_21_10::DamageAbsorptionItemComponent  (0xE5086292u)
// SharedTypes::v1_21_10::DurabilitySensorItemComponent  (0xA626C23Du)
// SharedTypes::v1_21_110::BiomeComponents  (0x3482F013u)
// SharedTypes::v1_21_110::ClientBiomeJsonDocument::ClientBiomeJsonObject::ComponentMap  (0xF9DCA7ACu)
// SharedTypes::v1_21_110::ExperienceRewardComponentDefinition  (0x8065A23Cu)
// SharedTypes::v1_21_110::MusicClientBiomeJsonComponent  (0x0F1D0EF2u)
// SharedTypes::v1_21_110::PrecipitationClientBiomeJsonComponent  (0xCC039F36u)
// SharedTypes::v1_21_120::AmbientSoundsClientBiomeJsonComponent  (0x49E738ECu)
// SharedTypes::v1_21_120::AmbientSoundsClientBiomeJsonComponent::SoundAddition  (0xA7C8E8EBu)
// SharedTypes::v1_21_120::ClientBiomeJsonDocument::ClientBiomeJsonObject::ComponentMap  (0xD711C04Bu)
// SharedTypes::v1_21_130::AddRiderComponentDefinition  (0x27ADCEF4u)
// SharedTypes::v1_21_130::AddRiderComponentDefinition::RiderData  (0x984020A0u)
// SharedTypes::v1_21_130::BurnsInDaylightComponentDefinition  (0x596E81B8u)
// SharedTypes::v1_21_130::ClientBiomeJsonDocument::ClientBiomeJsonObject::ComponentMap  (0x4C1E5EA6u)
// SharedTypes::v1_21_130::DataDrivenUI::ComponentType  (0x9EC06D26u)
// SharedTypes::v1_21_130::SkyboxIdentifierClientBiomeJsonComponent  (0x81AFF188u)
// SharedTypes::v1_21_30::BundleInteractionItemComponent  (0xBBC15408u)
// SharedTypes::v1_21_30::ComponentItemComponentData  (0xD67DCEE5u)
// SharedTypes::v1_21_30::DyeableItemComponent  (0x6D338F5Au)
// SharedTypes::v1_21_30::RarityItemComponent  (0xDFC8D689u)
// SharedTypes::v1_21_30::StorageItemComponent  (0xADA11FD3u)
// SharedTypes::v1_21_40::AmbientSoundsClientBiomeJsonComponent  (0x13B14521u)
// SharedTypes::v1_21_40::ClientBiomeJsonDocument::ClientBiomeJsonObject::ComponentMap  (0xBD0B0110u)
// SharedTypes::v1_21_40::ComponentItemComponentData  (0xCFE5ED72u)
// SharedTypes::v1_21_40::FogAppearanceClientBiomeJsonComponent  (0xA38A100Fu)
// SharedTypes::v1_21_40::FoliageAppearanceClientBiomeJsonComponent  (0xF81A99F8u)
// SharedTypes::v1_21_40::FoliageAppearanceClientBiomeJsonComponent::FoliageColorMapContainer  (0x33DF0D57u)
// SharedTypes::v1_21_40::FoliageAppearanceClientBiomeJsonComponent::FoliageColorMapContainer>  (0x11221C4Bu)
// SharedTypes::v1_21_40::GrassAppearanceClientBiomeJsonComponent  (0x7D0EFACDu)
// SharedTypes::v1_21_40::GrassAppearanceClientBiomeJsonComponent::GrassColorMapContainer  (0x5275575Du)
// SharedTypes::v1_21_40::MusicClientBiomeJsonComponent  (0xBC7FA4DEu)
// SharedTypes::v1_21_40::PlanterItemComponent  (0x849FF75Du)
// SharedTypes::v1_21_40::SkyColorClientBiomeJsonComponent  (0xE933D7F3u)
// SharedTypes::v1_21_40::WaterAppearanceClientBiomeJsonComponent  (0x7DB38CE0u)
// SharedTypes::v1_21_50::ComponentItemComponentData  (0xC2477D7Fu)
// SharedTypes::v1_21_50::CompostableItemComponent  (0x131A937Bu)
// SharedTypes::v1_21_60::ComponentItemComponentData  (0x6FD90AB4u)
// SharedTypes::v1_21_60::CustomComponentsItemComponent  (0xE2978352u)
// SharedTypes::v1_21_60::DimensionDefinition::Components  (0x4FAE043Cu)
// SharedTypes::v1_21_60::StorageItemComponent  (0x6A9EFFA6u)
// SharedTypes::v1_21_60::StorageWeightLimitItemComponent  (0x66B24D1Fu)
// SharedTypes::v1_21_60::StorageWeightModifierItemComponent  (0xAAC946E5u)
// SharedTypes::v1_21_70::AtmosphereIdentifierClientBiomeJsonComponent  (0x8CD63197u)
// SharedTypes::v1_21_70::ClientBiomeJsonDocument::ClientBiomeJsonObject::ComponentMap  (0x1E9CAF7Fu)
// SharedTypes::v1_21_70::ColorGradingIdentifierClientBiomeJsonComponent  (0x5613C906u)
// SharedTypes::v1_21_70::DryFoliageColorClientBiomeJsonComponent  (0x0F2BBF23u)
// SharedTypes::v1_21_70::FoliageAppearanceClientBiomeJsonComponent  (0xA4DD385Du)
// SharedTypes::v1_21_70::FoliageAppearanceClientBiomeJsonComponent::FoliageColorMapContainer  (0x47A69E32u)
// SharedTypes::v1_21_70::FoliageAppearanceClientBiomeJsonComponent::FoliageColorMapContainer>  (0xD74ACCE4u)
// SharedTypes::v1_21_70::LightingIdentifierClientBiomeJsonComponent  (0x84002BE3u)
// SharedTypes::v1_21_70::WaterIdentifierClientBiomeJsonComponent  (0x1ACC0C04u)
// SharedTypes::v1_21_80::ComponentItemComponentData  (0x11CD3D9Eu)
// SharedTypes::v1_21_80::IconItemComponent  (0xFFED526Eu)
// SharedTypes::v1_21_80::MusicClientBiomeJsonComponent  (0xEE06271Au)
// SharedTypes::v1_21_80::ReplaceBiomesBiomeJsonComponent  (0xAFEA0317u)
// SharedTypes::v1_21_80::ReplaceBiomesBiomeJsonComponent::BiomeReplacement  (0xAE4A16C3u)
// SharedTypes::v1_21_90::ComponentItemComponentData  (0x16317E6Bu)
// SharedTypes::v1_21_90::FireResistantItemComponent  (0xC9B3B56Bu)
// SharedTypes::v1_21_90::KineticWeaponItemComponent  (0xAC420BBBu)
// SharedTypes::v1_21_90::PiercingWeaponItemComponent  (0xB968E98Bu)
// SharedTypes::v1_21_90::SwingDurationItemComponent  (0x3DF57C10u)
// SharedTypes::v1_21_90::SwingSoundsItemComponent  (0x33E5EC30u)
// SharedTypes::v1_21_90::WearableItemComponent  (0x4D1643B3u)
// SharedTypes::v1_26_0::BiomeComponents  (0xBEF231A6u)
// SharedTypes::v1_26_0::ComponentItemComponentData  (0xECDD0E19u)
// SharedTypes::v1_26_0::DamageItemComponent  (0x154FC8A7u)
// SharedTypes::v1_26_0::ExperienceRewardComponentDefinition  (0x2F4A3409u)
// SharedTypes::v1_26_0::PlanterItemComponent  (0x1E5AB21Eu)
// SharedTypes::v1_26_0::ReplaceBiomesBiomeJsonComponent  (0x5EEEE7AAu)
// SharedTypes::v1_26_0::ReplaceBiomesBiomeJsonComponent::BiomeReplacement  (0x2AE5417Au)
// SharedTypes::v1_26_0::VillageTypeBiomeJsonComponent  (0xBCF1BEDFu)
// SharedTypes::v1_26_20::BlockClimberComponentDefinition  (0x016C2631u)
// SharedTypes::v1_26_20::BlockDefinition::BlockArchetypeMaxComponentConstraint  (0x99C12CEEu)
// SharedTypes::v1_26_20::BlockDefinition::BlockComponents  (0x98667921u)
// SharedTypes::v1_26_20::BlockDefinition::BlockCustomComponent<false, false>  (0xA8ABC4F9u)
// SharedTypes::v1_26_20::BlockDefinition::BlockCustomComponent<false, true>  (0x227AF8DCu)
// SharedTypes::v1_26_20::BlockDefinition::BlockCustomComponent<true, false>  (0x166DE004u)
// SharedTypes::v1_26_20::BlockDefinition::BlockCustomComponent<true, true>  (0x0B5AF9E3u)
// SharedTypes::v1_26_20::BlockDefinition::BlockEntityComponent  (0x96A98051u)
// SharedTypes::v1_26_20::BlockDefinition::BlockEntityComponent::ContainerData  (0x98D4A19Cu)
// SharedTypes::v1_26_20::BlockDefinition::BlockSoundJsonComponent  (0x54BE971Du)
// SharedTypes::v1_26_20::BlockDefinition::ChestObstructionComponent  (0x68164E8Cu)
// SharedTypes::v1_26_20::BlockDefinition::CollisionBoxComponent  (0x57471340u)
// SharedTypes::v1_26_20::BlockDefinition::ConnectionRuleComponent  (0xF6553E99u)
// SharedTypes::v1_26_20::BlockDefinition::CraftingTableComponent  (0xE6D46535u)
// SharedTypes::v1_26_20::BlockDefinition::CrossComponentsConstraint  (0xDCC327DFu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedBreathabilityComponent  (0x82B3BCDEu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedFallOnComponent  (0x3094FEACu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedInteractComponent  (0x69166D92u)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedPlacedComponent  (0xEF33A9EFu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedPlayerDestroyedComponent  (0x333A205Eu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedPlayerPlacingComponent  (0x175C8E5Bu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedQueuedTickingComponent  (0xA58706CAu)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedRandomTickingComponent  (0xD421CF74u)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedStepOffComponent  (0xB7BBACE3u)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedStepOnComponent  (0x37EE3031u)
// SharedTypes::v1_26_20::BlockDefinition::DeprecatedUnitCubeComponent  (0x8EBAE881u)
// SharedTypes::v1_26_20::BlockDefinition::DestructibleByExplosionComponent  (0x6F7CB2F9u)
// SharedTypes::v1_26_20::BlockDefinition::DestructibleByMiningComponent  (0x6DEA5E16u)
// SharedTypes::v1_26_20::BlockDefinition::DestructibleByMiningComponent::DetailedMiningSpeed  (0x340D3145u)
// SharedTypes::v1_26_20::BlockDefinition::DestructibleByMiningComponent::DetailedMiningSpeed>  (0x6BC4E4A1u)
// SharedTypes::v1_26_20::BlockDefinition::DestructibleByMiningComponent::ItemSpecificSpeed  (0x443F0500u)
// SharedTypes::v1_26_20::BlockDefinition::DestructibleByMiningComponent::ItemSpecificSpeed>>>  (0x2AED8256u)
// SharedTypes::v1_26_20::BlockDefinition::DestructionParticlesComponent  (0xC062F7D6u)
// SharedTypes::v1_26_20::BlockDefinition::DisplayNameComponent  (0xC76A087Cu)
// SharedTypes::v1_26_20::BlockDefinition::EmbeddedVisualComponent  (0x00FCDF09u)
// SharedTypes::v1_26_20::BlockDefinition::EntityFallOnComponent  (0x42E14122u)
// SharedTypes::v1_26_20::BlockDefinition::FlammableComponent  (0x0C19481Eu)
// SharedTypes::v1_26_20::BlockDefinition::FlammableComponent::DetailedFlammable  (0x207EE855u)
// SharedTypes::v1_26_20::BlockDefinition::FlowerPottableComponent  (0x347C1F8Du)
// SharedTypes::v1_26_20::BlockDefinition::FrictionComponent  (0x5A3FA215u)
// SharedTypes::v1_26_20::BlockDefinition::GeometryComponent  (0x6EB551B3u)
// SharedTypes::v1_26_20::BlockDefinition::GeometryComponent::DetailedGeometry  (0xB784BD2Bu)
// SharedTypes::v1_26_20::BlockDefinition::GeometryComponent::DetailedGeometryConstraint  (0x852F5C48u)
// SharedTypes::v1_26_20::BlockDefinition::GeometryComponent::NWayVisualRotationStateMapping  (0xE9E752A5u)
// SharedTypes::v1_26_20::BlockDefinition::GeometryComponent::NWayVisualRotationStateMapping>  (0xD2270A01u)
// SharedTypes::v1_26_20::BlockDefinition::IBlockCustomComponent  (0xE53B576Eu)
// SharedTypes::v1_26_20::BlockDefinition::InstrumentComponent  (0x81126C28u)
// SharedTypes::v1_26_20::BlockDefinition::ItemVisualComponent  (0xF2540CA2u)
// SharedTypes::v1_26_20::BlockDefinition::LeashableComponent  (0x0D0E056Cu)
// SharedTypes::v1_26_20::BlockDefinition::LightDampeningComponent  (0x1F43288Au)
// SharedTypes::v1_26_20::BlockDefinition::LightEmissionComponent  (0x015BA502u)
// SharedTypes::v1_26_20::BlockDefinition::LiquidDetectionComponent  (0x342C0092u)
// SharedTypes::v1_26_20::BlockDefinition::LootComponent  (0x20FB46ADu)
// SharedTypes::v1_26_20::BlockDefinition::MapColorComponent  (0x73B0E928u)
// SharedTypes::v1_26_20::BlockDefinition::MapColorComponent::DetailedMapColor  (0x14D8CD55u)
// SharedTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent  (0x4726AC26u)
// SharedTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent::MaterialInstance  (0x13E3488Cu)
// SharedTypes::v1_26_20::BlockDefinition::MaterialInstancesComponent::MaterialInstance>>>>>  (0x6252FA4Eu)
// SharedTypes::v1_26_20::BlockDefinition::MovableComponent  (0xAD1FFB51u)
// SharedTypes::v1_26_20::BlockDefinition::PlacementFilterComponent  (0x6F331778u)
// SharedTypes::v1_26_20::BlockDefinition::PlacementFilterComponent::PlacementCondition  (0x26E77094u)
// SharedTypes::v1_26_20::BlockDefinition::PrecipitationInteractionsComponent  (0x477202A1u)
// SharedTypes::v1_26_20::BlockDefinition::RandomOffsetComponent  (0x31EA77E7u)
// SharedTypes::v1_26_20::BlockDefinition::RandomOffsetComponent::RangeAndSteps  (0xCDC97DBCu)
// SharedTypes::v1_26_20::BlockDefinition::RedstoneConductivityComponent  (0xAD952074u)
// SharedTypes::v1_26_20::BlockDefinition::RedstoneConsumerComponent  (0x05403F1Bu)
// SharedTypes::v1_26_20::BlockDefinition::RedstoneProducerComponent  (0x4CDBC829u)
// SharedTypes::v1_26_20::BlockDefinition::ReplaceableComponent  (0xF3CD8B53u)
// SharedTypes::v1_26_20::BlockDefinition::SelectionBoxComponent  (0xF51E4942u)
// SharedTypes::v1_26_20::BlockDefinition::SupportComponent  (0xA944BE56u)
// SharedTypes::v1_26_20::BlockDefinition::TickComponent  (0x0D097104u)
// SharedTypes::v1_26_20::BlockDefinition::TickComponent::FirstSmallerConstraint  (0xD453F075u)
// SharedTypes::v1_26_20::BlockDefinition::TransformationComponent  (0xD22085E8u)
// SharedTypes::v1_26_20::Brain::MemorySensors::FindNearestEntityComponentDefinition  (0xC78F5C20u)
// SharedTypes::v1_26_20::Brain::MemorySensors::FindNearestPoiComponentDefinition  (0x0BA0C873u)
// SharedTypes::v1_26_20::Brain::MemorySensors::GameEventComponentDefinition  (0x1F98F4E2u)
// SharedTypes::v1_26_20::Brain::MemorySensors::InRangeOfEntityComponentDefinition  (0xC0C4DA26u)
// SharedTypes::v1_26_20::CanJoinRaidComponentDefinition  (0xAD7D96C8u)
// SharedTypes::v1_26_20::DimensionBoundComponentDefinition  (0x98F83072u)
// SharedTypes::v1_26_20::HopperComponentDefinition  (0x9C1076F4u)
// SharedTypes::v1_26_20::OutOfControlComponentDefinition  (0x6812E0F4u)
// SharedTypes::v1_26_20::PushableByEntityComponentDefinition  (0xBD4CC6FCu)
// SharedTypes::v1_26_20::SpawnOnDeathComponentDefinition  (0x8C6F7C3Eu)
// SharedTypes::v1_26_20::SuspectTrackingComponentDefinition  (0x821993FEu)
// SharedTypes::v1_26_20::TransientComponentDefinition  (0xF4F23454u)
// SharedTypes::v1_26_20::VibrationDamperComponentDefinition  (0x3C55009Bu)
// SharedTypes::v1_26_20::VibrationListenerComponentDefinition  (0x6D6FBEDCu)
// SharedTypes::v1_26_30::ApplyKnockbackRulesComponentDefinition  (0x35544D75u)
// SharedTypes::v1_26_30::ApplyKnockbackRulesComponentDefinition::ApplyKnockbackRulesPreset  (0x4498C856u)
// SharedTypes::v1_26_30::ApplyKnockbackRulesComponentDefinition::ApplyKnockbackRulesPreset>>>  (0x97D74A24u)
// SharedTypes::v1_26_30::BiomeComponents  (0x463F143Bu)
// SharedTypes::v1_26_30::Brain::MemorySensors::FindNearestAttackableEntityComponentDefinition  (0x10570C79u)
// SharedTypes::v1_26_30::Brain::MemorySensors::FindNearestBlockComponentDefinition  (0xA8FDAB4Fu)
// SharedTypes::v1_26_30::Brain::MemorySensors::HurtByComponentDefinition  (0x7517418Bu)
// SharedTypes::v1_26_30::Brain::MemorySensors::InRangeOfBlockComponentDefinition  (0xF9D247A1u)
// SharedTypes::v1_26_30::ItemComponents  (0xBD9AB00Eu)
// SharedTypes::v1_26_30::ItemCustomComponent  (0x1A42054Cu)
// SharedTypes::v1_26_30::ItemDeprecatedComponentData  (0x4463AA8Eu)
// SharedTypes::v1_26_30::PushableByEntityComponentDefinition  (0x3CE55B8Fu)
// SharedTypes::v1_26_30::SurfaceBuilderBiomeJsonComponent  (0x54699842u)
// SharedTypes::v1_26_30::UseModifiersItemComponent  (0xE2462B50u)
// SharedTypes::v1_26_30::UseModifiersItemComponent::StartUsing  (0x2ACEAAA4u)
// SharedTypes::v1_26_40::AdmireItemComponentDefinition  (0xED03E6DBu)
// SharedTypes::v1_26_40::BucketableComponentDefinition  (0xABA66E26u)
// SharedTypes::v1_26_40::DynamicJumpControlComponentDefinition  (0xA58B4CB6u)
// SharedTypes::v1_26_40::HideComponentDefinition  (0x1BD6E274u)
// SharedTypes::v1_26_40::JumpControlComponentDefinition  (0xACB2AF4Bu)
// SharedTypes::v1_26_40::ManagedWanderingTraderComponentDefinition  (0x76ED6044u)
// SharedTypes::v1_26_40::OpenDoorAnnotationComponentDefinition  (0xAFDB6513u)
// SharedTypes::v1_26_40::PersistentComponentDefinition  (0x3EE69D73u)
// SharedTypes::v1_26_40::PushableByEntityComponentDefinition  (0x8AC1AA6Au)
// SharedTypes::v1_26_40::TradeResupplyComponentDefinition  (0x5BFD3E14u)
// SharedTypes::v1_26_40::TrustComponentDefinition  (0x20AABC12u)
// SharedTypes::v1_26_50::AngerLevelComponentDefinition  (0x3AD739D2u)
// SharedTypes::v1_26_50::BarterComponentDefinition  (0x437B58E7u)
// SharedTypes::v1_26_50::BlockMovementSlowdownImmunityComponentDefinition  (0xF40BB550u)
// SharedTypes::v1_26_50::BossComponentDefinition  (0x623C7AE8u)
// SharedTypes::v1_26_50::CanStandOnPowderSnowComponentDefinition  (0x72139638u)
// SharedTypes::v1_26_50::CollisionBoxComponentDefinition  (0x2F065860u)
// SharedTypes::v1_26_50::DamageOverTimeComponentDefinition  (0xAE868499u)
// SharedTypes::v1_26_50::DimensionDefinition::Components  (0xF54CA164u)
// SharedTypes::v1_26_50::ExhaustionComponentDefinition  (0xDE3DBFB7u)
// SharedTypes::v1_26_50::FlockingComponentDefinition  (0xE46D0A16u)
// SharedTypes::v1_26_50::FreezingImmuneComponentDefinition  (0xB8D4A0B8u)
// SharedTypes::v1_26_50::FreezingVulnerableComponentDefinition  (0xE675FDDFu)
// SharedTypes::v1_26_50::GameEventMovementTrackingComponentDefinition  (0x3C2BD167u)
// SharedTypes::v1_26_50::GrowsCropComponentDefinition  (0x78699F53u)
// SharedTypes::v1_26_50::HomeComponentDefinition  (0x7166FFA6u)
// SharedTypes::v1_26_50::HomeComponentDefinition::RestrictionType  (0x5656E044u)
// SharedTypes::v1_26_50::InsomniaComponentDefinition  (0xD13C0A83u)
// SharedTypes::v1_26_50::InstantDespawnComponentDefinition  (0x916B81F4u)
// SharedTypes::v1_26_50::InteractComponentDefinition  (0x7BD3D859u)
// SharedTypes::v1_26_50::LegacyTradeableComponentDefinition  (0xA35A0EB4u)
// SharedTypes::v1_26_50::MountTamingComponentDefinition  (0x76B7E464u)
// SharedTypes::v1_26_50::MountTamingComponentDefinition::FeedItem  (0x15856193u)
// SharedTypes::v1_26_50::MountTamingComponentDefinition::RejectItem  (0x72CE8534u)
// SharedTypes::v1_26_50::PhysicsComponentDefinition  (0x35438DFEu)
// SharedTypes::v1_26_50::PreferredPathComponentDefinition  (0xF67D3EAFu)
// SharedTypes::v1_26_50::PreferredPathComponentDefinition::BlockSet  (0xBA582810u)
// SharedTypes::v1_26_50::ProjectileComponentDefinition  (0x5C57A6D6u)
// SharedTypes::v1_26_50::ProjectileComponentDefinition::ProjectileAnchor  (0xF4339DB0u)
// SharedTypes::v1_26_50::ProjectileComponentDefinition::ShouldBounce  (0x0965C025u)
// SharedTypes::v1_26_50::UsesLegacyAmbientSoundsComponentDefinition  (0x0691EA9Eu)
// ShooterItemComponent::DrawDuration  (0xEFE844A5u)
// ShooterItemComponent::ShooterAmmunitionEntry  (0xE922970Au)
// ShooterItemComponentLegacyFactoryData::ShooterAmmunitionEntry  (0x4BDF08F7u)
// std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DiggerItemComponent::BlockInfo>>>  (0x902A3443u)
// std::allocator<BlockCollisionBoxComponentDescriptor::BlockCollisionBoxProxy>  (0x194D60CFu)
// std::allocator<DiggerItemComponent::BlockInfo>  (0x40BD4396u)
// std::allocator<SharedTypes::v1_20_50::DiggerItemComponent::BlockInfo>  (0xAECA685Eu)
// std::allocator<SharedTypes::v1_20_50::RepairableItemComponent::RepairItemEntry>  (0x1394F662u)
// std::allocator<SharedTypes::v1_20_50::ShooterItemComponent::Ammunition>  (0x70E572F6u)
// std::allocator<SharedTypes::v1_21_130::AddRiderComponentDefinition::RiderData>  (0x085E1946u)
// std::allocator<SharedTypes::v1_21_80::ReplaceBiomesBiomeJsonComponent::BiomeReplacement>  (0x9C9BD723u)
// std::allocator<SharedTypes::v1_26_0::ReplaceBiomesBiomeJsonComponent::BiomeReplacement>  (0x91B8F4A8u)
// std::allocator<SharedTypes::v1_26_50::MountTamingComponentDefinition::FeedItem>  (0xB5E7FB6Bu)
// std::allocator<SharedTypes::v1_26_50::MountTamingComponentDefinition::RejectItem>  (0x3A9DDEBAu)
// std::allocator<SharedTypes::v1_26_50::PreferredPathComponentDefinition::BlockSet>  (0x3F4CFE5Eu)
// std::allocator<ShooterItemComponent::ShooterAmmunitionEntry>  (0x01069130u)
// std::allocator<ShooterItemComponentLegacyFactoryData::ShooterAmmunitionEntry>  (0x01232137u)
// std::basic_string<char>, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x12D27570u)
// std::optional<AllowOffHandItemComponent>  (0xA57B24B5u)
// std::optional<CanDestroyInCreativeItemComponent>  (0xB61555F0u)
// std::optional<ChargeableItemComponentLegacyFactoryData>  (0x225F6F23u)
// std::optional<CooldownItemComponent>  (0xB703E2F3u)
// std::optional<DamageItemComponent>  (0xDBF9B86Fu)
// std::optional<DiggerItemComponentLegacyFactoryData>  (0x5964ED45u)
// std::optional<DisplayNameItemComponent>  (0xD8454203u)
// std::optional<DurabilityItemComponent>  (0xB481D809u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentBoundingBoxLimit>  (0xB6B83260u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentBoundingBoxOptions>  (0xB01F6D4Bu)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentClipboardOptions>  (0xC8FBB06Cu)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentEntityOptions>  (0xAFEB65EDu)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentGizmoOptions>  (0x46BBA658u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentGridOptions>  (0x9A316946u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentGuideSensorOptions>  (0x832260B4u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentRenderPlaneOptions>  (0x6654D840u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentRenderPrimOptions>  (0x4D3743DEu)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentSplineOptions>  (0xD6E618E3u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentTextOptions>  (0xB7FF8D65u)
// std::optional<Editor::ScriptModule::ScriptWidgetComponentVolumeOutlineOptions>  (0x8356BD3Eu)
// std::optional<EnchantableItemComponent>  (0xC883461Fu)
// std::optional<EntityPlacerItemComponentLegacyFactoryData>  (0x636A02A3u)
// std::optional<FoodItemComponentData_v1_20_30>  (0x93A842C7u)
// std::optional<FuelItemComponent>  (0x0DFB9EB2u)
// std::optional<GlintItemComponent>  (0x208A8E02u)
// std::optional<HandEquippedItemComponent>  (0x55492842u)
// std::optional<HoverTextColorItemComponent>  (0xDA16B98Au)
// std::optional<IconItemComponentLegacyFactoryData>  (0xB06C58CCu)
// std::optional<InteractButtonItemComponent>  (0xC52C8FE8u)
// std::optional<LiquidClippedItemComponent>  (0xC3C0C18Du)
// std::optional<MaxStackSizeItemComponent>  (0x4B0CE5CDu)
// std::optional<OnUseItemComponent>  (0x686000B2u)
// std::optional<OnUseOnItemComponentLegacyFactoryData>  (0x0ABD20B8u)
// std::optional<PlanterItemComponentLegacyFactoryData>  (0xA9DDC235u)
// std::optional<ProjectileItemComponent>  (0xF20C1689u)
// std::optional<RecordItemComponent>  (0x59F971EFu)
// std::optional<RenderOffsetsItemComponent>  (0x2116A80Eu)
// std::optional<RepairableItemComponent>  (0x67AC68EBu)
// std::optional<SharedTypes::Legacy::OnCompleteTriggerItemComponent>  (0x5D1BBDEFu)
// std::optional<SharedTypes::Legacy::OnConsumeTriggerItemComponent>  (0xF145A990u)
// std::optional<SharedTypes::Legacy::OnHitActorTriggerItemComponent>  (0x43398114u)
// std::optional<SharedTypes::Legacy::OnHitBlockTriggerItemComponent>  (0x36565908u)
// std::optional<SharedTypes::Legacy::OnHurtActorTriggerItemComponent>  (0x84C43C70u)
// std::optional<SharedTypes::Legacy::OnUseOnTriggerItemComponent>  (0xE9EDDF6Cu)
// std::optional<SharedTypes::Legacy::OnUseTriggerItemComponent>  (0x74A5AAC3u)
// std::optional<SharedTypes::Legacy::RenderOffsetsItemComponent>  (0xBBEDDBF1u)
// std::optional<SharedTypes::v1_20_50::AllowOffHandItemComponent>  (0x15E4314Fu)
// std::optional<SharedTypes::v1_20_50::CanDestroyInCreativeItemComponent>  (0x89A09996u)
// std::optional<SharedTypes::v1_20_50::CooldownItemComponent>  (0xD8C6A58Du)
// std::optional<SharedTypes::v1_20_50::DamageItemComponent>  (0xE2FA6E6Du)
// std::optional<SharedTypes::v1_20_50::DiggerItemComponent>  (0xCEE6AE5Au)
// std::optional<SharedTypes::v1_20_50::DisplayNameItemComponent>  (0xCA520FE1u)
// std::optional<SharedTypes::v1_20_50::DurabilityItemComponent>  (0x6D2E721Bu)
// std::optional<SharedTypes::v1_20_50::EnchantableItemComponent>  (0xA902C17Du)
// std::optional<SharedTypes::v1_20_50::EntityPlacerItemComponent>  (0xB2737364u)
// std::optional<SharedTypes::v1_20_50::FoodItemComponent>  (0xA12EF010u)
// std::optional<SharedTypes::v1_20_50::FuelItemComponent>  (0xD4CC3E70u)
// std::optional<SharedTypes::v1_20_50::GlintItemComponent>  (0x12722C20u)
// std::optional<SharedTypes::v1_20_50::HandEquippedItemComponent>  (0x42684B58u)
// std::optional<SharedTypes::v1_20_50::HoverTextColorItemComponent>  (0x25063958u)
// std::optional<SharedTypes::v1_20_50::IconItemComponent>  (0x4F1B3A1Du)
// std::optional<SharedTypes::v1_20_50::InteractButtonItemComponent>  (0xCD257CC2u)
// std::optional<SharedTypes::v1_20_50::LiquidClippedItemComponent>  (0x28F91A1Fu)
// std::optional<SharedTypes::v1_20_50::MaxStackSizeItemComponent>  (0x0244BEB3u)
// std::optional<SharedTypes::v1_20_50::PlanterItemComponent>  (0x0AEC8942u)
// std::optional<SharedTypes::v1_20_50::ProjectileItemComponent>  (0x2BE66A8Bu)
// std::optional<SharedTypes::v1_20_50::RecordItemComponent>  (0xDE540009u)
// std::optional<SharedTypes::v1_20_50::RepairableItemComponent>  (0x297E8F79u)
// std::optional<SharedTypes::v1_20_50::ShooterItemComponent>  (0x15131080u)
// std::optional<SharedTypes::v1_20_50::ShouldDespawnItemComponent>  (0x613DBA0Bu)
// std::optional<SharedTypes::v1_20_50::StackedByDataItemComponent>  (0x615FCC24u)
// std::optional<SharedTypes::v1_20_50::TagsItemComponent>  (0xE673FCB5u)
// std::optional<SharedTypes::v1_20_50::ThrowableItemComponent>  (0xE2EB6C54u)
// std::optional<SharedTypes::v1_20_50::UseAnimationItemComponent>  (0xCFC0D747u)
// std::optional<SharedTypes::v1_20_50::UseModifiersItemComponent>  (0x3894A4CFu)
// std::optional<SharedTypes::v1_20_50::WearableItemComponent>  (0xF003BBB3u)
// std::optional<SharedTypes::v1_20_60::IconItemComponent>  (0x16DDAC5Au)
// std::optional<SharedTypes::v1_20_60::MountainParametersBiomeJsonComponent::SteepMaterial>  (0x29B07191u)
// std::optional<SharedTypes::v1_20_60::OverworldHeightBiomeJsonComponent::NoiseType>  (0x8715C041u)
// std::optional<SharedTypes::v1_20_80::CustomComponentsItemComponent>  (0x375228EAu)
// std::optional<SharedTypes::v1_21_10::DamageAbsorptionItemComponent>  (0x44663549u)
// std::optional<SharedTypes::v1_21_10::DurabilitySensorItemComponent>  (0x5DB470A0u)
// std::optional<SharedTypes::v1_21_30::BundleInteractionItemComponent>  (0x110F83C5u)
// std::optional<SharedTypes::v1_21_30::DyeableItemComponent>  (0x3DC50513u)
// std::optional<SharedTypes::v1_21_30::RarityItemComponent>  (0x4F636BCCu)
// std::optional<SharedTypes::v1_21_30::StorageItemComponent>  (0x2D397794u)
// std::optional<SharedTypes::v1_21_40::PlanterItemComponent>  (0x76109E0Au)
// std::optional<SharedTypes::v1_21_50::CompostableItemComponent>  (0x933ACB3Cu)
// std::optional<SharedTypes::v1_21_60::CustomComponentsItemComponent>  (0x7CED2929u)
// std::optional<SharedTypes::v1_21_60::StorageItemComponent>  (0x81FA9B1Bu)
// std::optional<SharedTypes::v1_21_60::StorageWeightLimitItemComponent>  (0x22C78BBAu)
// std::optional<SharedTypes::v1_21_60::StorageWeightModifierItemComponent>  (0xD66B1876u)
// std::optional<SharedTypes::v1_21_80::IconItemComponent>  (0x5DBD6C91u)
// std::optional<SharedTypes::v1_21_90::FireResistantItemComponent>  (0x88AF2B1Cu)
// std::optional<SharedTypes::v1_21_90::KineticWeaponItemComponent>  (0x3DE278A8u)
// std::optional<SharedTypes::v1_21_90::PiercingWeaponItemComponent>  (0x78446D3Eu)
// std::optional<SharedTypes::v1_21_90::SwingDurationItemComponent>  (0x4A4CE929u)
// std::optional<SharedTypes::v1_21_90::SwingSoundsItemComponent>  (0x376FEE61u)
// std::optional<SharedTypes::v1_21_90::WearableItemComponent>  (0x57E14FC2u)
// std::optional<SharedTypes::v1_26_0::DamageItemComponent>  (0xB3A88430u)
// std::optional<SharedTypes::v1_26_0::PlanterItemComponent>  (0x2E4DF36Du)
// std::optional<SharedTypes::v1_26_20::BlockDefinition::BlockEntityComponent::ContainerData>  (0x9F0D4BA5u)
// std::optional<ShooterItemComponentLegacyFactoryData>  (0x09F83F0Fu)
// std::optional<ShouldDespawnItemComponent>  (0x101FC6B9u)
// std::optional<StackedByDataItemComponent>  (0xF5F2EBF6u)
// std::optional<ThrowableItemComponentLegacyFactoryData>  (0x915715D3u)
// std::optional<UseAnimationItemComponent>  (0xA229F6B5u)
// std::optional<UseModifiersItemComponentLegacyFactoryData>  (0x42B4DADAu)
// std::optional<WeaponItemComponent>  (0x411D8FC2u)
// std::optional<WearableItemComponentLegacyFactoryData>  (0xDA672596u)
// std::shared_ptr<AllowOffHandItemComponent>  (0x46687045u)
// std::shared_ptr<ArmorItemComponent>  (0x38BBFC19u)
// std::shared_ptr<BlockCustomComponentsComponentDescription>  (0x19D0ED93u)
// std::shared_ptr<BlockEntityFallOnConfigurationComponentDescription>  (0xFED90C51u)
// std::shared_ptr<BlockLootComponentDescription>  (0x033E8C0Cu)
// std::shared_ptr<BlockPrecipitationInteractionsComponentDescription>  (0x8790F782u)
// std::shared_ptr<BlockTickConfigurationComponentDescription>  (0x0EBE6027u)
// std::shared_ptr<BundleInteractionItemComponent>  (0x07A8330Au)
// std::shared_ptr<CanDestroyInCreativeItemComponent>  (0x1FD8F600u)
// std::shared_ptr<ChargeableItemComponentLegacyFactoryData>  (0xEA7EF973u)
// std::shared_ptr<CompostableItemComponent>  (0x61B04B15u)
// std::shared_ptr<CooldownItemComponent>  (0x516200C3u)
// std::shared_ptr<DamageItemComponent>  (0x3F1FA85Fu)
// std::shared_ptr<DiggerItemComponentLegacyFactoryData>  (0x04D4BF15u)
// std::shared_ptr<DisplayNameItemComponent>  (0x01BA4773u)
// std::shared_ptr<DurabilityItemComponent>  (0x98898FF9u)
// std::shared_ptr<DyeableItemComponent>  (0xCE47AFE4u)
// std::shared_ptr<EnchantableItemComponent>  (0x6F1BC9CFu)
// std::shared_ptr<EntityPlacerItemComponentLegacyFactoryData>  (0x4801C073u)
// std::shared_ptr<FireResistantItemComponent>  (0xEC99C755u)
// std::shared_ptr<FoodItemComponentLegacyFactoryData>  (0xF711E08Fu)
// std::shared_ptr<FuelItemComponent>  (0x5FFA5CC2u)
// std::shared_ptr<GlintItemComponent>  (0xACD950F2u)
// std::shared_ptr<HandEquippedItemComponent>  (0xADC15A32u)
// std::shared_ptr<HoverTextColorItemComponent>  (0xA992D97Au)
// std::shared_ptr<IconItemComponentLegacyFactoryData>  (0xF4DBDFFCu)
// std::shared_ptr<InteractButtonItemComponent>  (0xF8EB2BD8u)
// std::shared_ptr<KineticWeaponItemComponent>  (0x6CCD5825u)
// std::shared_ptr<LiquidClippedItemComponent>  (0x1E099D9Du)
// std::shared_ptr<MaxStackSizeItemComponent>  (0x812B3A5Du)
// std::shared_ptr<OnUseItemComponent>  (0x422F1F02u)
// std::shared_ptr<OnUseOnItemComponentLegacyFactoryData>  (0x5C85FFC8u)
// std::shared_ptr<PiercingWeaponItemComponent>  (0xC0CEBEC5u)
// std::shared_ptr<PlanterItemComponentLegacyFactoryData>  (0xCC07C825u)
// std::shared_ptr<ProjectileItemComponent>  (0xFB3823D9u)
// std::shared_ptr<RarityItemComponent>  (0x443354DDu)
// std::shared_ptr<RecordItemComponent>  (0x91E16CDFu)
// std::shared_ptr<RenderOffsetsItemComponent>  (0x3681B8BEu)
// std::shared_ptr<RepairableItemComponent>  (0xDCE6D1FBu)
// std::shared_ptr<SharedTypes::v1_21_100::GrassAppearanceClientBiomeJsonComponent>  (0xA6B75F33u)
// std::shared_ptr<SharedTypes::v1_21_110::MusicClientBiomeJsonComponent>  (0x7AE13933u)
// std::shared_ptr<SharedTypes::v1_21_110::PrecipitationClientBiomeJsonComponent>  (0x109225F3u)
// std::shared_ptr<SharedTypes::v1_21_120::AmbientSoundsClientBiomeJsonComponent>  (0xC3A62821u)
// std::shared_ptr<SharedTypes::v1_21_130::SkyboxIdentifierClientBiomeJsonComponent>  (0x08B61853u)
// std::shared_ptr<SharedTypes::v1_21_40::AmbientSoundsClientBiomeJsonComponent>  (0xB46D07F8u)
// std::shared_ptr<SharedTypes::v1_21_40::FogAppearanceClientBiomeJsonComponent>  (0xF90AEA82u)
// std::shared_ptr<SharedTypes::v1_21_40::FoliageAppearanceClientBiomeJsonComponent>  (0x853C6447u)
// std::shared_ptr<SharedTypes::v1_21_40::GrassAppearanceClientBiomeJsonComponent>  (0xD19E8BD4u)
// std::shared_ptr<SharedTypes::v1_21_40::MusicClientBiomeJsonComponent>  (0xD8CFB35Du)
// std::shared_ptr<SharedTypes::v1_21_40::SkyColorClientBiomeJsonComponent>  (0x132B2FC4u)
// std::shared_ptr<SharedTypes::v1_21_40::WaterAppearanceClientBiomeJsonComponent>  (0x23AF7AFBu)
// std::shared_ptr<SharedTypes::v1_21_70::AtmosphereIdentifierClientBiomeJsonComponent>  (0xC3CAFB84u)
// std::shared_ptr<SharedTypes::v1_21_70::ColorGradingIdentifierClientBiomeJsonComponent>  (0x3F671157u)
// std::shared_ptr<SharedTypes::v1_21_70::DryFoliageColorClientBiomeJsonComponent>  (0x828DA4B2u)
// std::shared_ptr<SharedTypes::v1_21_70::FoliageAppearanceClientBiomeJsonComponent>  (0xEA780274u)
// std::shared_ptr<SharedTypes::v1_21_70::LightingIdentifierClientBiomeJsonComponent>  (0x4CC18AA0u)
// std::shared_ptr<SharedTypes::v1_21_70::WaterIdentifierClientBiomeJsonComponent>  (0x38535993u)
// std::shared_ptr<SharedTypes::v1_21_80::MusicClientBiomeJsonComponent>  (0xC38CE079u)
// std::shared_ptr<ShooterItemComponentLegacyFactoryData>  (0x04F85FFFu)
// std::shared_ptr<ShouldDespawnItemComponent>  (0x58714D29u)
// std::shared_ptr<StackedByDataItemComponent>  (0x2145E086u)
// std::shared_ptr<StorageItemComponent>  (0x0295767Fu)
// std::shared_ptr<StorageWeightLimitItemComponent>  (0x0BC08ACEu)
// std::shared_ptr<StorageWeightModifierItemComponent>  (0x12F2E4F2u)
// std::shared_ptr<SwingDurationItemComponent>  (0xC2E8BA84u)
// std::shared_ptr<SwingSoundsItemComponent>  (0xF33068C0u)
// std::shared_ptr<TagsItemComponent>  (0x26F12503u)
// std::shared_ptr<ThrowableItemComponentLegacyFactoryData>  (0x18F7A383u)
// std::shared_ptr<UseAnimationItemComponent>  (0x56886445u)
// std::shared_ptr<UseModifiersItemComponentLegacyFactoryData>  (0x70B4294Au)
// std::shared_ptr<WeaponItemComponent>  (0xFA0396F2u)
// std::shared_ptr<WearableItemComponentLegacyFactoryData>  (0xC75D57C6u)
// std::unordered_map<std::basic_string<char>, BlockComponentFactory::ComponentMetadata>  (0x7BB6EBDCu)
// std::vector<BlockCollisionBoxComponentDescriptor::BlockCollisionBoxProxy>  (0x0490E341u)
// std::vector<DiggerItemComponent::BlockInfo>  (0x41B098C4u)
// std::vector<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>>  (0xD2DFB1DDu)
// std::vector<SharedTypes::v1_20_50::DiggerItemComponent::BlockInfo>  (0x098CB62Cu)
// std::vector<SharedTypes::v1_20_50::RepairableItemComponent::RepairItemEntry>  (0x47938944u)
// std::vector<SharedTypes::v1_20_50::ShooterItemComponent::Ammunition>  (0xDB5B9878u)
// std::vector<SharedTypes::v1_21_130::AddRiderComponentDefinition::RiderData>  (0xF7D60B3Cu)
// std::vector<SharedTypes::v1_21_80::ReplaceBiomesBiomeJsonComponent::BiomeReplacement>  (0x916D2675u)
// std::vector<SharedTypes::v1_26_0::ReplaceBiomesBiomeJsonComponent::BiomeReplacement>  (0xD2CC12DAu)
// std::vector<SharedTypes::v1_26_50::MountTamingComponentDefinition::FeedItem>  (0xEE78BCD9u)
// std::vector<SharedTypes::v1_26_50::MountTamingComponentDefinition::RejectItem>  (0x7E78A9D8u)
// std::vector<SharedTypes::v1_26_50::PreferredPathComponentDefinition::BlockSet>  (0xF9FBB3CCu)
// std::vector<ShooterItemComponent::ShooterAmmunitionEntry>  (0xAAC6CA1Au)
// std::vector<ShooterItemComponentLegacyFactoryData::ShooterAmmunitionEntry>  (0x9DB28C8Du)
// StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cuboid>  (0x08886F10u)
// StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cylinder>  (0xAB84C7DCu)
// StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Pyramid>  (0x4740BD3Au)
// StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockLiquidContainerComponentV010>  (0x6FB03055u)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentActorAfterEvent>  (0x6AB61C70u)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentOnPlaceAfterEvent>  (0xB56D59A3u)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentStepOffAfterEvent>  (0x0003365Eu)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentStepOnAfterEvent>  (0xC5424934u)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponentContainerV010>  (0x9BE875FEu)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponentContainerV010>>  (0x2EF15D40u)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemBlockDynamicPropertiesComponent>  (0xC12F336Du)
// StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentCompleteUseEvent>  (0xDBDEA1C7u)
// sult<std::optional<Vec3>, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0xC566E4C7u)
// t<void, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent, Scripting::Error>  (0xFFD95C48u)
// td::_Vector_val<std::_Simple_types<SharedTypes::v1_20_50::DiggerItemComponent::BlockInfo>>>  (0xA1728F30u)
// td::optional<SharedTypes::v1_20_60::MountainParametersBiomeJsonComponent::TopSlideSettings>  (0x1E17211Fu)
// td::vector<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>>  (0x9CD4D10Cu)
// terator<std::_Vector_val<std::_Simple_types<ShooterItemComponent::ShooterAmmunitionEntry>>>  (0x9DEC3E3Au)
// TickMobEffectsSystem::RemoveMobEffectsRequestComponent  (0x09EC29D9u)
// ting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockDynamicPropertiesComponent>  (0x7C8D2B76u)
// ting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockLavaContainerComponentV010>  (0x023F776Eu)
// ting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockSnowContainerComponentV010>  (0x4D0089D5u)
// ting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentConsumeEvent>  (0x474BD69Bu)
// ting::TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cylinder>  (0x590A25F1u)
// ting::TypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockLiquidContainerComponentV010>  (0xB5AC8804u)
// ting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentOnPlaceAfterEvent>  (0xF98F0AF6u)
// ting::TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentStepOffAfterEvent>  (0x4CA8F84Bu)
// ting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cone>  (0xE45A28A6u)
// ting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Disc>  (0x0D5A5ADCu)
// ting::WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Line>  (0x57C31C7Du)
// ting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPotionContainerComponentV010>  (0x2E348584u)
// ting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentHitEntityEvent>  (0x1181F85Eu)
// ting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptItemCustomComponentMineBlockEvent>  (0xC33E3C6Cu)
// ting::WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptPlayerInventoryComponentContainer>  (0x7F0076AAu)
// tional<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>>  (0x407C50C1u)
// tModule::ScriptWidgetComponentBase>>, Editor::ScriptModule::ScriptWidgetErrorInvalidObject>  (0x497BAA49u)
// tModuleMinecraft::ScriptItemCustomComponentReloadNewComponentError, Scripting::EngineError>  (0xBFE0ED11u)
// tor<SharedTypes::Legacy::ApplyKnockbackRulesComponentDefinition::ApplyKnockbackRulesPreset>  (0x1D1BC48Eu)
// tor_val<std::_Simple_types<ShooterItemComponentLegacyFactoryData::ShooterAmmunitionEntry>>>  (0xA90E5B82u)
// trongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Ellipsoid>  (0x62ACCB68u)
// trongTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockInventoryComponentContainerV010>>>  (0x9C09AC57u)
// type_list<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptActorComponent>>  (0xF8AF84FCu)
// type_list<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::ScriptItemComponent>>  (0xC29326CAu)
// TypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_WireframeMesh>  (0x84B2B6D8u)
// TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentEntityFallOnAfterEvent>  (0x8208A94Bu)
// TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerBreakAfterEvent>  (0xCCEB738Au)
// TypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerPlaceBeforeEvent>  (0xE12E7427u)
// Types::v1_20_60::OverworldGenerationRulesBiomeJsonComponent::WeightedTemperatureCategory>>>  (0xA6F32986u)
// Types::v1_20_60::SurfaceMaterialAdjustmentsBiomeJsonComponent::SurfaceMaterialAdjustment>>>  (0xF12DF59Fu)
// uleMinecraft::ScriptRGBA, Editor::ScriptModule::ScriptWidgetComponentErrorInvalidComponent>  (0x1DEE50CBu)
// UseModifiersItemComponent::StartUsing  (0xCDDCCF90u)
// v1_20_60::SurfaceMaterialAdjustmentsBiomeJsonComponent::SurfaceMaterialAdjustmentMaterials  (0x8831B4ACu)
// val<std::_Simple_types<SharedTypes::v1_26_50::MountTamingComponentDefinition::RejectItem>>>  (0x09C388E9u)
// val<std::_Simple_types<SharedTypes::v1_26_50::PreferredPathComponentDefinition::BlockSet>>>  (0xEF437025u)
// VanillaCamera::CameraBobComponent  (0xC7B5D956u)
// VanillaCamera::CameraComfortMoveVRComponent  (0xBB08DAB0u)
// VanillaCamera::CameraPortalDistortionComponent  (0x2676E4F4u)
// VanillaCamera::CameraSleepVignetteComponent  (0x5844CE60u)
// VanillaCamera::CameraVehicleRotationComponent  (0xD7DB5F55u)
// VanillaCamera::UpdatePlayerFromCameraComponent  (0x0E49CF3Bu)
// VanillaSystems::ActorAdapterComponent  (0x63CF1B21u)
// VanillaSystems::BlockSourceFactoryAdapterComponent  (0xCA3EE50Eu)
// VanillaSystems::VanillaSystemsEventingComponent  (0xBC042BA4u)
// vector<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>>  (0x1F8E5050u)
// vector<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>>  (0xD57BE6D9u)
// Vector_const_iterator<std::_Vector_val<std::_Simple_types<DiggerItemComponent::BlockInfo>>>  (0x31025E35u)
// WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Cylinder>  (0x52F3FB8Du)
// WeakTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentRenderPrimType_Ellipsoid>  (0xD7C0EE7Au)
// WeakTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockLiquidContainerComponentV010>  (0x60C04060u)
// WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentOnPlaceAfterEvent>  (0xD3BF30E2u)
// WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentRedstoneUpdateEvent>  (0x403366E9u)
// WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentStepOffAfterEvent>  (0xFC1E309Fu)
// WeakTypedObjectHandle<ScriptModuleMinecraft::ScriptBlockPrecipitationInteractionsComponent>  (0xC2F657CDu)
// WidgetComponentErrorInvalidComponent, Editor::ScriptModule::ScriptWidgetErrorInvalidObject>  (0x03EE18D3u)
// ypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>, std::basic_string<char>>  (0xC5EECC68u)
// ypedObjectHandle<ScriptModuleMinecraft::ScriptBlockCustomComponentPlayerInteractAfterEvent>  (0x129651A1u)
// ypes<Scripting::StrongTypedObjectHandle<Editor::ScriptModule::ScriptWidgetComponentBase>>>>  (0x41C38082u)
// ypes<Scripting::StrongTypedObjectHandle<ScriptModuleMinecraft::BaseScriptBlockComponent>>>>  (0xAA6659AFu)
