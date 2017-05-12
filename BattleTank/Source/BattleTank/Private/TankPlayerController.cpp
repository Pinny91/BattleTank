// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

// Called every frame


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();


	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("PlayerController: Not possesing a tank")); }
	else { UE_LOG(LogTemp, Warning, TEXT("PlayerController: possesing tank, %s"), *ControlledTank->GetName()); }
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Get world location if linetrace through crosshair

}
