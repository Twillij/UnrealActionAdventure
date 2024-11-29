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
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAutoLoadPresetSkills = true;
    
protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "bAutoLoadPresetSkills"))
    TArray<FSkillData> PresetSkills;
    
    UPROPERTY(Replicated)
    TArray<USkill*> Skills;

public:
    USkillComponent();
    
    UFUNCTION(BlueprintPure, Category = "Component")
    APawn* GetOwningPawn() const { return Cast<APawn>(GetOwner()); }

    UFUNCTION(BlueprintPure, Category = "Component")
    AController* GetOwningController() const;
    
    UFUNCTION(BlueprintPure, Category = "Network")
    bool HasAuthority() const { return GetOwnerRole() == ROLE_Authority; }
    
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

    // Returns a skill data array that is used for initialization.
    // This function is intended for custom implementation, e.g. to load skills from a save file.
    UFUNCTION(BlueprintNativeEvent, Category = "Skill")
    TArray<FSkillData> GetSkillsToInitialize();

    // Creates skill instances based on the provided skill data array and caches within the Skills array.
    UFUNCTION(BlueprintCallable, Category = "Skill")
    void InitializeSkills(const TArray<FSkillData>& InSkills);

    // Retrieves skill data from the client and then sends it to the server to initialize.
    // Must be called from the owning actor on the server.
    UFUNCTION(Client, Reliable, BlueprintCallable, Category = "Skill")
    void ClientInitializeSkills();

    // Initializes skills on the server and replicates it to the owning actor.
    UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Skill")
    void ServerInitializeSkills(const TArray<FSkillData>& InSkills);
    
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
