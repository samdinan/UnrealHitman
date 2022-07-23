// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SecurityVolume.h"
#include "Components/ActorComponent.h"
#include "SecurityComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALHITMAN_API USecurityComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Security")
	int SecurityLevel;

private:
	int VolumeLevel;

public:	
	USecurityComponent();

	int GetSecurityLevel();

	UFUNCTION(BlueprintCallable, Category="Security")
	bool IsTrespassing();

	void EnterSecurityVolume(ASecurityVolume* SecurityVolume);

protected:
	virtual void BeginPlay() override;
	
};
