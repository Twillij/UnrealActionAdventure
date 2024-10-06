#include "MainMenuGameMode.h"

void AMainMenuGameMode::HostCampaignMode() const
{
	GetWorld()->ServerTravel(CampaignMap.GetLongPackageName() + "?listen");
}

void AMainMenuGameMode::JoinCampaignMode(const FString& JoinURL) const
{
	if (APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController())
	{
		PlayerController->ClientTravel(JoinURL, TRAVEL_Absolute);
	}
}
