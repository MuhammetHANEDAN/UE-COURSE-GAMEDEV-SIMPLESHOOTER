// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "GameFramework/PlayerController.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled) 
{
	Super::PawnKilled(PawnKilled);
	UE_LOG(LogTemp, Warning, TEXT("Pawnkilled in killemmall game mode"));
	APlayerController* PlayerController = Cast <APlayerController>(PawnKilled->GetController());
	if (PlayerController)
	{
		PlayerController->GameHasEnded(nullptr, false);

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Continued"));
		// 
	}
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{	
	for (AController* Controller : TActorRange <AController>(GetWorld()))
	{

	}
}