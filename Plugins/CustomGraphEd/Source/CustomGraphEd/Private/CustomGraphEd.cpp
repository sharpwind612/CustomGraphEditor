// Copyright Epic Games, Inc. All Rights Reserved.

#include "CustomGraphEd.h"
#include "CustomGraphEdStyle.h"
#include "CustomGraphEdCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "SCustomGraphWindow.h"
#include "ToolMenus.h"

static const FName CustomGraphEdTabName("CustomGraphEd");

#define LOCTEXT_NAMESPACE "FCustomGraphEdModule"

void FCustomGraphEdModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FCustomGraphEdStyle::Initialize();
	FCustomGraphEdStyle::ReloadTextures();

	FCustomGraphEdCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FCustomGraphEdCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FCustomGraphEdModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FCustomGraphEdModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(CustomGraphEdTabName, FOnSpawnTab::CreateRaw(this, &FCustomGraphEdModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FCustomGraphEdTabTitle", "CustomGraphEd"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FCustomGraphEdModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FCustomGraphEdStyle::Shutdown();

	FCustomGraphEdCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(CustomGraphEdTabName);
}

TSharedRef<SDockTab> FCustomGraphEdModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	//FText WidgetText = FText::Format(
	//	LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
	//	FText::FromString(TEXT("FCustomGraphEdModule::OnSpawnPluginTab")),
	//	FText::FromString(TEXT("CustomGraphEd.cpp"))
	//	);
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SCustomGraphWindow)
		];
}

void FCustomGraphEdModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(CustomGraphEdTabName);
}

void FCustomGraphEdModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FCustomGraphEdCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FCustomGraphEdCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomGraphEdModule, CustomGraphEd)