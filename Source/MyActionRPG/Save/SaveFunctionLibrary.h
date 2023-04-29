#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SaveInfo.h"
#include "SaveFunctionLibrary.generated.h"

class UCharacterAttributeSet;

UCLASS()
class MYACTIONRPG_API USaveFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FActorLocationInfo CreateActorLocationInfo(const AActor* Actor);
	
	UFUNCTION(BlueprintCallable)
	static FCharacterAttributeInfo CreateCharacterAttributeInfo(const UCharacterAttributeSet* CharacterAttributeSet);
};
