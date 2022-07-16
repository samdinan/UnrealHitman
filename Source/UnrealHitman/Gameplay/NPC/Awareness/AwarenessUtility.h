// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AwarenessUtility.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API UAwarenessUtility : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Awareness")
	float MaxAwareness = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category="Levels", meta=(ClampMin=0,ClampMax=1))
	float MaxUnawareAwarenessMod = 0.15f;
	
	UPROPERTY(EditDefaultsOnly, Category="Levels", meta=(ClampMin=0,ClampMax=1))
	float MaxInterestedAwarenessMod = 0.50f;

	UPROPERTY(EditDefaultsOnly, Category="Levels", meta=(ClampMin=0,ClampMax=1))
	float MaxInvestigatingAwarenessMod = 0.80f;
};

UENUM(BlueprintType)
enum EAwarenessLevel {
	None UMETA(DisplayName="None"),
	
	Unaware UMETA(DisplayName="Unaware"),
	Interested UMETA(DisplayName="Interested"),
	Investigating UMETA(DisplayName="Investigating"),
	Aware UMETA(DisplayName="Aware"),
};
