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

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string name, Material material)
: _max{max}, _min{min}, Shape(name, material)
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
	os << "[Box: " << _name <<"}\n[Material: " << _material << "]\n[Min; " << glm::to_string(_min) << "]\n[Max: " << glm::to_string(_max) << "]\n";
	return os;
}

bool Box::intersect(Ray const& r, std::shared_ptr<HitRecord>& hit_record)
{
	float dirfrac_x = 1.0f / r.direction_.x;
	float dirfrac_y = 1.0f / r.direction_.y;
	float dirfrac_z = 1.0f / r.direction_.z;

	float t1x = (_min.x - r.origin_.x) * dirfrac_x;
	float t2x = (_max.x - r.origin_.x) * dirfrac_x;

	float t1y = (_min.y - r.origin_.y) * dirfrac_y;
	float t2y = (_max.y - r.origin_.y) * dirfrac_y;

	float t1z = (_min.z - r.origin_.z) * dirfrac_z;
	float t2z = (_max.z - r.origin_.z) * dirfrac_z;

	float tmin = std::max(std::max(std::min(t1x, t2x), std::min(t1y, t2y)), std::min(t1z, t2z));
	float tmax = std::min(std::min(std::max(t1x, t2x), std::max(t1y, t2y)), std::max(t1z, t2z));

	// box is behind ray origin
	if(tmax < 0)
	{
		//hit_record->t = tmax;
		return false;
	}
	
	// if tmin > tmax, ray doesn't intersect AABB
	if(tmin > tmax)
	{
		//hit_record->t = tmax;
		return false;
	}

	// fill hit_record for shading information
	hit_record->t = tmin;

	hit_record->position = glm::vec3{hit_record->t * r.direction_};

	// find normal
	float eps = 0.0001f;
	if (std::abs(hit_record->position.x - t1x) < eps)
		hit_record->normal = glm::vec3{-1, 0, 0};
	else if (std::abs(hit_record->position.x - t2x) < eps)
		hit_record->normal = glm::vec3{1, 0, 0};
	else if (std::abs(hit_record->position.y - t1y) < eps)
		hit_record->normal = glm::vec3{0, -1, 0};
	else if (std::abs(hit_record->position.y - t2y) < eps)
		hit_record->normal = glm::vec3{0, 1, 0};
	else if (std::abs(hit_record->position.z - t1z) < eps)
		hit_record->normal = glm::vec3{0, 0, -1};
	else if (std::abs(hit_record->position.z - t2z) < eps)
		hit_record->normal = glm::vec3{0, 0, 1};

	hit_record->material_ptr = std::make_shared<Material>(_material);

	return true;
}
