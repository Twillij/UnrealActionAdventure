#include "SaveStructs.h"
#include "CoreFunctionLibrary.h"
#include "Character/CharacterBase.h"
#include "Kismet/GameplayStatics.h"

FActorLocationInfo::FActorLocationInfo(const AActor* Actor)
{
	if (!Actor)
		return;

	PersistentLevelName = FName(*UGameplayStatics::GetCurrentLevelName(Actor));
	StreamingLevelName = UCoreFunctionLibrary::GetStreamingLevelNameFromActor(Actor); // TODO: This may not work as intended for the player. See function tooltip.
	WorldLocation = Actor->GetActorLocation();
}

FCharacterMasterInfo::FCharacterMasterInfo(const ACharacterBase* Character)
{
	if (!Character)
		return;
	
	LocationInfo = FActorLocationInfo(Character);
}
