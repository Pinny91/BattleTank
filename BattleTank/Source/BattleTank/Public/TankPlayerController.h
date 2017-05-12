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
	
};
