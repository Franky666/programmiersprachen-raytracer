#include "box.hpp"
#include <cmath>

//Constructor
Box::Box()
: _min{0.0f}, _max{1.0f}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max)
: _min{min}, _max{max}
{}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Color color)
: _max{max}, _min{min}, Shape(name, color)
{}

Box::~Box()
{}

glm::vec3 Box::min() const
{
	return _min;
}

glm::vec3 Box::max() const
{
	return _max; 
}

double Box::volume() const
{
	glm::vec3 vec = _max - _min;
	return fabs(vec.x * vec.y * vec.z);
}

double Box::area() const
{
	glm::vec3 vec = _max - _min;

	return 2 * fabs((vec.x * vec.y) + (vec.x * vec.z) + (vec.y * vec.z));
}
