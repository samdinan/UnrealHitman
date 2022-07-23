// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAi.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"

AGuardAi::AGuardAi()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGuardAi::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	GuardCharacter = static_cast<AGuardCharacter*>(InPawn);
	TagUtility = UTagUtility::GetTagUtility();
	PlayerCharacter = static_cast<APlayerCharacter*>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AGuardAi::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateSight(DeltaSeconds);
}

void AGuardAi::OnSightUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if(Stimulus.WasSuccessfullySensed())
	{
		if(Actor->ActorHasTag(TagUtility->PlayerTag))
		{
			CanSeePlayer = true;
			PlayerCharacter = static_cast<APlayerCharacter*>(Actor);
		}
	}
	else
	{
		if(Actor->ActorHasTag(TagUtility->PlayerTag))
		{
			CanSeePlayer = false;
		}
	}
}

void AGuardAi::OnHearingUpdated(AActor* Actor, FAIStimulus Stimulus)
{
}

void AGuardAi::UpdateSight(float DeltaSeconds)
{
	if(CanSeePlayer && PlayerCharacter->GetStatus() != Legal)
	{
		const FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		
		PlayerDistance = FVector::Dist(PlayerLocation, GuardCharacter->GetActorLocation());
		const float AwarenessRate = AwarenessDistanceCurve->GetFloatValue(PlayerDistance);
		AwarenessComponent->AddAwareness(AwarenessRate * DeltaSeconds);

		GetBlackboardComponent()->SetValueAsVector(PlayerLocationKey, PlayerLocation);

		TimeSinceLastSight = 0;
	}
	else if(AwarenessComponent->GetNormalizedAwareness() > 0)
	{
		TimeSinceLastSight += DeltaSeconds;
		const float AwarenessRate = LostSightAwarenessCurve->GetFloatValue(TimeSinceLastSight);
		AwarenessComponent->AddAwareness(AwarenessRate * DeltaSeconds);
	}
}
