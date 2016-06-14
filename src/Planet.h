#pragma once
#include "Matrix3.h"
class Texture;
class SpriteBatch;
class Planet
{
public:
	Planet* m_Parent;
	float m_rotationSpeed, m_rotationAngle;
	Matrix3 m_localTrans, m_globalTrans, m_scaleTrans, m_rotationTrans, m_translationTrans;
	Texture* m_tex;
	SpriteBatch* m_sBatch;
	Planet();
	~Planet();
	void update(float T);
};

