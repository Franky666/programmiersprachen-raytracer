#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include "color.hpp"
#include "ray.hpp"

class Shape
{
	public:
			Shape();
			Shape(std::string const& name, Color const& color);
			virtual ~Shape();

			virtual double volume() const = 0;
			virtual double area() const = 0;

			Color const& color() const;
			std::string const& name() const;

			virtual std::ostream& print(std::ostream& os) const;

			virtual bool intersect(Ray const& ray, float& t) = 0;

	private:

	protected:
			std::string _name;
			Color _color;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif 
