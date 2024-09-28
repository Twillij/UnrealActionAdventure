#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"

class UInputAction;
class USkill;

UCLASS()
class SKILLSYSTEM_API USkillComponent : public UActorComponent
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Default Skills")
    TArray<TSubclassOf<USkill>> DefaultSkillClasses;
    
    UPROPERTY()
    TArray<USkill*> Skills;

public:
    UFUNCTION(BlueprintPure)
    ACharacter* GetOwningCharacter() const;
    
    UFUNCTION(BlueprintPure)
    TArray<USkill*> GetAllSkills(){ return Skills; }
    
    UFUNCTION(BlueprintPure)
    USkill* GetSkillOfClass(const TSubclassOf<USkill> SkillClass);

    UFUNCTION(BlueprintPure)
    USkill* GetSkillOfID(const FName SkillID);

    UFUNCTION(BlueprintPure)
    bool HasSkill(const USkill* Skill) const;
    
    UFUNCTION(BlueprintCallable)
    void AddSkill(USkill* Skill);

    UFUNCTION(BlueprintCallable)
    void RemoveSkill(USkill* Skill);

    UFUNCTION(BlueprintCallable)
    void BindSkillToInput(USkill* Skill, const UInputAction* InputAction);

protected:
    virtual void OnRegister() override;
    
    void InitializeSkills();
};
