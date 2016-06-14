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
		Node();

		Planet* data;
		std::vector<Node*> Children;
		Node* getNode(Planet* find)
		{
			if (data == find)
			{
				return this;
			}
			else
			{
				for (int i = 0; i < Children.size(); i++) 
				{
					if (data != nullptr)
					{
						if (Children.at(i)->getNode(find))
						{
							return Children.at(i)->getNode(find);
						}
					}
				}
			}
			return nullptr;
		}

		bool AddChild(Planet* Children, Planet* Parent)
		{

		}
	};

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
	
	void insert(int value)
	{
		if (root->value == NULL)
		{
			root->value = value;
		}
		Node* current = root;
		Node* next = getNode(current, value);
		while (current != next)
		{
			current = next;
			next = getNode(current, value);
		}

		Node* discover = new Node(value);

		if (current->value > value)
		{
			current->leftNode = discover;
		}
		else if (current->value < value)
		{
			current->rightNode = discover;
		}
		else
		{
			delete discover;
		}

		//Node* newnode = new Node(value);
	}
	Node* root;
	bool find(int value)
	{
		Node* current = root;
		Node* next = getnode(current, value);

		if (current->value == value)
		{
			return true;
		}

		while (current != next)
		{
			current = next;
			next = getNode(current, value);

			if (current->value == value)
			{
				return true;
			}
			
		}
		return false;
	}
};