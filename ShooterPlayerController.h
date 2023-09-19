// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
private:
	UPROPERTY(EditAnyWhere,BlueprintReadWrite,meta=(AllowPrivateAccess="true"))
	float StartDelay = 5.f;
	FTimerHandle RestartTimer;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> RestartWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> CrosshairWidgetClass;
	
	UPROPERTY()
	UUserWidget* Crosshair;

};
