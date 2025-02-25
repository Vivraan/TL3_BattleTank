// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

#include "Engine/World.h"



void UTankBarrel::Elevate(float RelativeAngularSpeed)
{
	// move barrel the right amount in this frame, given elevation speed and tick
	RelativeAngularSpeed = FMath::Clamp<float>(RelativeAngularSpeed, -1, +1);
	float ElevationChange = RelativeAngularSpeed * MaxAngularSpeed * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float ClampedElevation = FMath::ClampAngle(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));

}
