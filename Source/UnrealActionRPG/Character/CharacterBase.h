#pragma once

#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class UNREALACTIONRPG_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	FText DisplayName;
};
