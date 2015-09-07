#ifndef HITRECORD_HPP
#define HITRECORD_HPP

#include <glm/vec3.hpp>
#include <memory>
#include <material.hpp>

struct HitRecord {
	float t;
	glm::vec3 position;
	glm::vec3 normal;
	std::shared_ptr<Material> material_ptr;
};

#endif
