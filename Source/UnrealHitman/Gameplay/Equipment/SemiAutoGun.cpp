// Fill out your copyright notice in the Description page of Project Settings.


#include "SemiAutoGun.h"

ASemiAutoGun::ASemiAutoGun()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASemiAutoGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASemiAutoGun::PullTrigger(FVector Origin, FVector Direction)
{
	if(IsReady())
	{
		Fire(Origin, Direction);
	}

	HasTriggerReset = false;
}

void ASemiAutoGun::ReleaseTrigger()
{
	HasTriggerReset = true;
}

bool ASemiAutoGun::IsReady()
{
	if(HasTriggerReset)
	{
		return false;
	}
	
	return Super::IsReady();
}
