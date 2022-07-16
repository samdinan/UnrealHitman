// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// UHealthComponent::UHealthComponent()
// {
// 	PrimaryComponentTick.bCanEverTick = false;
// }

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
}

int UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthComponent::GetNormalizedHealth()
{
	UE_LOG(LogTemp, Display, TEXT("Current: %d Max: %d"), CurrentHealth, MaxHealth);
	return static_cast<float>(CurrentHealth) / static_cast<float>(MaxHealth);
}

void UHealthComponent::Heal(const int Heal)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Heal, 0, MaxHealth);

	OnHealthUpdated.Broadcast();
}

void UHealthComponent::Damage(const int Damage)
{
	CurrentHealth -= Damage;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);

	OnHealthUpdated.Broadcast();
	
	if(CurrentHealth <= 0)
	{
		CurrentHealth = 0;
		OnDeath.Broadcast();
	}
}

