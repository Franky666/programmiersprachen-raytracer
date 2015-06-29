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

std::ostream& Shape::print(std::ostream& os) const
{
	os << "Shape: [Name: " << _name << "] [Color: " << _color << "] \n ";
	return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}
