#include "SaveSubsystem.h"
#include "MySaveGame.h"
#include "Character/MyCharacter.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(RPGSave);

void USaveSubsystem::SaveGameProgress(UObject* WorldContextObject, UMySaveGame* SaveGameObject, FString SaveSlotName, int32 UserIndex)
{
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(WorldContextObject, UserIndex));

	if (!SaveGameObject)
	{
		if (!PlayerCharacter)
		{
			UE_LOG(RPGSave, Error, TEXT("Invalid player character"));
			return;
		}

		SaveGameObject = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
		SaveGameObject->PlayerInfo = FCharacterMasterInfo(PlayerCharacter);
	}

	if (!UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveSlotName, UserIndex))
	{
		UE_LOG(RPGSave, Warning, TEXT("Failed saving to slot"));
	}

	LastSavedGame = SaveGameObject;
}

UMySaveGame* USaveSubsystem::LoadGameProgress(FString SaveSlotName, int32 UserIndex)
{
	UMySaveGame* LoadedGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));

	if (LoadedGame)
	{
		const FCharacterMasterInfo PlayerInfo = LoadedGame->PlayerInfo;
		FString LogString = "Save sample log string\n";
		LogString.Append("Name:" + PlayerInfo.Name.ToString() + "\n");
		LogString.Append("Location: " + PlayerInfo.LocationInfo.WorldLocation.ToString() + "\n");
		LogString.Append("HP: " + FString::SanitizeFloat(PlayerInfo.AttributeInfo.Health) + "\n");
		UE_LOG(RPGSave, Display, TEXT("%s"), *LogString);
		LastLoadedGame = LoadedGame;
	}

	return LoadedGame;
}
