#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "shape.hpp"
#include <string>
#include <stdlib.h>
#include <glm/vec3.hpp>
#include "ray.hpp"

class Sphere: public Shape
{
	public: 
		//Constructor
		Sphere();
		~Sphere();
		Sphere(glm::vec3 const& mp, double r);
		Sphere(glm::vec3 const& mp, double r, std::string name, Material const& material);

		// get-methods
		glm::vec3 const& mp() const;
		double radius() const;

		double area() const override;
		double volume() const override;

    	std::ostream& print(std::ostream& os) const override;
    
		virtual bool intersect(Ray const& r, std::shared_ptr<HitRecord>& hit_record);

	private:
		glm::vec3 _mp;
		double _r;
};

#endif 
