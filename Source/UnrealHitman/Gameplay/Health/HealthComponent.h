// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALHITMAN_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Health")
	int MaxHealth = 100;

private:
	int CurrentHealth;

protected:
	virtual void BeginPlay() override;

public:
	// UHealthComponent();

	UFUNCTION(BlueprintCallable, Category="Health")
	int GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetNormalizedHealth();
	
	UFUNCTION(BlueprintCallable, Category="Health")
	void Heal(int Heal);

	UFUNCTION(BlueprintCallable, Category="Health")
	void Damage(int Damage);

	UPROPERTY(BlueprintAssignable)
	FOnHealthUpdated OnHealthUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;
};
