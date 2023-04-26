#pragma once

#include "CoreMinimal.h"
#include "SaveInfo.generated.h"

USTRUCT(BlueprintType)
struct FCharacterAttributeInfo
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite)
	float Health;

	UPROPERTY(BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(BlueprintReadWrite)
	float Mana;

	UPROPERTY(BlueprintReadWrite)
	float MaxMana;
};

USTRUCT(BlueprintType)
struct FCharacterLocationInfo
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite)
	FName PersistentLevelName;

	UPROPERTY(BlueprintReadWrite)
	FName StreamingLevelName;

	UPROPERTY(BlueprintReadWrite)
	FVector WorldLocation;
};
