#pragma once
#include "BaseApplication.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Trees.h"
class Texture;
class SpriteBatch;
class Planet
{

	
	
public:
	Matrix3 m_localTrans, m_globalTrans;
	Planet* m_Parent;
	Planet(Texture* tex, Planet* parent, float rotateSpeed, float rotateAngle, float Scale, float pX, float pY);
	~Planet();
	void update(float T);
	void Draw(SpriteBatch* batch);

	float m_rotationSpeed, m_rotationAngle;
	Matrix3 m_scaleTrans, m_translationTrans, m_rotationTrans;
	Texture* m_tex;
};

