// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurityComponent.h"

USecurityComponent::USecurityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USecurityComponent::BeginPlay()
{
	Super::BeginPlay();

	// SecurityLevel = 0;
}

int USecurityComponent::GetSecurityLevel()
{
	return SecurityLevel;
}

bool USecurityComponent::IsTrespassing()
{
	return SecurityLevel < VolumeLevel;
}

void USecurityComponent::EnterSecurityVolume(ASecurityVolume* SecurityVolume)
{
	VolumeLevel = SecurityVolume->GetSecurityLevel();

	UE_LOG(LogTemp, Display, TEXT("Security Level: %d \tVolume: %d"), SecurityLevel, VolumeLevel);
}
