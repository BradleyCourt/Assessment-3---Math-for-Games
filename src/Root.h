#pragma once
class Root
{
public:
	Root();
	~Root();
	void SetRoot(Root* pNode);
	bool isEmpty;
	void UpdateAll(float deltatime);
};

