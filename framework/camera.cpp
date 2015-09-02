#include "camera.hpp"

//ctor dtor
Camera::Camera()
: _position{0.0},
  _direction{0.0, 0.0, -1.0},
  _fov(40.0)
{
	//implement me!
}

Camera::Camera(glm::vec3 const& direction, float fov)
: _direction{direction},
  _fov{fov}
{
	//implement me!
}

Camera::Camera(std::string const& name, float fov)
: _name(name),
  _fov(fov)
{
	//implement me!
}

Camera::~Camera()
{}


//get-methods

std::string const& Camera::name() const
{
	return _name;
}

glm::vec3 const& Camera::position() const
{
	return _position;
}

glm::vec3 const& Camera::direction() const
{
	return _direction;
}
