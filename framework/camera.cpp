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

void Camera::setName(std::string const& name) 
{
	_name = name;
}

void Camera::setPosition(glm::vec3 const& position)
{
	_position = position;
}

void Camera::setDirection(glm::vec3 const& direction) 
{
	_direction = direction;
}

void Camera::setFOV(float fov)
{
	_fov = fov;
}

// setters

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

float Camera::fov() const
{
	return _fov;
}
