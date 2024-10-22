#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveSubsystem.generated.h"

class USaveGame;

DECLARE_LOG_CATEGORY_EXTERN(RPGSave, Log, All);

UCLASS()
class ACTIONADVENTURE_API USaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UPlayerSaveGame* LastSavedGame;

	UPROPERTY(BlueprintReadOnly)
	UPlayerSaveGame* LastLoadedGame;	

public:
	UPlayerSaveGame* GetLastSavedGame() { return LastSavedGame; }
	UPlayerSaveGame* GetLastLoadedGame() { return LastLoadedGame; }

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	void SaveGameProgress(UObject* WorldContextObject, UPlayerSaveGame* SaveGameObject = nullptr, FString SaveSlotName = "Default", int32 UserIndex = 0);

	UFUNCTION(BlueprintCallable)
	UPlayerSaveGame* LoadGameProgress(FString SaveSlotName = "Default", int32 UserIndex = 0);
};
