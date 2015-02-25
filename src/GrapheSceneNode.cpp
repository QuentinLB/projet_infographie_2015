#include "GrapheSceneNode.h"


GrapheSceneNode::GrapheSceneNode(void)
{
	_descendants = vector<GrapheSceneNode*>();
}


GrapheSceneNode::~GrapheSceneNode(void)
{
}

void GrapheSceneNode::ajDescendant(GrapheSceneNode* node)
{
	_descendants.push_back(node);
}