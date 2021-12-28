#include "CustomGraph.h"
#include "CustomGraphNode.h"

UEdCustomGraph::UEdCustomGraph(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UEdCustomGraph::RebuildGraph() 
{
	//创建测试节点
	auto Node1 = CreateCustomNode();
	auto Node2 = CreateCustomNode();
}

UEdCustomGraphNode* UEdCustomGraph::CreateCustomNode()
{
	FGraphNodeCreator<UEdCustomGraphNode> NodeCreator(*this);
	UEdCustomGraphNode* result = NodeCreator.CreateNode();
	NodeCreator.Finalize();
	return result;
}