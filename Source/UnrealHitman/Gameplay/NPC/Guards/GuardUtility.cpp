// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardUtility.h"

#include "UnrealHitman/Gameplay/StealthMode.h"

UGuardUtility* UGuardUtility::GetGuardUtility()
{
	const AStealthMode* StealthMode = static_cast<AStealthMode*>(GEngine->GameViewport->GetWorld()->GetAuthGameMode());
	return StealthMode->GuardUtility;
}
