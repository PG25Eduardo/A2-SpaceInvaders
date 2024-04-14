// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FightingControllerBase.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;

UCLASS()
class NETWORKFIGHTINGGAME_API AFightingControllerBase : public APlayerController
{
	GENERATED_BODY()

public:

	AFightingControllerBase(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MovementInputContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MovementInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> ActorToSpawn;

	// UFUNCTION required for networking functions
	UFUNCTION(Server, BlueprintCallable, Reliable)
	void NetSpawnFunction();

protected:

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void HorizontalMove(const FInputActionValue& Value);


	UFUNCTION()
	void Jump(const FInputActionValue& Value);

	
};
