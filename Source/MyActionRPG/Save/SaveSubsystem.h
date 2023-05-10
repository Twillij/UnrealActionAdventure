#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveSubsystem.generated.h"

class USaveGame;

DECLARE_LOG_CATEGORY_EXTERN(RPGSave, Log, All);

UCLASS()
class MYACTIONRPG_API USaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	void SaveGameProgress(UObject* WorldContextObject);
};
