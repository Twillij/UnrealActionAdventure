#include "CustomDataLibrary.h"

FCustomDataContainer UCustomDataLibrary::CreateBoolData(const bool InBool)
{
	return FCustomDataContainer(InBool);
}

FCustomDataContainer UCustomDataLibrary::CreateNumData(const double InNum)
{
	return FCustomDataContainer(InNum);
}

FCustomDataContainer UCustomDataLibrary::CreateStringData(const FString InString)
{
	return FCustomDataContainer(InString);
}
