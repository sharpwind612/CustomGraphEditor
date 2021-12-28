// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraph.h"

#include "CustomGraph.generated.h"


UCLASS()
class UEdCustomGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:
	void RebuildGraph();

	class UEdCustomGraphNode* CreateCustomNode();
};