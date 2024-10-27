#include "Skill.h"
#include "Net/UnrealNetwork.h"

void USkill::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USkill, bUnlocked)
	DOREPLIFETIME(USkill, SkillLevel)
}
