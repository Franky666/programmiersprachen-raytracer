#include "box.hpp"
#include "shape.hpp"
#include <cmath>
#include "glm/ext.hpp"


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

glm::vec3 const& Box::min() const
{
	return _min;
}

glm::vec3 const& Box::max() const
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

std::ostream& Box::print(std::ostream& os) const
{
	os << "[Box: " << _name <<"}\n[Color: " << _color << "]\n[Min; " << glm::to_string(_min) << "]\n[Max: " << glm::to_string(_max) << "]\n";
	return os;
}

bool Box::intersectBox(Ray r, Box b) const
{
	double tx1 = (b._min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	double tx2 = (b._min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	
	double tnear = std::min(tx1, tx2);
	double tfar = std::max(tx1, tx2);

	double ty1 = (b._min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	double ty2 = (b._min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	
	tnear = std::min(ty1, ty2);
	tfar = std::max(ty1, ty2);

	double tz1 = (b._min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	double tz2 = (b._min.x - r.origin_.x)/glm::normalize(r.direction_).x;
	
	tnear = std::min(tz1, tz2);
	tfar = std::max(tz1, tz2);

	return tfar >= std::max(0.0, tnear);

}
