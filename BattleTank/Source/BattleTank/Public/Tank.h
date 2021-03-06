// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // No include below this one!!


// Foward declarations
class UTankBarrel; 
class UTankTurret;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly) UTankMovementComponent* TankMovementComponent = nullptr;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup) void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup) void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable) void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = Firing) float LaunchSpeed = 100000; //1000 m/s TODO Find a default
	UPROPERTY(EditDefaultsOnly, Category = Firing) float ReloadTimeInSeconds = 3;


	UPROPERTY(EditDefaultsOnly, Category = Setup) TSubclassOf<AProjectile> ProjectileBlueprint;


	// use to know where the bullet needs to spawn
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;

};
