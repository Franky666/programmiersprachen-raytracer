#ifndef RAY_HPP
#define RAY_HPP
#include <glm/glm.hpp>
#include <iostream>

struct Ray
{
	glm::vec3 origin_;
	glm::vec3 direction_;

	Ray()
	: origin_{glm::vec3{0}}, direction_{glm::vec3{0}}
	{}

	Ray(glm::vec3 nOrigin, glm::vec3 nDirection)
	: origin_{nOrigin}, direction_{nDirection}
	{}
};

std::ostream& operator<<(std::ostream& os, Ray const& r);

#endif
