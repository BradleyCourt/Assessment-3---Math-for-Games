#pragma once
#include <vector>
#include <iostream>
#include <fstream>

class SpriteBatch;
class GameObject;
class Node
{
public:
	Node();
	~Node();
	Node(GameObject* p);
	

	GameObject* data;
	std::vector<Node*> m_Children = { nullptr };

	Node* getNode(GameObject* find);
	void update(float t);
	void Draw(SpriteBatch* s);
	void AddChild(GameObject* Children);
		
	void Save(std::fstream& file);
	void Load(std::fstream& file);
};