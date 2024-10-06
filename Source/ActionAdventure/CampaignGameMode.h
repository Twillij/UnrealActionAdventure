#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CampaignGameMode.generated.h"

UCLASS()
class ACTIONADVENTURE_API ACampaignGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SaveGameProgress();

	UFUNCTION(BlueprintCallable)
	void LoadGameProgress();

protected:
	virtual void BeginPlay() override;
};
