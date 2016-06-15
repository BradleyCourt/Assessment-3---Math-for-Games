#pragma once
#include <vector>
#include <iostream>
#include <fstream>

class SpriteBatch;
class Planet;
class Node
{
public:
	Node();
	~Node();
	Node(Planet* p);
	

	Planet* data;
	std::vector<Node*> m_Children = { nullptr };

	Node* getNode(Planet* find);
	void update(float t);
	void Draw(SpriteBatch* s);
	void AddChild(Planet* Children);
		
	void Save(std::fstream& file);
	void Load(std::fstream& file);
};