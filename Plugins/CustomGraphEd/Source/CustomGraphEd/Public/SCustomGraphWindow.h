// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "GraphEditor.h"


class SCustomGraphWindow : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCustomGraphWindow) {}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TSharedPtr<SGraphEditor> GraphEditorPtr;

	class UEdCustomGraph* GraphObj;
};