// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Perception/AISense_Sight.h"
#include "GuardUtility.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API UGuardUtility : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Line of Sight")
	float LosTime = 0.2f;

public:
	static UGuardUtility* GetGuardUtility();
	
};
