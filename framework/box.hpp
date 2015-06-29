#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape
{
	//Constructor
	Box();
	Box(glm::vec3 const&  min, glm::vec3 const& max);
	~Box();	


	glm::vec3 min() const;
	glm::vec3 max() const;

	double volume() const override;

	double area() const override;


	private:
		glm::vec3 _min;
		glm::vec3 _max;
};

#endif
