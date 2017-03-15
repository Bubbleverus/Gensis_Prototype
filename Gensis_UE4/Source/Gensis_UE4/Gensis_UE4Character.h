// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "Gensis_UE4Character.generated.h"

UCLASS(config=Game)
class AGensis_UE4Character : public ACharacter
{
	GENERATED_BODY()
public:
  AGensis_UE4Character();


  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStats)
    float health;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStats)
    float walk_speed;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStats)
    float sprint_speed;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStats)
    float max_stamina;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStats)
    float stamina;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStats)
    bool is_sprint;
  
  /** Camera Stats */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CameraStats)
    float aim_boom_length; 

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CameraStats)
    FVector aim_camera_offset; 

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CameraStats)
    float normal_boom_length;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CameraStats)
    FVector normal_camera_offset;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;


	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;




protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

  void StartSprint();

  void EndSprint();

  void StartAim();

  void EndAim();

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

