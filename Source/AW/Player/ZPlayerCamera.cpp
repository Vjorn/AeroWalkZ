// Fill out your copyright notice in the Description page of Project Settings.


#include "ZPlayerCamera.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AZPlayerCamera::AZPlayerCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultArmLength = 650.f;
	LockOnArmLengthOffset = 500.f;
	LockOnInterpSpeed = 10.f;
	UnlockInterpSpeed = 5.f;
}

// Called when the game starts or when spawned
void AZPlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZPlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

