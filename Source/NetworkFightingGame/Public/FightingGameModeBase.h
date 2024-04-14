// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FightingGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKFIGHTINGGAME_API AFightingGameModeBase : public AGameMode
{
	GENERATED_BODY()

public:

	AFightingGameModeBase(const FObjectInitializer& ObjectInitializer);
};
