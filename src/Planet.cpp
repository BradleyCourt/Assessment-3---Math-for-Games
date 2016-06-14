#include "Planet.h"
#include "Texture.h"
#include "SpriteBatch.h"


Planet::Planet(Texture * tex, Planet * parent, float rotateSpeed, float rotateAngle)
{
}

Planet::~Planet()
{
}

void Planet::update(float T)
{
	//Rotation
	m_rotationAngle += m_rotationSpeed * T;
	m_rotationTrans = Matrix3::CreateRotation(m_rotationAngle);
}
