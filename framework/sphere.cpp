#include "sphere.hpp"
#include "shape.hpp"
#include <cmath>
#include "glm/ext.hpp"



//Constructor
Sphere::Sphere()
:_mp{0.0f}, _r{0.0f}
{
}

Sphere::Sphere(glm::vec3 const& mp, double r)
: _mp{mp}, _r{r}
{
}

Sphere::Sphere(glm::vec3 const& mp, double r, std::string name, Color const& color)
: _mp{mp}, _r{r}, Shape(name, color)
{

}

Sphere::~Sphere()
{

}

glm::vec3 const& Sphere::mp() const
{
	return _mp;	
}

double Sphere::radius() const
{
	return _r;
}

double Sphere::volume() const
{
	return (4.0 / 3.0) * M_PI * _r * _r * _r;
}
double Sphere::area() const
{
	return 4.0 * M_PI * _r * _r;
}


std::ostream& Sphere::print(std::ostream& os) const
{
    os << "[Sphere: " << _name << "]\n[Color: " << _color << "]\n[Point: " << glm::to_string(_mp) << "]\n[radius: " << _r << "]\n";
    return os;
}

