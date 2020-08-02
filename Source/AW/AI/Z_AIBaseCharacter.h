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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	bool bInvincible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	int Team;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float HitstopTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
