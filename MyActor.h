// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBCJUNG_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector2D Start;
	int EvCount;
	TArray<FVector2D> Arr;
	float totDis;
	

public:
	// Called every frame
	// virtual void Tick(float DeltaTime) override;
	
	float Distance(FVector2D current, FVector2D later);
	void Move(FVector2D current);
	int Step();
	void CreateEvent();

};