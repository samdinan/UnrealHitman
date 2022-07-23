// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcCharacter.h"

ANpcCharacter::ANpcCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

UHealthComponent* ANpcCharacter::GetHealth()
{
	return HealthComponent;
}

TEnumAsByte<EStatus> ANpcCharacter::GetStatus()
{
	return Status;
}

void ANpcCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

