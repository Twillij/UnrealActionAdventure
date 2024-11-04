#include "SkillComponent.h"
#include "Skill.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Pawn.h"
#include "Net/UnrealNetwork.h"

USkillComponent::USkillComponent()
{
	SetIsReplicatedByDefault(true);
	bReplicateUsingRegisteredSubObjectList = true;
}

AController* USkillComponent::GetOwningController() const
{
	const APawn* OwningPawn = GetOwningPawn();
	return OwningPawn ? OwningPawn->GetController() : nullptr;
}

USkill* USkillComponent::GetSkillOfClass(const TSubclassOf<USkill>& SkillClass)
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

bool USkillComponent::HasSkill(const USkill* Skill) const
{
	return Skill ? Skills.Contains(Skill) : false;
}

void USkillComponent::AddSkill(USkill* Skill)
{
	if (Skill && !Skills.Contains(Skill))
	{
		AddReplicatedSubObject(Skill);
		Skills.Add(Skill);
		Skill->SetOwningComponent(this);
	}
}

void USkillComponent::RemoveSkill(USkill* Skill)
{
	if (Skills.Remove(Skill))
	{
		RemoveReplicatedSubObject(Skill);
		Skill->SetOwningComponent(nullptr);
	}
}

void USkillComponent::BindSkillToInput(USkill* Skill, const UInputAction* InputAction) const
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

FString USkillComponent::GetOwnerName() const
{
	const AActor* Owner = GetOwner();
	return Owner ? Owner->GetName() : "Invalid";
}

FString USkillComponent::GetOwnerNetRoleAsString() const
{
	const UEnum* EnumPtr = FindFirstObjectSafe<UEnum>(TEXT("ENetRole"));
	return EnumPtr ? EnumPtr->GetNameStringByValue(GetOwnerRole()) : "Invalid";
}

void USkillComponent::OnRegister()
{
	Super::OnRegister();

	if (GetWorld() && GetWorld()->IsGameWorld() && HasAuthority())
	{
		for (int i = 0; i < DefaultSkillClasses.Num(); ++i)
		{
			if (DefaultSkillClasses[i])
			{
				USkill* NewSkill = NewObject<USkill>(this, DefaultSkillClasses[i]);
				AddSkill(NewSkill);
			}
		}
	}
}

void USkillComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USkillComponent, Skills);
}
