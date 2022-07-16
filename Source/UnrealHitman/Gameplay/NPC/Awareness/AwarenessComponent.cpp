// Fill out your copyright notice in the Description page of Project Settings.


#include "AwarenessComponent.h"

#include "Blueprint/UserWidget.h"

UAwarenessComponent::UAwarenessComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UAwarenessComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentAwareness = 0;
	IsActive = StartOnBegin;
}

void UAwarenessComponent::AddAwareness(float Value)
{
	if(!IsActive)
	{
		return;
	}
	
	CurrentAwareness += Value;

	if(CurrentAwareness > MaxAwareness)
	{
		CurrentAwareness = MaxAwareness;
	}
	else if(CurrentAwareness < 0)
	{
		CurrentAwareness = 0;
	}
	
	OnAwarenessUpdated.Broadcast();
}

float UAwarenessComponent::GetNormalizedAwareness() const
{	
	return CurrentAwareness / MaxAwareness;
}

void UAwarenessComponent::StartAwareness()
{
	IsActive = true;
}

void UAwarenessComponent::PauseAwareness()
{
	IsActive = false;
}

void UAwarenessComponent::StopAwareness()
{
	IsActive = false;

	CurrentAwareness = 0;
}

