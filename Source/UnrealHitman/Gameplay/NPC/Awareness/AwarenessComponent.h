// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/WidgetComponent.h"
#include "AwarenessComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAwarenessUpdate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALHITMAN_API UAwarenessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Awareness")
	bool StartOnBegin = true;

private:
	bool IsActive;
	
	UPROPERTY(EditDefaultsOnly, Category="Awareness")
	float MaxAwareness = 100.0f;
	
	float CurrentAwareness = 0;

public:	
	UAwarenessComponent();

	UFUNCTION(BlueprintCallable, Category="Awareness")
	void AddAwareness(float Value);

	UFUNCTION(BlueprintCallable, Category="Awareness")
	float GetNormalizedAwareness() const;

	UFUNCTION(BlueprintCallable, Category="Awareness")
	void StartAwareness();
	
	UFUNCTION(BlueprintCallable, Category="Awareness")
	void PauseAwareness();

	UFUNCTION(BlueprintCallable, Category="Awareness")
	void StopAwareness();
	
	UPROPERTY(BlueprintAssignable)
	FAwarenessUpdate OnAwarenessUpdated;

protected:
	virtual void BeginPlay() override;
};
