// Fill out your copyright notice in the Description page of Project Settings.


#include "Z_AIBaseCharacter.h"

// Sets default values
AZ_AIBaseCharacter::AZ_AIBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Team = 1;
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

