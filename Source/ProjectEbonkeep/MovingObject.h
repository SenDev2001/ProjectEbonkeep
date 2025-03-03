// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class PROJECTEBONKEEP_API AMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="MovingObject")
	FVector PlatformVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere, Category="MovingObject")
	float MoveDistance = 100;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
};
