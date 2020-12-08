// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

/*
* Members *
*/
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", Meta = (MakeEditWidget = "true"))
	FVector TargetLocation;

private:
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
	float DistanceBetweenLocations_Sqrd;



/*
* Methods *
*/
public:
	AMovingPlatform();


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	void SwapStartAndEndLocation(FVector& StartLocation, FVector& EndLocation);

};
