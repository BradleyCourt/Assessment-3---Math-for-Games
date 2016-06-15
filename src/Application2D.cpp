#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Planet.h"
#include "Trees.h"
#include "Node.h"
#include <iostream>
#include <fstream>

#include <Windows.h>

Texture* texTrump;
Texture* Money;
Texture* Trump_Face;

Planet* Trump;
Planet* Trumps_son;
Planet* Trump_NotBad;
Tree* TreeTrump;

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	texTrump = new Texture("./bin/textures/Pic1.png");
	Money = new Texture("./bin/textures/Pic2.png");
	Trump_Face = new Texture("./bin/textures/Pic3.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);


	Trump = new Planet(texTrump, nullptr, 2, 2, .5, 640, 360);
	Trumps_son = new Planet(Money, nullptr, -5, -5, 1, 0, 350);
	Trump_NotBad = new Planet(Trump_Face, nullptr, -5, -5, 1, 0, 350);

	TreeTrump = new Tree(Trump);
	TreeTrump->AddChild(Trumps_son, Trump);
	TreeTrump->AddChild(Trump_NotBad, Trumps_son);
	return true;
}

void Application2D::shutdown()
{

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;
	delete Trump;
	delete Money;
	delete texTrump;
	delete Trumps_son;

	destroyWindow();
}

bool hasOpenedUrl = false;
std::fstream file;

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	m_rotation += 3.141596f * deltaTime;

	//Trump->update(deltaTime);
	TreeTrump->updateAll(deltaTime);

	//for (int i = 0; i < 0; i++)
	//{
	//	if (isKeyPressed(GLFW_KEY_0 + i))
	//	{
	//		m_delay = 10 * i;
	//	}
	//}
	// the applciation closes if we return false

	if (isKeyPressed(GLFW_KEY_S))
	{
		std::cout << "Saved" << std::endl;

		file.open("data.dat", std::ios::out | std::ios::binary);

		TreeTrump->root->Save(file);

		file.close();
	}
	else if (isKeyPressed(GLFW_KEY_L))
	{
		std::cout << "Load" << std::endl;

		file.open("data.dat", std::ios::in | std::ios::binary);

		TreeTrump->root->Load(file);

		file.close();
	}

	if (!hasOpenedUrl)
	{
		hasOpenedUrl = true;

		/*ShellExecute(NULL,
			TEXT("open"),
			TEXT("https://www.youtube.com/watch?v=TeXatquVqAc"),
			NULL, NULL, SW_SHOWNORMAL);*/
	}

	deltatime = deltaTime;
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100);
	//m_spriteBatch->drawSprite(Pic, 300, 200, 600, 300);
	//m_spriteBatch->drawSprite(Pic2, 300, 200, 600, 300);

	//Trump->Draw(m_spriteBatch);
	TreeTrump->Draw(m_spriteBatch);

	//m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	//m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	//m_spriteBatch->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f);

	//m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	//m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	//m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);

	// done drawing sprites
	m_spriteBatch->end();	
}