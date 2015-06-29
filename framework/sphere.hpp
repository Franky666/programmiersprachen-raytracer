#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere: public Shape
{
	//Constructor
	Sphere();
	~Sphere();
	Sphere(glm::vec3 const& mp, float r);
	Sphere(glm::vec3 const& mp, double r, std::string name, Color const& color);

	glm::vec3 mp() const;
	double radius() const;

	double area() const override;
	double volume() const override;



	private:
		glm::vec3 _mp;
		double _r;
};

#endif 
