// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/DataAsset.h"
#include "FightingCameraManager.generated.h"

/**
 * 
 */

UCLASS(Blueprintable, BlueprintType)
class NETWORKFIGHTINGGAME_API UCameraData : public UDataAsset
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CameraDelay;
};


UCLASS()
class NETWORKFIGHTINGGAME_API AFightingCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraData> CameraData;
	
};
