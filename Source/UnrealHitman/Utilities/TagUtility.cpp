// Fill out your copyright notice in the Description page of Project Settings.


#include "TagUtility.h"

#include "UnrealHitman/Gameplay/StealthMode.h"

UTagUtility* UTagUtility::GetTagUtility()
{
	const AStealthMode* StealthMode = static_cast<AStealthMode*>(GEngine->GameViewport->GetWorld()->GetAuthGameMode());
	return StealthMode->TagUtility;
}
