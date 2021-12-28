// Copyright Epic Games, Inc. All Rights Reserved.

#include "SCustomGraphWindow.h"
#include "CustomGraph.h"
#include "CustomGraphSchema.h"


void SCustomGraphWindow::Construct(const FArguments& InArgs)
{
	//创建图表
	GraphObj = NewObject<UEdCustomGraph>();
	GraphObj->Schema = UCustomGraphSchema::StaticClass();
	GraphObj->AddToRoot();
	GraphObj->RebuildGraph();  

	//使用默认图表编辑器
	GraphEditorPtr = SNew(SGraphEditor)
		.GraphToEdit(GraphObj);


	//指定本控件的UI：
	ChildSlot
		[
			GraphEditorPtr.ToSharedRef()
		];
}