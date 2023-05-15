#include "SaveInfo.h"
#include "CoreFunctionLibrary.h"
#include "Character/MyCharacter.h"
#include "Gameplay/Attributes/CharacterAttributeSet.h"
#include "Kismet/GameplayStatics.h"

FActorLocationInfo::FActorLocationInfo(const AActor* Actor)
{
	if (!Actor)
		return;

	PersistentLevelName = FName(*UGameplayStatics::GetCurrentLevelName(Actor));
	StreamingLevelName = UCoreFunctionLibrary::GetStreamingLevelNameFromActor(Actor); // TODO: This may not work as intended for the player. See function tooltip.
	WorldLocation = Actor->GetActorLocation();
}

FCharacterAttributeInfo::FCharacterAttributeInfo(const UCharacterAttributeSet* CharacterAttributeSet)
{
	if (!CharacterAttributeSet)
		return;

	Health = CharacterAttributeSet->GetBaseHealth();
	MaxHealth = CharacterAttributeSet->GetBaseMaxHealth();
	Mana = CharacterAttributeSet->GetBaseMana();
	MaxMana = CharacterAttributeSet->GetBaseMaxMana();
}

FCharacterMasterInfo::FCharacterMasterInfo(const AMyCharacter* Character)
{
	if (!Character)
		return;
		
	Name = Character->Name;
	LocationInfo = FActorLocationInfo(Character);
	AttributeInfo = FCharacterAttributeInfo(Character->GetAttributeSet());
}
