// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TagUtility.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API UTagUtility : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FName PlayerTag = "Player";

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FName NpcTag = "NPC";

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FName EnemyTag = "Enemy";

public:
	static UTagUtility* GetTagUtility();
};
