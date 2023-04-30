// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/MyCharacter/SK_MyCharacter.SK_MyCharacter"));
	GetMesh()->SetSkeletalMesh(MeshAsset.Object);

	// ”станавливаем значени€ свойств по умолчанию
	DefaultFloatProperty = 0.f;
	InstanceFloatProperty = 0.f;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("DefaultFloatProperty: %f"), DefaultFloatProperty);
	UE_LOG(LogTemp, Warning, TEXT("InstanceFloatProperty: %f"), InstanceFloatProperty);
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

