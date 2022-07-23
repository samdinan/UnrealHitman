// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunObject.generated.h"

UENUM()
enum EGunType {
	Pistol,
	AssaultRifle,
	SMG,
	Sniper,
	Shotgun,
};

UENUM()
enum EReloadType {
	Magazine,
	Bullet,
};

UCLASS()
class UNREALHITMAN_API AGunObject : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Equipement Properties")
	FText EquipmentName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Equipement Properties")
	FText EquipmentDescription;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon Properties")
	int Damage = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gun Properties")
	TEnumAsByte<EGunType> GunType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gun Properties", meta=(ClampMin=0))
	float Range = 1000000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gun Properties", meta=(ClampMin=0))
	int RateOfFire = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gun Properties", meta=(ClampMin=0))
	int Magazine = 5;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gun Properties")
	TEnumAsByte<EReloadType> ReloadType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gun Properties", meta=(ClampMin=0))
	float ReloadTime = 1.0f;

private:
	bool IsTriggerPulled;
	
	bool IsBetweenShots;
	float BetweenShotTimer;

	bool HasResetTrigger;
	
public:
	AGunObject();
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Gun")
	virtual void PullTrigger(FVector Origin, FVector Direction) PURE_VIRTUAL(AGunObject::PullTrigger,);

	UFUNCTION(BlueprintCallable, Category="Gun")
	virtual void ReleaseTrigger() PURE_VIRTUAL(AGunObject::ReleaseTrigger,);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, Category="Gun")
	void Fire(FVector Origin, FVector Direction);
	
	virtual bool IsReady();

	// Usage events for Blueprint
	UFUNCTION(BlueprintNativeEvent, Category="Gun")
	void OnFire();

	UFUNCTION(BlueprintNativeEvent, Category="Gun")
	void OnHit(FVector Point, FVector Normal);
	
};
