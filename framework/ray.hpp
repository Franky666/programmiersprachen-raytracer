#ifndef BUW_RAY_HPP
#define BUW_RAY_HPP
#include <glm/glm.hpp>
struct Ray
{
	glm::vec3 origin_;
	glm::vec3 direction_;

	Ray(): origin_{glm::vec3{0}}, direction_{glm::vec3{0}}
	{}

	Ray(glm::vec3 nOrigin, glm::vec3 nDirection): origin_{nOrigin}, direction_{nDirection}
	{}
};

#endif // BUW_RAY_HPP
