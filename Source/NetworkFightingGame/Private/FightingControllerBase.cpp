// Copyright Rohit 2023-2024


#include "FightingControllerBase.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FightingCameraManager.h"
#include "InputMappingContext.h"
#include "InputAction.h"

AFightingControllerBase::AFightingControllerBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerCameraManagerClass = AFightingCameraManager::StaticClass();
}

void AFightingControllerBase::NetSpawnFunction_Implementation()
{
	const TObjectPtr<UWorld> world = GetWorld();
	if (!IsValid(world))
	{
		return;
	}

	const TObjectPtr<APawn> pawn =  GetPawn();
	if (!IsValid(pawn))
	{
		return;
	}

	world->SpawnActor<AActor>(ActorToSpawn, (pawn->GetActorLocation() + FVector{ 0.0f,0.0f,50.0f }), FRotator::ZeroRotator);

}

void AFightingControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* enhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	enhancedInputSubsystem->ClearAllMappings();
	enhancedInputSubsystem->AddMappingContext(MovementInputContext, 0);

	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(InputComponent);
	if (IsValid(InputComp))
	{
		if (IsValid(MovementInputAction))
		{
			InputComp->BindAction(MovementInputAction, ETriggerEvent::Triggered, this, &AFightingControllerBase::HorizontalMove);
		}

		if (IsValid(JumpInputAction))
		{
			InputComp->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ThisClass::Jump);
		}
	}
}

void AFightingControllerBase::HorizontalMove(const FInputActionValue& Value)
{
	float horizontalAxisValue = Value.Get<float>();
	ACharacter* possesedCharacter = GetCharacter();
	if (IsValid(possesedCharacter))
	{
		possesedCharacter->AddMovementInput(possesedCharacter->GetActorForwardVector(),horizontalAxisValue);
	}
}

void AFightingControllerBase::Jump(const FInputActionValue& Value)
{
	bool jumpValue = Value.Get<bool>();
	if (jumpValue)
	{
		ACharacter* possesedCharacter = GetCharacter();
		if (IsValid(possesedCharacter))
		{
			possesedCharacter->Jump();
		}
	}
}
