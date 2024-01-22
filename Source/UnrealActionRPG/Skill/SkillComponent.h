#pragma once

#include "SkillComponent.generated.h"

class USkill;

UCLASS()
class UNREALACTIONRPG_API USkillComponent : public UActorComponent
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditAnywhere)
    TArray<USkill*> Skills;

public:
    UFUNCTION(BlueprintPure)
    TArray<USkill*> GetAllSkills(){ return Skills; }
    
    UFUNCTION(BlueprintPure)
    USkill* GetSkillOfClass(const TSubclassOf<USkill> SkillClass);
    
    UFUNCTION(BlueprintCallable)
    void AddSkill(USkill* Skill);

    UFUNCTION(BlueprintCallable)
    void RemoveSkill(USkill* Skill);

protected:
    virtual void BeginPlay() override;

    void InitializeSkills();
};
