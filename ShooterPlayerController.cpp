// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include"TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	Crosshair = CreateWidget(this, CrosshairWidgetClass);
	if (Crosshair)
	{
		Crosshair->AddToViewport();
	}
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if (RestartWidgetClass)
	{
		if (Crosshair)
		{
			Crosshair->RemoveFromParent();
		}
		UUserWidget* RestartWidget = CreateWidget(this, RestartWidgetClass);
		RestartWidget->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("restartwidgetclass added to viewport"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("There is a no restartwidgetclass"));
	GetWorldTimerManager().SetTimer(RestartTimer, this,&APlayerController::RestartLevel, StartDelay);

}