// Fill out your copyright notice in the Description page of Project Settings.


#include "ZHitbox.h"

// Sets default values
AZHitbox::AZHitbox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AZHitbox::BeginPlay()
{
	Super::BeginPlay();
	PreviousLocation = AZHitbox::GetActorLocation();
	
}

// Called every frame
void AZHitbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

