#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreFunctionLibrary.generated.h"

UCLASS()
class MYACTIONRPG_API UCoreFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	* Returns the name of the streaming level which the actor belongs to.
	* Note: If the actor does not belong to a streaming level, it will return the name of the persistent level instead.
	* Tip: In the above case, use a nearby actor that is definitely streamed in instead.
	*/
	UFUNCTION(BlueprintPure)
	static FName GetStreamingLevelNameFromActor(const AActor* Actor);
};
