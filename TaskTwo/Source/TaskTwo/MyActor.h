// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "MyActor.generated.h"

UCLASS()
class TASKTWO_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

	//ќбъ€вл€ем переменные
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* FirstMesh;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* SecondMesh;
	UPROPERTY(EditDefaultsOnly)
		UMaterialInterface* FirstMeshMaterial;
	UPROPERTY(EditDefaultsOnly)
		UMaterialInterface* SecondMeshMaterial;
	UPROPERTY()
		UMaterialInstanceDynamic* FirstDynamicMaterial;
	UPROPERTY()
		UMaterialInstanceDynamic* SecondDynamicMaterial;
	UPROPERTY(EditDefaultsOnly)
		float MetallicInterval = 2;
	UPROPERTY(EditAnywhere)
		float ColorInterval = 3;
	int MetallicChanged;
	int ColorChanged;
	bool Red;
	bool Metal;

	//объ€вл€ем функции

	void ChangeMetallic();
	void ChangeColor();
	void MetallicTimer();
	void ColorTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
