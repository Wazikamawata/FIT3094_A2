// Fill out your copyright notice in the Description page of Project Settings.


#include "Builder.h"


#include "GOAP/BuildAction.h"
#include "GOAP/PickupMaterialsAction.h"

ABuilder::ABuilder() : AGOAPActor()
{
  Health = 400;
  MaxHealth = 400;
  FoodTrigger = 15;
}

void ABuilder::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	PickupMaterialsAction* PickupMaterials = new PickupMaterialsAction();
	PickupMaterials->AddPrecondition("HasResources", false);
	PickupMaterials->AddEffect("HasResources", true);
	AvailableActions.Add(PickupMaterials);
	BuildAction* NewBuildAction = new BuildAction();
	NewBuildAction->AddPrecondition("HasResources", true);
	NewBuildAction->AddEffect("HasResources", false);
	AvailableActions.Add(NewBuildAction);
}

TMap<FString, bool> ABuilder::GetWorldState()
{
	TMap<FString, bool> WorldState = Super::GetWorldState();
	WorldState.Add("HasResources", (NumWood != 0 && NumStone != 0)) ;
	return WorldState;
}

TMap<FString, bool> ABuilder::CreateGoalState()
{
	TMap<FString, bool> GoalState;
	return GoalState;
}

void ABuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
