// Fill out your copyright notice in the Description page of Project Settings.


#include "NpcAi.h"

DEFINE_LOG_CATEGORY(LogNpc);

ANpcAi::ANpcAi()
{
	AwarenessComponent = CreateDefaultSubobject<UAwarenessComponent>(TEXT("Awareness Component"));
}

void ANpcAi::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(BehaviorTree != nullptr)
	{
		RunBehaviorTree(BehaviorTree);
	}
	else
	{
		UE_LOG(LogNpc, Error, TEXT("No Bahvior Tree found on NpcAi"));
	}

	NpcCharacter = static_cast<ANpcCharacter*>(InPawn);
}
