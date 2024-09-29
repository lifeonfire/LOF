// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBaseClass.generated.h"

UCLASS()
class LOF_API AWeaponBaseClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Variable 

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	TSubclassOf < AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf < AActor> CasingClass;
};
