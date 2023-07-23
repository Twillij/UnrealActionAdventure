#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

#define GAMEPLAYATTRIBUTE_BASEVALUE_GETTER(PropertyName) \
	FORCEINLINE float GetBase##PropertyName() const \
	{ \
		return PropertyName.GetBaseValue(); \
	}

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_BASEVALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UNREALACTIONRPG_API UCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, MaxMana);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Health = 100;
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth = 100;
	
	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData Mana = 100;

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxMana = 100;
};
