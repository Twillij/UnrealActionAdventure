#pragma once

#include "CharacterBase.h"
#include "PlayableCharacter.generated.h"

class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
struct FInputActionValue;

UCLASS()
class UNREALACTIONRPG_API APlayableCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayableCharacter();
	
	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	UCameraComponent* FollowCamera;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
