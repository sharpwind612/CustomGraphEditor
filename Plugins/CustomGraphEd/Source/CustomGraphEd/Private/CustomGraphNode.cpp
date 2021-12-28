// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomGraphNode.h"
#include "EdGraphSchema_K2.h"	// BlueprintGraph

namespace CustomGraphNodePN
{
	FName Input1 = TEXT("Input1");
	FName Input2 = TEXT("Input2");
	FName Output1 = TEXT("Output1");
}

UEdCustomGraphNode::UEdCustomGraphNode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UEdCustomGraphNode::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, NAME_None, CustomGraphNodePN::Input1);
	CreatePin(EGPD_Input, NAME_None, CustomGraphNodePN::Input2);

	CreatePin(EGPD_Output, NAME_None, CustomGraphNodePN::Output1);
}