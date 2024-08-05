#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

UCLASS()
class ACTIONADVENTURE_API AMainGameMode : public AGameModeBase
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
