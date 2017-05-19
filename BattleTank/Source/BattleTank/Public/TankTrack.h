// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets the throttle to a value of -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input) void SetThrottle(float Throttle);
	
	//Max force in Newtons
	UPROPERTY(EditDefaultsOnly) float TrackMaxDrivingForce = 400000; // 40Tons at 10m/s²

	
};
