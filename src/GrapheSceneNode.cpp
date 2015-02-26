#include "GrapheSceneNode.h"


GrapheSceneNode::GrapheSceneNode(void)
{
	_descendants = vector<GrapheSceneNode*>();
}

GrapheSceneNode::GrapheSceneNode(IElementDessinable* dessinable)
{
	_draw = true;
	_dessinable = dessinable;
	_descendants = vector<GrapheSceneNode*>();
}

GrapheSceneNode::GrapheSceneNode(IElementDessinable* dessinable, bool draw)
{
	_draw = draw;
	_dessinable = dessinable;
	_descendants = vector<GrapheSceneNode*>();
}

GrapheSceneNode::~GrapheSceneNode(void)
{
}

void GrapheSceneNode::addDescendant(GrapheSceneNode* node)
{
	_descendants.push_back(node);
}

vector<GrapheSceneNode*> GrapheSceneNode::getDescendants()
{
	return _descendants;
}

IElementDessinable* GrapheSceneNode::getDessinable()
{
	return _dessinable;
}