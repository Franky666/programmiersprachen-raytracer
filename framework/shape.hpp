#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include "color.hpp"


class Shape
{
	public:
			Shape();
			Shape(std::string name, Color const& color);
			virtual ~Shape();

			virtual double volume() const = 0;
			virtual double area() const = 0;

			Color color() const;
			std::string name() const;

	private:

	protected:
			std::string _name;
			Color _color;

};


#endif
