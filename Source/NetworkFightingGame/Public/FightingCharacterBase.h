// Copyright Rohit 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FightingCharacterBase.generated.h"

class UHealthComponent;

UCLASS()
class NETWORKFIGHTINGGAME_API AFightingCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFightingCharacterBase();

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UHealthComponent> HealthComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
