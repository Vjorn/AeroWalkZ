// Fill out your copyright notice in the Description page of Project Settings.


#include "ZPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"




// Sets default values
AZPlayerCharacter::AZPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxAcceleration = 1000000.f;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 1200.f, 0.0f);
	GetCharacterMovement()->GravityScale = 18.f;
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.1f;
	GetCharacterMovement()->AirControlBoostMultiplier = 0.f;
	GetCharacterMovement()->MaxWalkSpeed = 1700.f;


	// Input
	WalkThreshold = 0.1f;
	RunThreshold = 0.8f;
	InputBuffer = -1;

	// Movement
	WalkSpeed = 0.1f;
	RunSpeed = 0.4f;
	FloatTime = 0.f;
	TargetGravity = 15.f;
	TargetGroundFriction = 8.f;
	TargetAirFriction = 0.f;

	// Action
	bCanMove = true;
	bCanAttack = true;
	bAbleToJump = true;
	bCanBurst = true;
	bCanEnemyStep = true;
	MeleeChargeLevel = -1;
	SpecialChargeLevel = -1;

	// Character Switch
	bActive = true;

	// Character Info
	Health = 1000.f;
	MaxHealth = 200.f;
	Meter = 200.f;
	MaxMeter = 1000.f;
	CharacterPlayRate = 1.f;
	Team = 0;
	bSuperChar = false;

	// Collision
	HitstopTime = 0.f;
}

// Called when the game starts or when spawned
void AZPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AZPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZPlayerCharacter::ResetJumpOptions()
{
	AirJumpsUsed = 0;
	AirDashesUsed = 0;
	AirTeleportsUsed = 0;
}

void AZPlayerCharacter::CanDo(bool CanDo, bool BurstAndEnemyStep)
{
	bCanMove = CanDo;
	bCanAttack = CanDo;
	bAbleToJump = CanDo;
	bCanBurst = BurstAndEnemyStep;
	bCanEnemyStep = BurstAndEnemyStep;
}

void AZPlayerCharacter::RestoreMovementDefaults(bool ZeroVelocity)
{
	if (ZeroVelocity) {
		GetCharacterMovement()->Velocity = FVector(0.f, 0.f, 0.f);
		GetCharacterMovement()->GravityScale = TargetGravity;
		GetCharacterMovement()->GroundFriction = TargetGroundFriction;
		GetCharacterMovement()->FallingLateralFriction = TargetAirFriction;
		FloatTime = 0.f;
	}
}

void AZPlayerCharacter::AddMeter(float InMeter)
{
	float A;
	float B;

	if (bSuperChar) {
		A = FMath::Clamp(InMeter, 0.f, MaxMeter);
	} 
	else {
		A = InMeter;
	}

	B = Meter + A;
	Meter = FMath::Clamp(B, 0.f, MaxMeter);
}

void AZPlayerCharacter::TickHitstop()
{
	if (HitstopTime > 0.f) {
		HitstopTime = FMath::Clamp(HitstopTime - UGameplayStatics::GetWorldDeltaSeconds(this), 0.f, HitstopTime);
		if (HitstopTime == 0.f) {
			CustomTimeDilation = CharacterPlayRate;
		}
		else {
			CustomTimeDilation = 0.f;
		}
	}
	else {
		if (CharacterPlayRate != CustomTimeDilation) {
			CustomTimeDilation = CharacterPlayRate;
		}
	}
}