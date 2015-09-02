#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <iostream>
#include <glm/vec3.hpp>

class Camera
{
	public:
			// ctors dtors
			Camera();
			Camera(glm::vec3 const& direction, float fov);
			Camera(std::string const& name, float fov); 
			~Camera();

			// get-methods
			std::string const& name() const;
			glm::vec3 const& position() const;
			glm::vec3 const& direction() const;
			float fov() const;

			// setters
			void setName(std::string const& name);
			void setPosition(glm::vec3 const& position);
			void setDirection(glm::vec3 const& direction);
			void setFOV(float fov);

	private:
			glm::vec3 _position;
			glm::vec3 _direction;
			std::string _name;
			float _fov; // fov = field of view
			glm::vec3 upVector;

			
};


#endif
