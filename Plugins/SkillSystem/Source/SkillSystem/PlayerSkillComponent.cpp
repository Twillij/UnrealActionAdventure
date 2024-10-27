#include "PlayerSkillComponent.h"

void UPlayerSkillComponent::InitializeComponent()
{
	Super::InitializeComponent();

	const AController* OwningController = GetOwningController();
	if (OwningController && OwningController->IsLocalPlayerController())
	{
		
	}
}
