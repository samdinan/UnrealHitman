// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true; 

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	if(StartingGun != nullptr)
	{
		SetGun(StartingGun);
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TEnumAsByte<EPlayerStatus> APlayerCharacter::GetStatus()
{
	return Status;
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &APlayerCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("LookUp_Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight_Mouse", this, &APawn::AddControllerYawInput);
	
	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &APlayerCharacter::StartAim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &APlayerCharacter::EndAim);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &APlayerCharacter::StartShoot);
	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &APlayerCharacter::EndShoot);

}

void APlayerCharacter::MoveForward(const float Value)
{
	if(Value != 0 && Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveRight(const float Value)
{
	if(Value != 0 && Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::StartAim()
{
}

void APlayerCharacter::EndAim()
{
}

void APlayerCharacter::StartShoot_Implementation()
{
	// if(CurrentGun != nullptr)
	// {
	// 	CurrentGun->PullTrigger(FollowCamera->GetComponentLocation(), FollowCamera->GetForwardVector());
	// }
}

void APlayerCharacter::EndShoot_Implementation()
{
	// if(CurrentGun != nullptr)
	// {
	// 	CurrentGun->ReleaseTrigger();
	// }
}

void APlayerCharacter::SetGun_Implementation(TSubclassOf<AGunObject> GunRef)
{
	CurrentGun = GetWorld()->SpawnActor<AGunObject>(GunRef, GetActorTransform());
	CurrentGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, GunSocketName);
}

