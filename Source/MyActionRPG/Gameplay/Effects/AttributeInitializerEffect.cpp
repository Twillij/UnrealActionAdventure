#include "AttributeInitializerEffect.h"
#include "Gameplay/Attributes/CharacterAttributeSet.h"

#define INITIALIZE_ATTRIBUTE(AttributeName, ModMagnitude) \
	FGameplayModifierInfo AttributeName##Modifier; \
	AttributeName##Modifier.Attribute = UCharacterAttributeSet::Get##AttributeName##Attribute(); \
	AttributeName##Modifier.ModifierOp = EGameplayModOp::Override; \
	AttributeName##Modifier.ModifierMagnitude = FGameplayEffectModifierMagnitude(ModMagnitude); \
	Modifiers.Add(AttributeName##Modifier);

UAttributeInitializerEffect::UAttributeInitializerEffect()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;
	INITIALIZE_ATTRIBUTE(Health, 100);
	INITIALIZE_ATTRIBUTE(MaxHealth, 100);
	INITIALIZE_ATTRIBUTE(Mana, 100);
	INITIALIZE_ATTRIBUTE(MaxMana, 100);
}
