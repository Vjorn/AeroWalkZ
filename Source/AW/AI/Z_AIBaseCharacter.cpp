// Fill out your copyright notice in the Description page of Project Settings.


#include "Z_AIBaseCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AZ_AIBaseCharacter::AZ_AIBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Input
	WalkThreshold = 0.1f;
	InputBuffer = -1;

	// Movement
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

	// Character Info
	Health = 1000.f;
	MaxHealth = 200.f;
}

// Called when the game starts or when spawned
void AZ_AIBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZ_AIBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AZ_AIBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AZ_AIBaseCharacter::CanDo(bool CanDo, bool BurstAndEnemyStep)
{
	bCanMove = CanDo;
	bCanAttack = CanDo;
	bAbleToJump = CanDo;
	bCanBurst = BurstAndEnemyStep;
	bCanEnemyStep = BurstAndEnemyStep;
}

void AZ_AIBaseCharacter::RestoreMovementDefaults(bool ZeroVelocity)
{
	if (ZeroVelocity) {
		GetCharacterMovement()->Velocity = FVector(0.f, 0.f, 0.f);
		GetCharacterMovement()->GravityScale = TargetGravity;
		GetCharacterMovement()->GroundFriction = TargetGroundFriction;
		GetCharacterMovement()->FallingLateralFriction = TargetAirFriction;
		FloatTime = 0.f;
	}
}

