// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComp.h"

UTriggerComp::UTriggerComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComp::BeginPlay()
{
	Super::BeginPlay();

	if (moveActor)
	{
		moveComponent = moveActor->FindComponentByClass<UMove>();
	}
	if (isPresgurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComp::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComp::OnOverlapEnd);
	}
}

void UTriggerComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComp::Trigger(bool triggerValue)
{
	isTriggered = triggerValue;

	if (moveComponent)
	{
		moveComponent->SetShouldMove(isTriggered);
	}
}

void UTriggerComp::OnOverlapBegin(UPrimitiveComponent* verlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		if (!isTriggered)
		{
			Trigger(true);
		}
	}
}

void UTriggerComp::OnOverlapEnd(UPrimitiveComponent* verlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		if (isTriggered)
		{
			Trigger(false);
		}
	}
}
