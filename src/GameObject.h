#pragma once
#include "BaseApplication.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Trees.h"
class Texture;
class SpriteBatch;
class GameObject
{

	
	
public:
	Matrix3 m_localTrans, m_globalTrans;
	GameObject* m_Parent;
	GameObject(Texture* tex, GameObject* parent, float rotateSpeed, float rotateAngle, float Scale, float pX, float pY);
	~GameObject();
	void update(float T);
	void Draw(SpriteBatch* batch);

	float m_rotationSpeed, m_rotationAngle;
	Matrix3 m_scaleTrans, m_translationTrans, m_rotationTrans;
	Texture* m_tex;
};

