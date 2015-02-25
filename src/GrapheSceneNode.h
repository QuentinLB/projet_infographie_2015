#pragma once
#include <vector>

using namespace std;

class GrapheSceneNode
{
private:
	vector<GrapheSceneNode*> _descendants;
public:
	GrapheSceneNode(void);
	~GrapheSceneNode(void);
	void ajDescendant(GrapheSceneNode* node);
};
