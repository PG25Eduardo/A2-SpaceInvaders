// Copyright Rohit 2023-2024


#include "FightingCameraManager.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"


void AFightingCameraManager::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	
	FVector camLoc = GetCameraLocation();
	FRotator camRot = GetCameraRotation();

	if (!IsValid(CameraData))
	{
		return;
	}

	TArray<TObjectPtr<AActor>> pawns;

	const TObjectPtr<UWorld> world = GetWorld();

	if (!IsValid(world))
	{
		return;
	}

	const TObjectPtr<AGameStateBase> gameState = world->GetGameState();
	if (!IsValid(gameState))
	{
		return;
	}

	// geting all the characters and adding the positions to the list
	for (const TObjectPtr<APlayerState> playerStateIter : gameState->PlayerArray)
	{
		TObjectPtr<APawn> pawnIter = playerStateIter->GetPawn();
		if (!IsValid(pawnIter))
		{
			continue;
		}
		pawns.AddUnique(pawnIter);
	}

	FVector avgLoc = UGameplayStatics::GetActorArrayAverageLocation(pawns);
	avgLoc += CameraData->CameraOffset;

	FVector lerpLocation = FMath::VInterpTo(GetCameraLocation(), avgLoc, DeltaTime, CameraData->CameraDelay);

	camRot = CameraData->CameraRotationOffset;

	OutVT.POV.Location = lerpLocation;
	OutVT.POV.Rotation = camRot;
	OutVT.POV.FOV = 90.0f;
}
