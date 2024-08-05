#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Skill.generated.h"

class USkillComponent;

UCLASS(Blueprintable)
class ACTIONADVENTURE_API USkill : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SkillID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SkillDescription;
	
	UPROPERTY(BlueprintReadOnly)
	USkillComponent* OwningComponent = nullptr;

public:
	UFUNCTION(BlueprintNativeEvent)
	void ActivateSkill();

	void virtual ActivateSkill_Implementation(){}
};
