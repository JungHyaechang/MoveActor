// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor() 
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	Start = { 0, 0 };
	Arr.SetNum(11);
	EvCount = 0;
	totDis = 0;
	
		
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 10; i++) {
		if (i == 0) { Arr[0] = Start; }
		Arr[i + 1] = { Arr[i].X + Step(), Arr[i].Y + Step() };
		Move(Arr[i]);
		Move(Arr[i + 1]);
		Distance(Arr[i], Arr[i+1]);
		if (i == 0) { continue; }
		CreateEvent();
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %f"), totDis);
	UE_LOG(LogTemp, Warning, TEXT("Total Event : %d"), EvCount);
}

// Called every frame
/*void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

float AMyActor::Distance(FVector2D current, FVector2D later)
{
	FVector2D result = later - current;
	UE_LOG(LogTemp, Warning, TEXT("Distance : %f"), result.Size());
	totDis += result.Size();
	return result.Size();
	
}

void AMyActor::Move(FVector2D current)
{
	UE_LOG(LogTemp, Log, TEXT("Location : [%f, %f]"), current.X, current.Y);
}

int AMyActor::Step()
{
	int randnum = FMath::RandRange(-1, 1);
	return randnum;
}

void AMyActor::CreateEvent()
{
	int Cointoss = FMath::RandRange(0, 1);
	if (Cointoss == 1) {
		++EvCount;
		UE_LOG(LogTemp, Error, TEXT("You have encountered the %d enemy "), EvCount);
	}
}












