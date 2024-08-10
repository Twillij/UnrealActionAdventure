#include "SaveFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

FActorLocationInfo USaveFunctionLibrary::CreateActorLocationInfo(const AActor* Actor)
{
	return FActorLocationInfo(Actor);
}

FCharacterMasterInfo USaveFunctionLibrary::CreateCharacterMasterInfo(const ACharacterBase* Character)
{
	return FCharacterMasterInfo(Character);
}
