// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototipadoMotoresGameMode.h"

APrototipadoMotoresGameMode::APrototipadoMotoresGameMode()
{
	// stub
}

void APrototipadoMotoresGameMode::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<APrototipadoMotoresCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacter::StaticClass(), enemyArray);

	if (enemyArray.Num() <= 0)
	{
		return;
	}

	for (AActor* temp : enemyArray)
	{
		if (temp) 
		{
			AEnemyCharacter* enemy = Cast<AEnemyCharacter>(temp);

			if (!enemy) 
			{
				continue;
			}

			AEnemyAI* enemyController = Cast<AEnemyAI>(enemy->GetController());

			if (enemyController) 
			{
				enemyController->StartbehaviorTree(enemy);
			}
			
		}
	}
}
