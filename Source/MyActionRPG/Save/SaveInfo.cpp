#include "SaveInfo.h"
#include "CoreFunctionLibrary.h"
#include "Character/Attributes/CharacterAttributeSet.h"
#include "Kismet/GameplayStatics.h"

FActorLocationInfo::FActorLocationInfo(const AActor* Actor)
{
	if (!Actor)
		return;

	PersistentLevelName = FName(*UGameplayStatics::GetCurrentLevelName(Actor));
	StreamingLevelName = UCoreFunctionLibrary::GetStreamingLevelNameFromActor(Actor); // This may not work as intended for the player. See function tooltip.
	WorldLocation = Actor->GetActorLocation();
}

FCharacterAttributeInfo::FCharacterAttributeInfo(const UCharacterAttributeSet* CharacterAttributeSet)
{
	if (!CharacterAttributeSet)
		return;

	Health = CharacterAttributeSet->GetHealth();
	MaxHealth = CharacterAttributeSet->GetMaxHealth();
	Mana = CharacterAttributeSet->GetMana();
	MaxMana = CharacterAttributeSet->GetMaxMana();
}
