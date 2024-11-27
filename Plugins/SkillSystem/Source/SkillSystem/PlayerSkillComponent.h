#pragma once

#include "SkillComponent.h"
#include "PlayerSkillComponent.generated.h"

UCLASS()
class SKILLSYSTEM_API UPlayerSkillComponent : public USkillComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Skill")
	void BindSkillToInput(USkill* Skill, const UInputAction* InputAction) const;
	
	UFUNCTION(BlueprintCallable, Client, Reliable, Category = "Network")
	void ClientSendSkills();

	UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Network")
	void ServerReceiveSkills(const TArray<FSkillData>& SkillDataArray);
	
protected:
	virtual void OnRegister() override;
};
