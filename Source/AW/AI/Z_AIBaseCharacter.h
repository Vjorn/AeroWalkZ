// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Z_AIBaseCharacter.generated.h"

UCLASS()
class AW_API AZ_AIBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZ_AIBaseCharacter();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	FVector2D InputVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	float WalkThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	int InputBuffer;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float FloatTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TargetGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TargetGroundFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TargetAirFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float JumpTimer;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bCanMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bCanAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bAbleToJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bCanBurst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bCanEnemyStep;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	int StateIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	int SubStateIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bGuarding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	float GuardTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bCombatAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bMeleeCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	bool bSpecialCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	int MeleeChargeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	int SpecialChargeLevel;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	bool bInvincible;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float HitstopTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	bool bPhaseThrough;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	bool bCollisionStop;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable)
	void CanDo(bool CanDo, bool BurstAndEnemyStep);

	UFUNCTION(BlueprintCallable)
	void RestoreMovementDefaults(bool ZeroVelocity);
};
