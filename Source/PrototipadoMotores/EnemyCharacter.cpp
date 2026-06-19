// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationYaw = false;
	//GetCharacterMovement()->bOrientRotationToMovement = true;

	//GetCharacterMovement()->MaxWalkSpeed = 300.f;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	health = maxHealth;

	OnTakeAnyDamage.AddDynamic(this, &AEnemyCharacter::OnDamageTaken);
	
}

void AEnemyCharacter::OnDamageTaken(AActor* damagedActor, float Damage, const UDamageType* DamageType, AController* instigatedBy, AActor* DamageCauser)
{
	if (isAlive)
	{
		health -= Damage;
		if (health <= 0)
		{
			isAlive = false;
			health = 0;
			//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

