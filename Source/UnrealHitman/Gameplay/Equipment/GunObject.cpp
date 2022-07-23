// Fill out your copyright notice in the Description page of Project Settings.


#include "GunObject.h"

#include "UnrealHitman/Gameplay/Health/HealthComponent.h"

AGunObject::AGunObject()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGunObject::BeginPlay()
{
	Super::BeginPlay();
}

void AGunObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IsBetweenShots)
	{
		BetweenShotTimer -= DeltaTime;

		if(BetweenShotTimer <= 0)
		{
			IsBetweenShots = false;
		}
	}
}

void AGunObject::Fire_Implementation(FVector Origin, FVector Direction)
{
	DrawDebugLine(GetWorld(), Origin, Origin + Direction * Range, FColor::Green, false, 2.0f, 5.0f);

    FHitResult HitResult;
    if(GetWorld()->LineTraceSingleByChannel(HitResult, Origin, Direction * Range, ECC_Camera,
    	FCollisionQueryParams::DefaultQueryParam, FCollisionResponseParams::DefaultResponseParam))
    {
    	AActor* HitActor = HitResult.GetActor();
    	if(HitActor != nullptr)
    	{
    		UHealthComponent* HealthComponent = HitActor->FindComponentByClass<UHealthComponent>();

    		if(HealthComponent != nullptr)
    		{
    			HealthComponent->Damage(Damage);
    		}
    	}
    }

	OnFire();
}

bool AGunObject::IsReady()
{
	if(IsBetweenShots)
	{
		return false;
	}

	return true;
}

void AGunObject::OnFire_Implementation()
{
}

void AGunObject::OnHit_Implementation(FVector Point, FVector Normal)
{
}
