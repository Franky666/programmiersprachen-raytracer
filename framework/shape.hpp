#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#include "material.hpp"
#include "ray.hpp"
#include <hitrecord.hpp>

class Shape
{
	public:
			//ctor dtor
			Shape();
			Shape(std::string const& name, Material const& material);
			virtual ~Shape();

			virtual double volume() const = 0;
			virtual double area() const = 0;

			Material const& material() const;
			std::string const& name() const;

			virtual std::ostream& print(std::ostream& os) const;

			virtual bool intersect(Ray const& ray, std::shared_ptr<HitRecord>& hit_record) = 0;

	private:

	protected:
			std::string _name;
			Material _material;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
