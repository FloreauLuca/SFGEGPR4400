/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <graphics/graphics.h>

#include <engine/log.h>
#include <engine/config.h>
//Dependencies includes
#include <SFML/Graphics/RenderWindow.hpp>
#include "imgui-SFML.h"
#include "imgui.h"

#include <sstream>

void GraphicsManager::Init()
{
	ConfigEngine* config = Engine::GetInstance()->GetConfig();
	window = new sf::RenderWindow(sf::VideoMode(config->screenResolution.x, config->screenResolution.y), "SFGE 0.1");
	if(config->maxFramerate)
	{
		window->setFramerateLimit(config->maxFramerate);
	}
	CheckVersion();
	//Init GUI
	ImGui::SFML::Init(*(sf::RenderTarget*)window);
}

void GraphicsManager::Update(sf::Time dt)
{
	ImGui::SFML::Update(*window, dt);
	
	window->clear();
	
	ImGui::SFML::Render(*window);
	window->display();
}

sf::RenderWindow * GraphicsManager::GetWindow()
{
	return window;
}

void GraphicsManager::CheckVersion()
{
	sf::ContextSettings settings = window->getSettings();
	std::stringstream log_message;
	log_message << "OpenGL version: " << settings.majorVersion << "." << settings.minorVersion << std::endl;
	
	Log::GetInstance()->Msg(log_message.str());
}

void checkVersion()
{

}


void GraphicsManager::Destroy()
{
	ImGui::SFML::Shutdown();
	if (window != nullptr)
	{
		delete window;
	}
	window = nullptr;
}