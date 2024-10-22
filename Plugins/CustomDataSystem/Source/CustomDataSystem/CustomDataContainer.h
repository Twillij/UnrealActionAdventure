#pragma once

#include "CustomDataContainer.generated.h"

UENUM(BlueprintType)
enum class ECustomDataType : uint8
{
	Void,
	Bool,
	Number,
	String
};

USTRUCT(BlueprintType)
struct FCustomDataContainer
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECustomDataType DataType = ECustomDataType::Void;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString RawData;
	
	FCustomDataContainer() {}
	FCustomDataContainer(const bool& InBool);
	FCustomDataContainer(const double& InNum);
	FCustomDataContainer(const FString& InString);
	
	bool GetBoolData() const;
	double GetNumData() const;
	FString GetStringData() const;
};
