#include "sphere.hpp"
#include "shape.hpp"
#include <cmath>
#include "glm/ext.hpp"
//temp
#include <iostream>



//Constructor
Sphere::Sphere()
:_mp{0.0f}, _r{0.0f}
{
}

Sphere::Sphere(glm::vec3 const& mp, double r)
: _mp{mp}, 
  _r{r}
{
}

Sphere::Sphere(glm::vec3 const& mp, double r, std::string name, Material const& material)
: _mp{mp}, 
  _r{r}, 
  Shape(name, material)
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


bool Sphere::intersect(Ray const& r, float& t) 
{

	return glm::intersectRaySphere(r.origin_, glm::normalize(r.direction_), _mp, _r, t);
	/*
	glm::vec3 norm, intersect;
	
	float L_x = _mp.x - r.origin_.x;
	float L_y = _mp.y - r.origin_.y;
	float L_z = _mp.z - r.origin_.z;


	// L = distance camera & _mp
	glm::vec3 L =  _mp - r.origin_;	
	glm::vec3 tc = L * r.direction_;
	std::cout << tc.z << std::endl;
	
	return true;
	*/
}

std::ostream& Sphere::print(std::ostream& os) const
{
	os << "[Sphere: " << _name << "]\n[Material: " << _material << "]\n[Point: " << glm::to_string(_mp) << "\n[Radius: " << _r << "]\n";

	return os;
}
