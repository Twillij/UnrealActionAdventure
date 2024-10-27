#include "CampaignGameMode.h"
#include "Character/CharacterBase.h"
#include "Save/PlayerSaveGame.h"
#include "Save/SaveSubsystem.h"
#include "Kismet/GameplayStatics.h"

void ACampaignGameMode::SaveGameProgress()
{
	UPlayerSaveGame* SaveGameObject = Cast<UPlayerSaveGame>(UGameplayStatics::CreateSaveGameObject(UPlayerSaveGame::StaticClass()));
	ACharacterBase* PlayerCharacter = Cast<ACharacterBase>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (!PlayerCharacter)
	{
		UE_LOG(RPGSave, Error, TEXT("Invalid player character"));
		return;
	}
	
	SaveGameObject->PlayerInfo = FCharacterMasterInfo(PlayerCharacter);

	if (!UGameplayStatics::SaveGameToSlot(SaveGameObject, "SlotName", 0)) // TODO: Slot name as param variable
	{
		UE_LOG(RPGSave, Warning, TEXT("Failed saving to slot"));
	}
}

void ACampaignGameMode::LoadGameProgress()
{
	if (UPlayerSaveGame* LoadedGame = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot("SlotName", 0)))
	{
		const FCharacterMasterInfo PlayerInfo = LoadedGame->PlayerInfo;
		FString LogString = "Save sample log string\n";
		LogString.Append("Name:" + PlayerInfo.Name.ToString() + "\n");
		LogString.Append("Location: " + PlayerInfo.LocationInfo.WorldLocation.ToString() + "\n");
		UE_LOG(RPGSave, Display, TEXT("%s"), *LogString);
	}
}

void ACampaignGameMode::BeginPlay()
{
	Super::BeginPlay();
}
