#include "trees.h"
#include <vector>
#include <iostream>
#include "GameObject.h"
#include "Node.h"
#include "SpriteBatch.h"

Tree::Tree()
{
}

Tree::~Tree()
{
	//delete &root;
}

Tree::Tree(GameObject * p)
{
	root = new Node(p);
}

bool Tree::isEmpty()
{
	if (root == nullptr) return true;
	return false;
}

void Tree::updateAll(float t)
{
	root->update(t);
}

void Tree::Draw(SpriteBatch * s)
{
	root->Draw(s);
}

bool Tree::AddChild(GameObject * Children, GameObject * Parent)
{
	Node* temp = (root->getNode(Parent));
	if (temp == nullptr)
	{
		// No parent find, child is not added
		return false;
	}
	else
	{
		// parent found
		temp->AddChild(Children);
		Children->m_Parent = Parent;
		return true;
	}
}
