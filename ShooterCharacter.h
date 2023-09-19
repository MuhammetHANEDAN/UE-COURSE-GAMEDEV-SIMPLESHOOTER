// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()

class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Fire();
private:
	//Character movement functions
	void Move(float AxisValue);
	//void LookUp(float AxisValue);
	void MoveRight(float AxisValue);

	//Components

	
	// Initialize

	UPROPERTY(EditDefaultsOnly, Category = "Initialize")
	TSubclassOf <AGun> GunClass;

	UPROPERTY(EditDefaultsOnly, Category = "Initialize")
	FName HideBoneName;

	UPROPERTY(EditDefaultsOnly, Category = "Initialize")
	FName WeaponSocketName;

	UPROPERTY(EditDefaultsOnly, Category = "Initialize")
	float MaxHealth = 100;

	UPROPERTY(VisibleAnyWhere, Category = "Initialize")
	float Health;

	UPROPERTY(EditDefaultsOnly, Category = "Initialize")
	UAnimMontage* DeathAnimation;

	
	// Items
	UPROPERTY(VisibleAnyWhere,Category="Items")
	AGun* Gun;
private:
	//Functions

	UFUNCTION()
	void AnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* DamageAtan, AActor* DamageCauser);
public:
	//Functions
	virtual void PerformDeath();
	float GetCurrentHealth() const;
};
