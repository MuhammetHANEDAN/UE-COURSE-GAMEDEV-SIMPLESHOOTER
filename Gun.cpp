// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root ");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh Component");
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::LineTraceForPullTrigger(FHitResult& OutHitResult, AController& OutOwnerController)
{
	APawn* OwnerPawn = Cast <APawn>(GetOwner());
	AController* OwnerController = OwnerPawn->GetController();

	if (OwnerController == nullptr) return false;
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	FVector End = Location + Rotation.Vector() * MaxRange;

	if (MuzzleFlash == nullptr) return false;
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, MuzzleFlashLocation);
	if (MuzzleSound)
	{
		UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, MuzzleFlashLocation);
	}
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return  GetWorld()->LineTraceSingleByChannel(HitResult, Location, End, ECC_GameTraceChannel1, Params);
}

void AGun::PullTrigger()
{
	FHitResult HitResult;
	AController* OwnerController = nullptr;
	if (LineTraceForPullTrigger(HitResult,*OwnerController)==false) return;
	FVector impact = HitResult.ImpactPoint;
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,impact,impact.Rotation(),false);
	if (ImpactSound)
	{
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, impact);
	}
	AActor* DamagedActor = HitResult.GetActor();
	if (DamagedActor)
	{
		UGameplayStatics::ApplyDamage(DamagedActor, Damage, OwnerController, this,UDamageType::StaticClass());
	}
}

