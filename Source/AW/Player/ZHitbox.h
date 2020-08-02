// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZHitbox.generated.h"

UCLASS()
class AW_API AZHitbox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZHitbox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PreviousLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Active;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
