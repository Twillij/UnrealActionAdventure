#include "SaveSubsystem.h"
#include "MySaveGame.h"
#include "MainGameMode.h"

void USaveSubsystem::SaveGameProgress()
{
	if (!Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this)))
		return;
	
	if (UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass())))
	{
		
	}
}
