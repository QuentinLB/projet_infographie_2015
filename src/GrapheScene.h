#pragma once
#include "GrapheSceneNode.h"

class GrapheScene
{
private:
	GrapheSceneNode* _racine;
public:
	GrapheScene(){};
	GrapheScene(GrapheSceneNode* racine);
	~GrapheScene(void);
	void render();
	void dealloc();
};
