#include "shape.hpp"
#include <iostream>
#include <string>

Shape::Shape(): _name{"untitled"}, _color{1.0f, 1.0f, 1.0f}
{
}

Shape::~Shape()
{
	std::cout << "c'tor shape" << std::endl;
}

Color Shape::color() const
{
	return _color;
}

std::string Shape::name() const
{
	return _name;
}


