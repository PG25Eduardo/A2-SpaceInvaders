// Copyright Rohit 2023-2024


#include "FightingGameModeBase.h"
#include "FightingGameStateBase.h"
#include "FightingPlayerState.h"
#include "FightingControllerBase.h"
#include "FightingCharacterBase.h"
#include "FightingGameHUDBase.h"


AFightingGameModeBase::AFightingGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = AFightingGameStateBase::StaticClass();
	PlayerStateClass = AFightingPlayerState::StaticClass();
	PlayerControllerClass = AFightingControllerBase::StaticClass();
	DefaultPawnClass = AFightingCharacterBase::StaticClass();
	HUDClass = AFightingGameHUDBase::StaticClass();
}
