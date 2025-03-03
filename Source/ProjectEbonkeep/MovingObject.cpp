// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObject.h"

// Sets default values
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("THIS IS A TEST WARNING"));
}

// Called every frame
void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

void AMovingObject::MovePlatform(float DeltaTime)
{
	// Get current location
	FVector CurrentLocation = GetActorLocation();

	// Add vector to location
	CurrentLocation += PlatformVelocity * DeltaTime;
	
	// Set Location
	SetActorLocation(CurrentLocation);

	// Send platform back if gone too far
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if(DistanceMoved > MoveDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}
}
