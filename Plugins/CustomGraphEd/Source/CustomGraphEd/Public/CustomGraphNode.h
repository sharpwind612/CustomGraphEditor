// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraphNode.h"

#include "CustomGraphNode.generated.h"


UCLASS()
class UEdCustomGraphNode : public UEdGraphNode
{
	GENERATED_UCLASS_BODY()

public:
	// UEdGraphNode interface
	virtual void AllocateDefaultPins() override;

};