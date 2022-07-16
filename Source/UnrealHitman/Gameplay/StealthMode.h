// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NPC/Awareness/AwarenessUtility.h"
#include "NPC/Guards/GuardUtility.h"
#include "UnrealHitman/Utilities/TagUtility.h"
#include "StealthMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API AStealthMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Utilities")
	UTagUtility* TagUtility;
	
	UPROPERTY(EditDefaultsOnly, Category="Utilities")
	UAwarenessUtility* AwarenessUtility;

	UPROPERTY(EditDefaultsOnly, Category="Utilities")
	UGuardUtility* GuardUtility;
	
};
