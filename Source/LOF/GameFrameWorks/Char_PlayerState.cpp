// Fill out your copyright notice in the Description page of Project Settings.


#include "Char_PlayerState.h"

void AChar_PlayerState::OnRep_Score()
{
	Super::OnRep_Score();

	OnScoreChange();


}

void AChar_PlayerState::OnScoreChange_Implementation()
{

}

void AChar_PlayerState::SetPlayerScore(float Scores)
{
	Score = Scores;

}
