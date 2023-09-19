// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
private:
	APawn* Target;

	UPROPERTY(EditAnyWhere, Category = "0Initialize")
	UBehaviorTree* AIBehavior;

	UPROPERTY(EditAnyWhere, Category = "0Initialize")
	float AcceptanceRadius = 500;


public:
	// Functions
	
};
