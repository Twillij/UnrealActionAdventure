#include "CustomDataContainer.h"
#include "Misc/DefaultValueHelper.h"

FCustomDataContainer::FCustomDataContainer(const bool& InBool)
{
	DataType = ECustomDataType::Bool;
	RawData = InBool ? "true" : "false";
}

FCustomDataContainer::FCustomDataContainer(const double& InNum)
{
	DataType = ECustomDataType::Number;
	RawData = FString::Printf(TEXT("%f"), InNum);
}

FCustomDataContainer::FCustomDataContainer(const FString& InString)
{
	DataType = ECustomDataType::String;
	RawData = InString;
}

bool FCustomDataContainer::GetBoolData() const
{
	return DataType == ECustomDataType::Bool ? RawData.Equals("true", ESearchCase::IgnoreCase) : false;
}

double FCustomDataContainer::GetNumData() const
{
	double OutNum;
	
	if (DataType == ECustomDataType::Number)
		FDefaultValueHelper::ParseDouble(RawData, OutNum);
	
	return OutNum;
}

FString FCustomDataContainer::GetStringData() const
{
	return DataType == ECustomDataType::String ? RawData : FString();
}
