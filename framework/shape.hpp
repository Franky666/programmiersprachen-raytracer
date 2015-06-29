#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
	public:
			Shape();
			virtual ~Shape();

			virtual double volume() const = 0;
			virtual double area() const = 0;

};


#endif
