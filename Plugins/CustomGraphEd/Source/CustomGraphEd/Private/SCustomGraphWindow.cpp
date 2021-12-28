// Copyright Epic Games, Inc. All Rights Reserved.

#include "SCustomGraphWindow.h"
#include "CustomGraph.h"
#include "CustomGraphSchema.h"


void SCustomGraphWindow::Construct(const FArguments& InArgs)
{
	//����ͼ��
	GraphObj = NewObject<UEdCustomGraph>();
	GraphObj->Schema = UCustomGraphSchema::StaticClass();
	GraphObj->AddToRoot();
	GraphObj->RebuildGraph();  

	//ʹ��Ĭ��ͼ��༭��
	GraphEditorPtr = SNew(SGraphEditor)
		.GraphToEdit(GraphObj);


	//ָ�����ؼ���UI��
	ChildSlot
		[
			GraphEditorPtr.ToSharedRef()
		];
}