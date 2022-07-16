// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

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
	
// Functions
public:
	APlayerCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:	
	// Input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveForward(float Value);
	void MoveRight(float Value);

};
