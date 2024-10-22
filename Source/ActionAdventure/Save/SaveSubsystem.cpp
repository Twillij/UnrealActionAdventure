#include "SaveSubsystem.h"
#include "PlayerSaveGame.h"
#include "Character/CharacterBase.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(RPGSave);

void USaveSubsystem::SaveGameProgress(UObject* WorldContextObject, UPlayerSaveGame* SaveGameObject, FString SaveSlotName, int32 UserIndex)
{
	ACharacterBase* PlayerCharacter = Cast<ACharacterBase>(UGameplayStatics::GetPlayerCharacter(WorldContextObject, UserIndex));

	if (!SaveGameObject)
	{
		if (!PlayerCharacter)
		{
			UE_LOG(RPGSave, Error, TEXT("Invalid player character"));
			return;
		}

		SaveGameObject = Cast<UPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(UPlayerSaveGame::StaticClass()));
		SaveGameObject->PlayerInfo = FCharacterMasterInfo(PlayerCharacter);
	}

	if (!UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveSlotName, UserIndex))
	{
		UE_LOG(RPGSave, Warning, TEXT("Failed saving to slot"));
	}

	LastSavedGame = SaveGameObject;
}

UPlayerSaveGame* USaveSubsystem::LoadGameProgress(FString SaveSlotName, int32 UserIndex)
{
	UPlayerSaveGame* LoadedGame = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));

	if (LoadedGame)
	{
		const FCharacterMasterInfo PlayerInfo = LoadedGame->PlayerInfo;
		FString LogString = "Save sample log string\n";
		LogString.Append("Name:" + PlayerInfo.Name.ToString() + "\n");
		LogString.Append("Location: " + PlayerInfo.LocationInfo.WorldLocation.ToString() + "\n");
		UE_LOG(RPGSave, Display, TEXT("%s"), *LogString);
		LastLoadedGame = LoadedGame;
	}

	return LoadedGame;
}
