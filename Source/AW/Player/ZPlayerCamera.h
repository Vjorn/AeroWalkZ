// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZPlayerCamera.generated.h"

UCLASS()
class AW_API AZPlayerCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZPlayerCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float UnlockInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LockOnInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LockOnArmLengthOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DefaultArmLength;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
