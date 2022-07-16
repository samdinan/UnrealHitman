// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardCharacter.h"

DEFINE_LOG_CATEGORY(LogGuard);

void AGuardCharacter::BeginPlay()
{
	Super::BeginPlay();

	PatrolIndex = 0;
}

FVector AGuardCharacter::GetPatrolPosition()
{
	if(PatrolPositions.Num() == 0)
	{
		return GetActorLocation();
	}
	
	return PatrolPositions[PatrolIndex]->GetActorLocation();
}

void AGuardCharacter::AdvancePatrol()
{
	if(PatrolPositions.Num() == 0)
	{
		return;
	}
	
	switch(PatrolLoopType)
	{
		case Loop:
			{
				PatrolIndex++;
				PatrolIndex %= PatrolPositions.Num();
			}
			break;
		
		case Yoyo:
			{
				if(PatrolIndex + PatrolIncrement >= PatrolPositions.Num() || PatrolIndex + PatrolIncrement < 0)
				{
					PatrolIncrement *= -1;
				}

				PatrolIndex += PatrolIncrement;
				PatrolIndex %= PatrolPositions.Num();
			}
			break;
		
		default:
			break;
	}
}
