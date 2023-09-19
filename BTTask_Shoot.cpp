// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"
#include "Kismet/GameplayStatics.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr) return EBTNodeResult::Failed;
	APawn* ControlledPawn = AIController->GetPawn();
	AShooterCharacter* ControlledShooter = Cast < AShooterCharacter>(ControlledPawn);
	if (ControlledShooter)
	{
		AShooterCharacter* Target = Cast<AShooterCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
		if (Target && Target->GetCurrentHealth() > 0)
		{
			ControlledShooter->Fire();
			return EBTNodeResult::Succeeded;
		}
		else
			return EBTNodeResult::Succeeded;
		
	}
	return EBTNodeResult::Failed;
}