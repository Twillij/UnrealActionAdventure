#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomDataContainer.h"
#include "CustomDataLibrary.generated.h"

UCLASS()
class UCustomDataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static FCustomDataContainer CreateBoolData(const bool InBool);
	
	UFUNCTION(BlueprintCallable)
	static FCustomDataContainer CreateNumData(const double InNum);
	
	UFUNCTION(BlueprintCallable)
	static FCustomDataContainer CreateStringData(const FString InString);
};
