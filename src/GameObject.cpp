#include "GameObject.h"
#include "Texture.h"
#include "SpriteBatch.h"


GameObject::GameObject(Texture * tex, GameObject * parent, float rotateSpeed, float rotateAngle, float Scale, float pX, float pY)
{
	m_tex = tex;
	m_Parent = parent;
	m_rotationSpeed = rotateSpeed;
	m_rotationAngle = rotateAngle;

	

	// scale
	m_scaleTrans = Matrix3::CreateScale(Vector3(Scale, Scale, 1));
	m_rotationTrans = Matrix3::CreateRotation(0);
	m_translationTrans = Matrix3::CreateTranslation(Vector3(pX, pY, 1));

	m_localTrans = m_translationTrans * m_rotationTrans * m_scaleTrans;
}

GameObject::~GameObject()
{
}

void GameObject::update(float T)
{
	Matrix3 m_rotationTrans;

	//Rotation
	m_rotationAngle += m_rotationSpeed * T;
	m_rotationTrans = Matrix3::CreateRotation(m_rotationAngle);

	//m_localTrans = m_rotationTrans * m_localTrans;
	m_localTrans = m_translationTrans * m_rotationTrans * m_scaleTrans;

	if (m_Parent != nullptr)
	{
		m_globalTrans = m_Parent->m_globalTrans * m_localTrans;
	}
	else
	{
		m_globalTrans = m_localTrans;
	}
}

void GameObject::Draw(SpriteBatch* batch)
{
	batch->drawSpriteTransformed3x3(m_tex, m_globalTrans);
}
