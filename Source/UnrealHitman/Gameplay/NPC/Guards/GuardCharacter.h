// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealHitman/Gameplay/NPC/NpcCharacter.h"
#include "GuardCharacter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGuard, Log, All);

UENUM()
enum EPatrolLoopTypes {
	None,
	Loop,
	Yoyo,
};

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API AGuardCharacter : public ANpcCharacter
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditInstanceOnly, Category="Patrol")
	TEnumAsByte<EPatrolLoopTypes> PatrolLoopType;
	
	UPROPERTY(EditInstanceOnly, Category="Patrol")
	TArray<AActor*> PatrolPositions;

private:
	int PatrolIndex = 0;
	int PatrolIncrement = 1;

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category="Patrol")
	FVector GetPatrolPosition();

	UFUNCTION(BlueprintCallable, Category="Patrol")
	void AdvancePatrol();
};
