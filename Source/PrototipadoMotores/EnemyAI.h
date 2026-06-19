// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "PrototipadoMotoresCharacter.h"
#include "BehaviorTree/blackboardComponent.h"
#include "EnemyCharacter.h"
#include "EnemyAI.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTIPADOMOTORES_API AEnemyAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	APrototipadoMotoresCharacter* PlayerPawn;

	AEnemyCharacter* myCharacter;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* enemyTree;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public:
	void StartbehaviorTree(AEnemyCharacter* character);

	APrototipadoMotoresCharacter* getPlayerCharacter() const { return PlayerPawn; };
	AEnemyCharacter* getMyCharacter() const { return myCharacter; };
};
