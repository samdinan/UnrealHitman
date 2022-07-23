// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "SecurityVolume.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API ASecurityVolume : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, Category="Security")
	int SecurityLevel = 0;

public:
	UFUNCTION(BlueprintCallable, Category="Security")
	int GetSecurityLevel();
	
};
