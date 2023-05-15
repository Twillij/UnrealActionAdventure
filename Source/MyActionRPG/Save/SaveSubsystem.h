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

protected:
	UPROPERTY(BlueprintReadOnly)
	UMySaveGame* LastSavedGame;

	UPROPERTY(BlueprintReadOnly)
	UMySaveGame* LastLoadedGame;	

public:
	UMySaveGame* GetLastSavedGame() { return LastSavedGame; }
	UMySaveGame* GetLastLoadedGame() { return LastLoadedGame; }

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	void SaveGameProgress(UObject* WorldContextObject, UMySaveGame* SaveGameObject = nullptr, FString SaveSlotName = "Default", int32 UserIndex = 0);

	UFUNCTION(BlueprintCallable)
	UMySaveGame* LoadGameProgress(FString SaveSlotName = "Default", int32 UserIndex = 0);
};
