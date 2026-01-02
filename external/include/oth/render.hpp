#ifndef RENDER_HPP
#define RENDER_HPP

#include <string>

class Render {
	public:
		virtual void shapeRender();
	
	private:
		std::string id;
};

#endif