#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveStructs.h"
#include "PlayerSaveGame.generated.h"

UCLASS()
class ACTIONADVENTURE_API UPlayerSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	FCharacterMasterInfo PlayerInfo;
};
