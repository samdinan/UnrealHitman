// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealHitman/Gameplay/Equipment/GunObject.h"
#include "PlayerCharacter.generated.h"

UENUM()
enum EPlayerStatus {
	Legal,
	Revealed,
	Trespassing,
};

UCLASS()
class UNREALHITMAN_API APlayerCharacter final : public ACharacter
{
	GENERATED_BODY()

//Variables
public:
	// Movement
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float WalkSpeed = 300.0f;

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, Category=Camera)
	float RegularBoomLength = 300.0f;

	UPROPERTY(EditDefaultsOnly, Category=Camera)
	float AimBoomLength = 125.0f;

	// Gun
	UPROPERTY(EditDefaultsOnly, Category="Gun")
	TSubclassOf<AGunObject> StartingGun;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Sockets")
	FName GunSocketName = "GunSocket";

protected:
	UPROPERTY(BlueprintReadWrite, Category="Gun")
	AGunObject* CurrentGun;

	UPROPERTY(EditDefaultsOnly, Category="Status")
	TEnumAsByte<EPlayerStatus> Status;
	
// Functions
public:
	APlayerCharacter();

	virtual void Tick(float DeltaTime) override;

	TEnumAsByte<EPlayerStatus> GetStatus();

protected:
	virtual void BeginPlay() override;

	// Gun Stuff
	UFUNCTION(BlueprintNativeEvent, Category="Gun")
	void SetGun(TSubclassOf<AGunObject> GunRef);

	// Input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartAim();
	void EndAim();

	UFUNCTION(BlueprintNativeEvent, Category="Gun")
	void StartShoot();

	UFUNCTION(BlueprintNativeEvent, Category="CATEOGRY")
	void EndShoot();

};
