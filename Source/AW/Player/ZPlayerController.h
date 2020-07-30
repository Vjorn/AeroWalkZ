// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AW_API AZPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AZPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ForwardAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RightAxis;

protected:


public:
};
