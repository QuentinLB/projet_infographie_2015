#pragma once

using namespace std;

class IElementDessinable
{
public:
	virtual ~IElementDessinable(){};
	virtual void draw() = 0;
	virtual void setElement(ofNode* aNode){};
};
