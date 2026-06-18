// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class PROTOTIPADOMOTORES_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnDamageTaken(AActor* damagedActor, float Damage, const class UDamageType* DamageType, class AController* instigatedBy, AActor* DamageCauser);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Stats")
	float maxHealth = 100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	float health;

	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	bool isAlive = true;
};
