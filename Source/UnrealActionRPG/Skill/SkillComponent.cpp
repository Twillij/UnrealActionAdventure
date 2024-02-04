#include "SkillComponent.h"
#include "Skill.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

ACharacter* USkillComponent::GetOwningCharacter() const
{
	return Cast<ACharacter>(GetOwner());
}

USkill* USkillComponent::GetSkillOfClass(const TSubclassOf<USkill> SkillClass)
{
	for (USkill* Skill : Skills)
		if (Skill && Skill->GetClass() == SkillClass)
			return Skill;
	
	return nullptr;
}

USkill* USkillComponent::GetSkillOfID(const FName SkillID)
{
	for (USkill* Skill : Skills)
		if (Skill && Skill->SkillID == SkillID)
			return Skill;

	return nullptr;
}

bool USkillComponent::HasSkill(const USkill* Skill)
{
	if (!Skill)
		return false;
	
	for (const USkill* OwnedSkill : Skills)
		if (OwnedSkill == Skill)
			return true;

	return false;
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

void USkillComponent::BindSkillToInput(USkill* Skill, const UInputAction* InputAction)
{
	if (!HasSkill(Skill) || !InputAction)
		return;

	const ACharacter* OwningCharacter = GetOwningCharacter();
	if (!OwningCharacter)
		return;

	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(OwningCharacter->InputComponent);
	if (!InputComponent)
		return;
	
	InputComponent->BindAction(InputAction, ETriggerEvent::Triggered, Skill, "ActivateSkill");
}

void USkillComponent::OnRegister()
{
	Super::OnRegister();
	InitializeSkills();
}

void USkillComponent::InitializeSkills()
{
	for (TSubclassOf<USkill> SkillClass : DefaultSkillClasses)
	{
		if (SkillClass)
		{
			USkill* NewSkill = NewObject<USkill>(this, SkillClass);
			AddSkill(NewSkill);
		}
	}
}
