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

#ifndef SFGE_GRAPHICS_H
#define SFGE_GRAPHICS_H

#include <engine/engine.h>

/**
 * \brief The Graphics Manager
 */
class GraphicsManager : public Module<GraphicsManager>
{
public:
	/**
	 * \brief Initialize the Graphics Manager
	 */
	void Init() override;
	/**
	 * \brief Update the Graphics Manager and prepare for the rendering
	 * \param dt Delta time since last frame
	 */
	void Update(sf::Time dt) override;


	void Destroy() override;
	sf::RenderWindow* GetWindow();

protected:

	void CheckVersion();

	sf::RenderWindow* window = nullptr;
};


#endif
