#pragma once

#include "CoreMinimal.h"
#include "SaveStructs.generated.h"

class ACharacterBase;
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
	FVector WorldLocation = FVector(0);

	FActorLocationInfo(){}
	FActorLocationInfo(const AActor* Actor);
};

USTRUCT(BlueprintType)
struct FCharacterMasterInfo
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite)
	FName Name = NAME_None;

	UPROPERTY(BlueprintReadWrite)
	FActorLocationInfo LocationInfo = FActorLocationInfo();

	FCharacterMasterInfo(){}
	FCharacterMasterInfo(const ACharacterBase* Character);
};
