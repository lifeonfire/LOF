// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_Character.h"

ABase_Character::ABase_Character()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABase_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABase_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABase_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABase_Character::ResetPlayer()
{
	Reset();
}

