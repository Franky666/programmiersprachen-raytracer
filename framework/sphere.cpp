#include "sphere.hpp"
#include "shape.hpp"
#include <cmath>

//Constructor
Sphere::Sphere()
:_mp{0.0f}, _r{0.0f}
{
}

Sphere::Sphere(glm::vec3 const& mp, double r, std::string name, Color const& color)
: _mp{mp}, _r{r}, Shape(name, color)
{

}

Sphere::~Sphere()
{

}

glm::vec3 Sphere::mp() const
{
	
}

double Sphere::radius() const
{
	return _r;
}

double Sphere::area() const
{
	return 4.0 * M_PI * _r * _r * _r;
}


