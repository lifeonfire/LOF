// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Char_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class LOF_API AChar_PlayerState : public APlayerState
{
	GENERATED_BODY()
	

protected:

	virtual void OnRep_Score() override;

	UFUNCTION(BlueprintCallable , BlueprintNativeEvent)
	void OnScoreChange();

	UFUNCTION(BlueprintCallable)
	void SetPlayerScore(float Scores);
};
