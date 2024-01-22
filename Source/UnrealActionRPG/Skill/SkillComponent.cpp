#include "SkillComponent.h"
#include "Skill.h"

USkill* USkillComponent::GetSkillOfClass(const TSubclassOf<USkill> SkillClass)
{
	for (USkill* Skill : Skills)
		if (Skill && Skill->GetClass() == SkillClass)
			return Skill;
	
	return nullptr;
}

void USkillComponent::AddSkill(USkill* Skill)
{
	if (Skills.AddUnique(Skill))
		Skill->OwningComponent = this;
}

void USkillComponent::RemoveSkill(USkill* Skill)
{
	if (Skills.Remove(Skill))
		Skill->OwningComponent = nullptr;
}

void USkillComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeSkills();
}

void USkillComponent::InitializeSkills()
{
	for (USkill* Skill : Skills)
		if (Skill)
			Skill->OwningComponent = this;
}
