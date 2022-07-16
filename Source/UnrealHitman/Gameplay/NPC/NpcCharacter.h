// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealHitman/Gameplay/Health/HealthComponent.h"
#include "NpcCharacter.generated.h"

UCLASS()
class UNREALHITMAN_API ANpcCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Health")
	UHealthComponent* HealthComponent;
	
public:
	ANpcCharacter();

	UFUNCTION(BlueprintCallable)
	UHealthComponent* GetHealth();

protected:
	virtual void BeginPlay() override;

};
