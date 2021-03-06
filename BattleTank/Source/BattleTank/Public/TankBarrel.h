// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))//, hidecategories = ("Physics", "Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max down speed and +1 is max up
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup) float MaxDegreesPerSecond = 5;
	UPROPERTY(EditDefaultsOnly, Category = Setup) float MaxElevationDegrees = 40;
	UPROPERTY(EditDefaultsOnly, Category = Setup) float MinElevationDegrees = 0;

	
};
