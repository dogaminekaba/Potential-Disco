// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class POTENTIALDISCO_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// <summary>
	/// Called for forwards/backwards input 
	/// </summary>
	/// <param name="Value"></param>
	void MoveForward(float Value);

	/// <summary>
	/// Called for side to side input 
	/// </summary>
	/// <param name="Value"></param>
	void MoveRight(float Value);

	/// <summary>
	/// Called via input to turn at a given rate
	/// </summary>
	/// <param name="Rate"> This is a normalized rate, i.e. 1.0 means 100% of desired turn rate </param>
	void TurnAtRate(float Rate);

	/// <summary>
	/// Called via input to look up/down at a given rate
	/// </summary>
	/// <param name="Rate"> This is a normalized rate, i.e. 1.0 means 100% of desired turn rate </param>
	void LookUpAtRate(float Rate);

	/// <summary>
	/// Zoom the camera in or out with mouse scroll
	/// </summary>
	void ZoomCamera(float Value);

	/// <summary>
	/// Called when the fire button is pressed
	/// </summary>
	void FireWeapon();

	bool GetBeamEndLocation(const FVector& MuzzleSocketLocation, FVector& OutBeamLocation);

	/// <summary>
	/// Set bAiming true with button press
	/// </summary>
	void AimingButtonPressed();

	/// <summary>
	/// Set bAiming false with button release
	/// </summary>
	void AimingButtonReleased();

	/// <summary>
	/// Handle interpolation for zoom when aiming
	/// </summary>
	/// <param name="DeltaTime"></param>
	void CameraInterpZoom(float DeltaTime);

public:	
	/// <summary>
	/// Called every frame
	/// </summary>
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Called to bind functionality to input
	/// </summary>
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	/// <summary>
	/// Camera boom positioning the camera behind the character
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/// <summary>
	/// Camera that follows the character
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/// <summary>
	/// Base turn rate, in deg/sec. Other scaling may affect final turn rate
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	/// <summary>
	/// Base look up/down rate, in deg/sec. Other scaling may affect final turn rate
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

	/// <summary>
	/// Randomized gunshot sound cue
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class USoundCue* FireSound;

	/// <summary>
	/// Flash spawned at barrel socket
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	/// <summary>
	/// Montage for firing the weapon
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class UAnimMontage* HipFireMontage;

	/// <summary>
	/// Particles spawned upon bullet impact
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactParticles;

	/// <summary>
	/// Smoke trail for bullets
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* BeamParticles;

	/// <summary>
	/// True when aiming
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	bool bAiming;

	/// <summary>
	/// Default camera field of view value
	/// </summary>
	float CameraDefaultFOV;

	/// <summary>
	/// Field of view value for when zoomed in
	/// </summary>
	float CameraZoomedFOV;

	/// <summary>
	/// Current field of view this frame
	/// </summary>
	float CameraCurrentFOV;

	/// <summary>
	/// Interp speed for zooming when aiming
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	float ZoomInterpSpeed;

	/// <summary>
	/// Zooming rate for default camera position
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	float CameraZoomingRate;

	/// <summary>
	/// Minimum FOV value of camera
	/// </summary>
	float CameraMinFOV;

	/// <summary>
	/// Maximum FOV value of camera
	/// </summary>
	float CameraMaxFOV;

public:

	/// <summary>
	/// Returns CameraBoom subobject
	/// </summary>
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/// <summary>
	/// Returns FollowCamera subobject
	/// </summary>
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }


};
