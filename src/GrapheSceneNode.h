#pragma once
#include <vector>
#include "IElementDessinable.h"

using namespace std;

class GrapheSceneNode
{
private:
	IElementDessinable* _dessinable;
	vector<GrapheSceneNode*> _descendants;
	bool _draw;
public:
	GrapheSceneNode(void);
	GrapheSceneNode(IElementDessinable* dessinable);
	GrapheSceneNode(IElementDessinable* dessinable, bool draw);
	~GrapheSceneNode(void);
	void addDescendant(GrapheSceneNode* node);
	vector<GrapheSceneNode*> getDescendants();
	IElementDessinable* getDessinable();
};
