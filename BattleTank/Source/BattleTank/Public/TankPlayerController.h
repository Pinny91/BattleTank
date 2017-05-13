// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Always the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
		// Sets default values for this pawn's properties

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
		ATank* GetControlledTank() const;

private:
	//start the tank moving the barrel so that a shot would hit where the crosshair instersects the world 
	void AimTowardsCrosshair();

	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	//Returns the location where the player is looking at
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;





	UPROPERTY(EditAnywhere) float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere) float CrossHairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere) float LineTraceRange = 1000000.f; // in cm

	
};
