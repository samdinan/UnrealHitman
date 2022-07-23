// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GunObject.h"
#include "SemiAutoGun.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API ASemiAutoGun : public AGunObject
{
	GENERATED_BODY()

private:
	bool HasTriggerReset;

public:
	ASemiAutoGun();

	virtual void Tick(float DeltaTime) override;

	virtual void PullTrigger(FVector Origin, FVector Direction) override;
	virtual void ReleaseTrigger() override;

	virtual bool IsReady() override;
	
};
