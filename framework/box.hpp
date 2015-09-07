#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
#include <stdlib.h>
#include "ray.hpp"

class Box : public Shape
{
    public:
        //Constructor
        Box();
        Box(glm::vec3 const&  min, glm::vec3 const& max);
        Box(glm::vec3 const&  min, glm::vec3 const& max, std::string name, Material material);
        ~Box();
    
    
        glm::vec3 const& min() const;
        glm::vec3 const& max() const;
    
        double volume() const override;
        double area() const override;
    
        std::ostream& print(std::ostream & os) const override;

		virtual bool intersect(Ray const& ray, std::shared_ptr<HitRecord>& hit_record);

	private:
		glm::vec3 _min;
		glm::vec3 _max;
};

#endif
