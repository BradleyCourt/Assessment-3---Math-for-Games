#pragma once
class Node;
class Planet;
class SpriteBatch;
class Tree
{
public:
	
	Node* root;
	Tree();

	~Tree();
	Tree(Planet* p);

	bool isEmpty();
	void updateAll(float t);
	void Draw(SpriteBatch* s);

	bool AddChild(Planet* Children, Planet* Parent);

};