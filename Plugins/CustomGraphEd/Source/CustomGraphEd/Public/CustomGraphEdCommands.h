// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "CustomGraphEdStyle.h"

class FCustomGraphEdCommands : public TCommands<FCustomGraphEdCommands>
{
public:

	FCustomGraphEdCommands()
		: TCommands<FCustomGraphEdCommands>(TEXT("CustomGraphEd"), NSLOCTEXT("Contexts", "CustomGraphEd", "CustomGraphEd Plugin"), NAME_None, FCustomGraphEdStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};