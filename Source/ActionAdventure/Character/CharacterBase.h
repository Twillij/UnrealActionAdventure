#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class USkillComponent;

UCLASS()
class ACTIONADVENTURE_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Info")
	FText CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	USkillComponent* SkillComponent;
};
