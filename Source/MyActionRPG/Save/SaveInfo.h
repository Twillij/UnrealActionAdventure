#pragma once

#include "CoreMinimal.h"
#include "SaveInfo.generated.h"

class UCharacterAttributeSet;

USTRUCT(BlueprintType)
struct FActorLocationInfo
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite)
	FName PersistentLevelName = NAME_None;

	UPROPERTY(BlueprintReadWrite)
	FName StreamingLevelName = NAME_None;

	UPROPERTY(BlueprintReadWrite)
	FVector WorldLocation = FVector();

	FActorLocationInfo(){}
	FActorLocationInfo(const AActor* Actor);
};

USTRUCT(BlueprintType)
struct FCharacterAttributeInfo
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite)
	float Health = 0;

	UPROPERTY(BlueprintReadWrite)
	float MaxHealth = 0;

	UPROPERTY(BlueprintReadWrite)
	float Mana = 0;

	UPROPERTY(BlueprintReadWrite)
	float MaxMana = 0;

	FCharacterAttributeInfo(){}
	FCharacterAttributeInfo(const UCharacterAttributeSet* CharacterAttributeSet);
};
