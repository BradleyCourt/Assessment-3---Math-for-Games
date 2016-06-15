#include "Node.h"
#include "Trees.h"
#include "GameObject.h"
#include "SpriteBatch.h"
#include <fstream>

Node::Node()
{
	data = nullptr;
}

Node::~Node()
{
}




Node::Node(GameObject * p)
{
	data = p;
}

Node * Node::getNode(GameObject * find)
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

void Node::update(float t)
{
	data->update(t);
	for (unsigned int i = 0; i < m_Children.size(); i++)
	{
		if (m_Children.at(i) != nullptr)
			m_Children.at(i)->update(t);
	}
}

void Node::Draw(SpriteBatch * s)
{
	data->Draw(s);
	for (unsigned int i = 0; i < m_Children.size(); i++)

	{
		if (m_Children.at(i) != nullptr)
			m_Children.at(i)->Draw(s);
	}
}

void Node::AddChild(GameObject * Children)
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

void Node::Save(std::fstream& file)
{
	std::cout << "Node written" << std::endl;

	//file.write((char*)&data->m_localTrans, sizeof(data->m_localTrans));
	file.write((char*)&data->m_rotationAngle, sizeof(data->m_rotationAngle));

	for (unsigned int i = 0; i < m_Children.size(); i++)
	{
		if (m_Children.at(i) != nullptr)
			m_Children.at(i)->Save(file);
	}
}

void Node::Load(std::fstream& file)
{
	std::cout << "Node read" << std::endl;

	//file.read((char*)&data->m_localTrans, sizeof(data->m_localTrans));
	file.read((char*)&data->m_rotationAngle, sizeof(data->m_rotationAngle));

	for (unsigned int i = 0; i < m_Children.size(); i++)
	{
		if (m_Children.at(i) != nullptr)
			m_Children.at(i)->Load(file);
	}
}