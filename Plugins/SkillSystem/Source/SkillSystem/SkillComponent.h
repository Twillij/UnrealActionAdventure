#pragma once

#include "CoreMinimal.h"
#include "SkillGlobals.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"

class UInputAction;
class USkill;

UCLASS(Blueprintable)
class SKILLSYSTEM_API USkillComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USkillComponent();
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "Default Skills")
    TArray<TSubclassOf<USkill>> DefaultSkillClasses;
    
    UPROPERTY(Replicated)
    TArray<USkill*> Skills;

public:
    UFUNCTION(BlueprintPure, Category = "Component")
    APawn* GetOwningPawn() const { return Cast<APawn>(GetOwner()); }

    UFUNCTION(BlueprintPure, Category = "Component")
    AController* GetOwningController() const;
    
    UFUNCTION(BlueprintPure, Category = "Network")
    bool HasAuthority() const { return GetOwnerRole() == ROLE_Authority; }

    UFUNCTION(BlueprintCallable, Client, Reliable, Category = "Network")
    virtual void ClientSendSkillData();

    UFUNCTION(BlueprintCallable, Server, Reliable, Category = "Network")
    virtual void ServerReceiveSkillData(const TArray<FSkillData>& SkillDataArray);
    
    UFUNCTION(BlueprintPure, Category = "Skill")
    TArray<USkill*> GetAllSkills() { return Skills; }
    
    UFUNCTION(BlueprintPure, Category = "Skill")
    USkill* GetSkillOfClass(const TSubclassOf<USkill>& SkillClass);

    UFUNCTION(BlueprintPure, Category = "Skill")
    USkill* GetSkillOfID(const FName SkillID);

    UFUNCTION(BlueprintPure, Category = "Skill")
    bool HasSkill(const USkill* Skill) const;
    
    UFUNCTION(BlueprintCallable, Category = "Skill")
    void AddSkill(USkill* Skill);

    UFUNCTION(BlueprintCallable, Category = "Skill")
    void RemoveSkill(USkill* Skill);
    
    UFUNCTION(BlueprintPure, Category = "Debug")
    FString GetClassName() const { return GetClass()->GetName(); }

    UFUNCTION(BlueprintPure, Category = "Debug")
    FString GetOwnerName() const;
    
    UFUNCTION(BlueprintPure, Category = "Debug")
    FString GetOwnerNetRoleAsString() const;

protected:
    virtual void OnRegister() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
