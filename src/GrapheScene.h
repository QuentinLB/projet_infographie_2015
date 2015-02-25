#pragma once
#include "GrapheSceneNode.h"

class GrapheScene
{
private:
	GrapheSceneNode* _racine;

public:
	GrapheScene(GrapheSceneNode* racine);
	~GrapheScene(void);
};
