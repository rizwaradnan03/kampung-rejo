#ifndef RENDER_HPP
#define RENDER_HPP

#include <string>
#include <SFML/Graphics.hpp>

class Render {
	public:
		virtual void _shape_render(sf::RenderWindow* window) = 0;
	
	private:
		std::string id;
};

#endif