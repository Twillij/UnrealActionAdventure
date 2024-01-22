#pragma once

#include "Skill.generated.h"

class USkillComponent;

UCLASS()
class UNREALACTIONRPG_API USkill : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	USkillComponent* OwningComponent = nullptr;

public:
	UFUNCTION(BlueprintNativeEvent)
	void ActivateSkill();

	void virtual ActivateSkill_Implementation(){}
};
