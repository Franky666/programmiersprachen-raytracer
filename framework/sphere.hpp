#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere: public Shape
{
	//Constructor
	Sphere();
	Sphere(glm::vec3 mp, float r);

	private:
		glm::vec3 _mp;
		float _r;
};

#endif 
