// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//создаем компоненты
	FirstMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FirstMeshComp"));
	RootComponent = FirstMesh;
	SecondMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondMeshComp"));
}

void AMyActor::ChangeMetallic()
{
	if (!Metal) // проверяем применялся ли металлик
	{
		FirstDynamicMaterial->SetScalarParameterValue("Metallic", 1); // применяем если нет
		Metal = true;
	}
	else
	{
		FirstDynamicMaterial->SetScalarParameterValue("Metallic", 0); // отменяем если да
		Metal = false;
	}


	// перезапускаем таймер после смены
	AMyActor::MetallicTimer();
}

void AMyActor::ChangeColor()
{
	if (!Red) //проверяем применялся ли красный цвет
	{
		FirstDynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor::Red); // ставим красный если фолс
		Red = true;
	}
	else
	{
		FirstDynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor::Blue); // ставим синий если тру
		Red = false;
	}

	// перезапускаем таймер после смены
	AMyActor::ColorTimer();
}

void AMyActor::MetallicTimer()
{
	if (MetallicChanged < 5) // проверяем сколько раз сработал
	{
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AMyActor::ChangeMetallic, MetallicInterval, false);
		MetallicChanged = MetallicChanged + 1;
	}

}

void AMyActor::ColorTimer()
{
	if (ColorChanged < 5) // проверяем сколько раз сработал
	{
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &AMyActor::ChangeMetallic, MetallicInterval, false);
		ColorChanged = ColorChanged + 1;
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//создаем динамические материалы
	FirstDynamicMaterial = FirstMesh->CreateDynamicMaterialInstance(0, FirstMeshMaterial);
	SecondDynamicMaterial = SecondMesh->CreateDynamicMaterialInstance(0, SecondMeshMaterial);



	//Запускаем таймеры
	AMyActor::ColorTimer();
	AMyActor::MetallicTimer();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

