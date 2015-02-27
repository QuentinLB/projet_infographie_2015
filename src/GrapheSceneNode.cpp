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

GrapheSceneNode::GrapheSceneNode(IElementDessinable* dessinable, bool isDrawable)
{
	_draw = isDrawable;
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

bool GrapheSceneNode::isDrawable()
{
	return _draw;
}

void GrapheSceneNode::setDraw(bool isDrawable)
{
	_draw = isDrawable;
}

void GrapheSceneNode::switchVisibility()
{
	_draw = !_draw;
}