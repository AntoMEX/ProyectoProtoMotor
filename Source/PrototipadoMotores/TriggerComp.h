// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Move.h"
#include "TriggerComp.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROTOTIPADOMOTORES_API UTriggerComp : public UBoxComponent
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	UTriggerComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Trigger(bool triggerValue);

	UPROPERTY(EditAnywhere)
	bool isPresgurePlate = false;

	UPROPERTY(VisibleAnywhere)
	bool isTriggered = false;

	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UMove* moveComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* verlappedComp, AActor* otherActor,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* verlappedComp, AActor* otherActor,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex);

};
