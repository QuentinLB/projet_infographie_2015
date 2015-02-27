#include <algorithm>
#include "GrapheScene.h"

GrapheScene::GrapheScene(GrapheSceneNode* racine):_racine(racine)
{
}

void fe_node_delete(GrapheSceneNode* node)
{
	vector<GrapheSceneNode*> childs = node->getDescendants();
	if(!childs.empty())
		for_each(childs.begin(), childs.end(),fe_node_delete);
	delete node;
}

GrapheScene::~GrapheScene(void)
{
	vector<GrapheSceneNode*> rac_childs = _racine->getDescendants();
	for_each(rac_childs.begin(), rac_childs.end(),fe_node_delete);
	delete _racine;
}

void fe_node(GrapheSceneNode* node)
{
	if(node->isDrawable())
		node->getDessinable()->draw();
	vector<GrapheSceneNode*> childs = node->getDescendants();
	if(!childs.empty())
		for_each(childs.begin(), childs.end(),fe_node);
}

void GrapheScene::render()
{
	if(_racine->isDrawable())
		_racine->getDessinable()->draw();
	vector<GrapheSceneNode*> rac_childs = _racine->getDescendants();
	for_each(rac_childs.begin(), rac_childs.end(),fe_node);
}
