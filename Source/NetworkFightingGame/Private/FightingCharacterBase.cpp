// Copyright Rohit 2023-2024


#include "FightingCharacterBase.h"
#include "Net/UnrealNetwork.h"
#include "HealthComponent.h"

// Sets default values
AFightingCharacterBase::AFightingCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

// Called when the game starts or when spawned
void AFightingCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(HealthComponent))
	{
		OnTakeAnyDamage.AddUniqueDynamic(HealthComponent.Get(), &UHealthComponent::TakeDamage);
	}
	
}

// Called every frame
void AFightingCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFightingCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

