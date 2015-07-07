#ifndef BOX_HPP
#define BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>
#include <stdlib.h>
#include "shape.hpp"
#include "ray.hpp"

class Box : public Shape
{
    public:
        //Constructor
        Box();
        Box(glm::vec3 const&  min, glm::vec3 const& max);
        Box(glm::vec3 const&  min, glm::vec3 const& max, std::string name, Color color);
        ~Box();
    
    
        glm::vec3 const& min() const;
        glm::vec3 const& max() const;
    
        double volume() const override;
        double area() const override;
    
        std::ostream& print(std::ostream & os) const override;

		bool intersectBox(Ray, Box) const;

	private:
		glm::vec3 _min;
		glm::vec3 _max;
};

#endif
