#pragma once
#include "BaseApplication.h"
#include "Vector.h"
#include "Matrix3.h"
class Texture;
class SpriteBatch;
class Planet
{
private:
	Planet* m_Parent;
	float m_rotationSpeed, m_rotationAngle;
	Matrix3 m_localTrans, m_globalTrans, m_scaleTrans, m_rotationTrans, m_translationTrans;
	Texture* m_tex;
	SpriteBatch* m_sBatch;
public:
	Planet(Texture* tex, Planet* parent, float rotateSpeed, float rotateAngle);
	~Planet();
	void update(float T);
};

