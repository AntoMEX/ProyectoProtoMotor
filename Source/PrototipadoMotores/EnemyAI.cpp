// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyAI::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AEnemyAI::StartbehaviorTree(AEnemyCharacter* character)
{


	if (enemyTree)
	{
		myCharacter = Cast<AEnemyCharacter>(GetPawn());
		PlayerPawn = getPlayerCharacter();

		RunBehaviorTree(enemyTree);
		if (myCharacter || PlayerPawn) 
		{
			UBlackboardComponent* blackboard = GetBlackboardComponent();
			if (blackboard) 
			{
				GetBlackboardComponent()->SetValueAsVector("StartLocation", myCharacter->GetActorLocation());
				GetBlackboardComponent()->SetValueAsVector("PlayerLocation", PlayerPawn->GetActorLocation());
			}
		}
	}
}
