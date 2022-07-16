// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GuardCharacter.h"
#include "Perception/AIPerceptionTypes.h"
#include "UnrealHitman/Gameplay/NPC/NpcAi.h"
#include "UnrealHitman/Gameplay/Player/PlayerCharacter.h"
#include "UnrealHitman/Utilities/TagUtility.h"
#include "GuardAi.generated.h"

/**
 * 
 */
UCLASS()
class UNREALHITMAN_API AGuardAi : public ANpcAi
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Blackboard Keys")
	FName PlayerLocationKey = "PlayerLocation";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Perception")
	UAIPerceptionComponent* AiPerceptionComponent;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Character")
	AGuardCharacter* GuardCharacter;

private:
	UPROPERTY()
	UTagUtility* TagUtility;

	UPROPERTY()
	APlayerCharacter* PlayerCharacter;

	// Sight
	UPROPERTY(EditDefaultsOnly, Category="Sight")
	float SightCheckRate = 0.2f;

	UPROPERTY(EditDefaultsOnly, Category="Sight")
	UCurveFloat* AwarenessDistanceCurve;

	UPROPERTY(EditDefaultsOnly, Category="Sight")
	UCurveFloat* LostSightAwarenessCurve;

	bool CanSeePlayer = false;
	float PlayerDistance;
	float TimeSinceLastSight;

public:
	AGuardAi();
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UFUNCTION(BlueprintCallable, Category="Sight")
	void OnSightUpdated(AActor* Actor, FAIStimulus Stimulus);

	UFUNCTION(BlueprintCallable, Category="Hearing")
	void OnHearingUpdated(AActor* Actor, FAIStimulus Stimulus);

private:
	// Sight
	void UpdateSight(float DeltaSeconds);
};
