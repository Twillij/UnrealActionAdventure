#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

UCLASS()
class ACTIONADVENTURE_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> CampaignMap;

	UFUNCTION(BlueprintCallable)
	void HostCampaignMode() const;

	UFUNCTION(BlueprintCallable)
	void JoinCampaignMode(const FString& JoinURL) const;
};
