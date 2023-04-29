#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "SaveSubsystem.generated.h"

class USaveGame;

UCLASS()
class MYACTIONRPG_API USaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void SaveGameProgress();
};
