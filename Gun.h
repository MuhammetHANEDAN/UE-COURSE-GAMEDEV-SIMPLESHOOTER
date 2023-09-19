// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//Functions
	bool LineTraceForPullTrigger(FHitResult & OutHitResult, AController & OutOwnerController);

private:
	//Components
	UPROPERTY(VisibleAnyWhere,Category="Components") // Root comp
	USceneComponent* Root;

	UPROPERTY(VisibleAnyWhere, Category = "Components") // For gun skeletal mesh
	USkeletalMeshComponent* Mesh;

	//Initialize
	
	UPROPERTY(EditDefaultsOnly, Category = "Initialize")
	FName MuzzleFlashLocation;
	
	UPROPERTY(EditAnyWhere,Category="Initialize")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnyWhere, Category = "Initialize")
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnyWhere, Category = "Initialize")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnyWhere, Category = "Initialize")
	USoundBase* ImpactSound;

	UPROPERTY(EditAnyWhere, Category = "Initialize")
	float MaxRange = 10000;

	UPROPERTY(EditAnyWhere, Category = "Initialize")
	float Damage = 10;

};
