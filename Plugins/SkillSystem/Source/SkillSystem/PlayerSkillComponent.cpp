#include "PlayerSkillComponent.h"
#include "Skill.h"
#include "EnhancedInputComponent.h"

void UPlayerSkillComponent::BindSkillToInput(USkill* Skill, const UInputAction* InputAction) const
{
	if (!HasSkill(Skill) || !InputAction)
		return;

	const APawn* OwningPawn = GetOwningPawn();
	if (!OwningPawn)
		return;

	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(OwningPawn->InputComponent);
	if (!InputComponent)
		return;

	InputComponent->BindAction(InputAction, ETriggerEvent::Triggered, Skill, "ActivateSkill");
}

void UPlayerSkillComponent::OnRegister()
{
	Super::OnRegister();
	
	if (GetWorld() && GetWorld()->IsGameWorld() && HasAuthority())
	{
		// Request skill data to load from client
	}
}
