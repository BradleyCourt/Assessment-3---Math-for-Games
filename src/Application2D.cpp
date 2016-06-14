#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

Texture* Pic;


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");
	Pic = new Texture("./bin/textures/Pic1.jpg");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;
	delete Pic;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	//m_rotation += M_PI * deltaTime;

	//for (int i = 0; i < 0; i++)
	//{
	//	if (isKeyPressed(GLFW_KEY_0 + i))
	//	{
	//		m_delay = 10 * i;
	//	}
	//}
	// the applciation closes if we return false
	deltatime = deltaTime;
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100);
	m_spriteBatch->drawSprite(Pic, 300, 200, 600, 300);

	//m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	//m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	//m_spriteBatch->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f);

	//m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	//m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	//m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);

	// done drawing sprites
	m_spriteBatch->end();	
}