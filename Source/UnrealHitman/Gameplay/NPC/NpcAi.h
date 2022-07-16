// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NpcCharacter.h"
#include "Awareness/AwarenessComponent.h"
#include "NpcAi.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNpc, Log, All);

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API ANpcAi : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="NPC AI")
	UBehaviorTree* BehaviorTree;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Awareness")
	UAwarenessComponent* AwarenessComponent;

	UPROPERTY(BlueprintReadOnly, Category="Npc Character")
	ANpcCharacter* NpcCharacter;
	
public:
	ANpcAi();

	virtual void OnPossess(APawn* InPawn) override;
	
};
