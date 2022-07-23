// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealHitman/Gameplay/Health/HealthComponent.h"
#include "NpcCharacter.generated.h"

UENUM()
enum EStatus {
	None,
	Alive,
	Dead
};

UCLASS()
class UNREALHITMAN_API ANpcCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Health")
	UHealthComponent* HealthComponent;

protected:
	UPROPERTY(BlueprintReadWrite, Category="Status")
	TEnumAsByte<EStatus> Status;
	
public:
	ANpcCharacter();

	UFUNCTION(BlueprintCallable, Category="Health")
	UHealthComponent* GetHealth();

	UFUNCTION(BlueprintCallable, Category="Health")
	TEnumAsByte<EStatus> GetStatus();
	
protected:
	virtual void BeginPlay() override;

};
