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

GrapheSceneNode::GrapheSceneNode(IElementDessinable* dessinable, IElementDessinable** descendants, int nb_desc)
{
	_draw = true;
	_dessinable = dessinable;
	_descendants = vector<GrapheSceneNode*>();
	for (int i = 0; i < nb_desc; i++)
		_descendants.push_back(new GrapheSceneNode(descendants[i]));
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