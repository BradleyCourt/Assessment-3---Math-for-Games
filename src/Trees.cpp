#include "Trees.h"
#include <vector>
#include <iostream>
#include "Planet.h"


class Tree
{
public:
	class Node
	{
	public:
		Node()
		{
			data = nullptr;
		}
		Node(Planet* p)
		{
			data = p;
		}

		Planet* data;
		std::vector<Node*> m_Children = { nullptr };
		Node* getNode(Planet* find)
		{
			if (data == find)
			{
				return this;
			}
			else
			{
				for (int i = 0; i < m_Children.size(); i++)
				{
					if (data != nullptr)
					{
						if (m_Children.at(i)->getNode(find))
						{
							return m_Children.at(i)->getNode(find);
						}
					}
				}
			}
			return nullptr;
		}
		void AddChild(Planet* Children)
		{
			if (m_Children.at(0) == nullptr)
			{
				m_Children.at(0) = new Node(Children);
			}
			else
			{
				m_Children.push_back(new Node(Children));
			}
		}
		
	};
	Node* root;
	Tree() : root(new Node) {};

	~Tree()
	{
		delete root;
	}

	bool isEmpty()
	{
		if (root == nullptr) return true;
		return false;
	}

	bool AddChild(Planet* Children, Planet* Parent)
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
};