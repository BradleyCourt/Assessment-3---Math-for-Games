#pragma once
class Node;
class GameObject;
class SpriteBatch;
class Tree
{
public:
	
	Node* root;
	Tree();

	~Tree();
	Tree(GameObject* p);

	bool isEmpty();
	void updateAll(float t);
	void Draw(SpriteBatch* s);

	bool AddChild(GameObject* Children, GameObject* Parent);

};