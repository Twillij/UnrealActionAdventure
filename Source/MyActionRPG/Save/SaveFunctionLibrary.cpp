#include "SaveFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

FActorLocationInfo USaveFunctionLibrary::CreateActorLocationInfo(const AActor* Actor)
{
	return FActorLocationInfo(Actor);
}

FCharacterAttributeInfo USaveFunctionLibrary::CreateCharacterAttributeInfo(const UCharacterAttributeSet* CharacterAttributeSet)
{
	return FCharacterAttributeInfo(CharacterAttributeSet);
}

FCharacterMasterInfo USaveFunctionLibrary::CreateCharacterMasterInfo(const ARPGCharacter* Character)
{
	return FCharacterMasterInfo(Character);
}
