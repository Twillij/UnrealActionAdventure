#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveInfo.h"
#include "MySaveGame.generated.h"

UCLASS()
class UNREALACTIONRPG_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	FCharacterMasterInfo PlayerInfo;
};
