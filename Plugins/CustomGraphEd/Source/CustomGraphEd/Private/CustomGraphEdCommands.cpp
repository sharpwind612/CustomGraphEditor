// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomGraphEdCommands.h"

#define LOCTEXT_NAMESPACE "FCustomGraphEdModule"

void FCustomGraphEdCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "CustomGraphEd", "Bring up CustomGraphEd window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
