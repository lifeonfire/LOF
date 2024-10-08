// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Base_Character.generated.h"

UCLASS()
class LOF_API ABase_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ABase_Character();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ResetPlayer();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
