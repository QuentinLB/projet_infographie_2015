#include <algorithm>
#include "GrapheScene.h"

GrapheScene::GrapheScene(GrapheSceneNode* racine):_racine(racine)
{
}


GrapheScene::~GrapheScene(void)
{
}

void fe_node(GrapheSceneNode* node)
{
	node->getDessinable()->draw();
	vector<GrapheSceneNode*> childs = node->getDescendants();
	if(!childs.empty())
	{
		for_each(childs.begin(), childs.end(),fe_node);
	}
}

void GrapheScene::render()
{
	vector<GrapheSceneNode*> rac_childs = _racine->getDescendants();
	_racine->getDessinable()->draw();
	for_each(rac_childs.begin(), rac_childs.end(),fe_node);
}