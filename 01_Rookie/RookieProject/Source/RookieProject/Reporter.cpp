// Fill out your copyright notice in the Description page of Project Settings.


#include "Reporter.h"

// Sets default values for this component's properties
UReporter::UReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReporter::BeginPlay()
{
	Super::BeginPlay();

	// LOG
	FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("report for %s."), *ObjectName);
	// ...
}


// Called every frame
void UReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

