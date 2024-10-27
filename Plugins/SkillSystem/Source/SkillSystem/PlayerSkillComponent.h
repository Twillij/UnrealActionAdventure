#pragma once

#include "SkillComponent.h"
#include "PlayerSkillComponent.generated.h"

UCLASS()
class SKILLSYSTEM_API UPlayerSkillComponent : public USkillComponent
{
	GENERATED_BODY()

protected:
	virtual void InitializeComponent() override;
};
