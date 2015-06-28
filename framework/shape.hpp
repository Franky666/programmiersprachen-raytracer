#ifndef SHAPE_HPP
#define SHAPE_HPP

class shape
{
	public:
			shape();
			virtual ~shape();

			virtual float volume() const = 0;
			virtual float area() const = 0;

}


#endif
