#include "MainGameMode.h"
#include "Character/MyCharacter.h"
#include "Save/MySaveGame.h"
#include "Save/SaveSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

void AMainGameMode::SaveGameProgress()
{
	UMySaveGame* SaveGameObject = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
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

void AMainGameMode::LoadGameProgress()
{
	if (UMySaveGame* LoadedGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot("SlotName", 0)))
	{
		const FCharacterMasterInfo PlayerInfo = LoadedGame->PlayerInfo;
		FString LogString = "Save sample log string\n";
		LogString.Append("Name:" + PlayerInfo.Name.ToString() + "\n");
		LogString.Append("Location: " + PlayerInfo.LocationInfo.WorldLocation.ToString() + "\n");
		LogString.Append("HP: " + FString::SanitizeFloat(PlayerInfo.AttributeInfo.Health) + "\n");
		UE_LOG(RPGSave, Display, TEXT("%s"), *LogString);
	}
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}
