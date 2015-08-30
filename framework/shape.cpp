#include "shape.hpp"
#include <iostream>
#include <string>

Shape::Shape()
: _name{"untitled"}, _material{"untitled material"}, Color{}, Color{}, Color{}, 0.0f}

Shape::Shape(std::string const& name, Material const& material)
: _name{name}, _material{material}
{}

Shape::~Shape()
{
}

Material const& Shape::material() const
{
	return _material;
}

std::string const& Shape::name() const
{
	return _name;
}

std::ostream& Shape::pring(std::ostream& os) const
{
	os << "Shape: [Name: " << _name << "] [Material: " << _material << "] \n ";
	return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}
