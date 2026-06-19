// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PrototipadoMotoresCharacter.h"
#include "EnemyAI.h"
#include "PrototipadoMotoresGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class APrototipadoMotoresGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	APrototipadoMotoresGameMode();

protected:
	virtual void BeginPlay() override;

	APrototipadoMotoresCharacter* player;

	TArray<AActor*> enemyArray;
};



