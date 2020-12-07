// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 5.f;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += FVector(DeltaTime * Speed, 0.0f, 0.0f);
		SetActorLocation(CurrentLocation);
	}

	
}
