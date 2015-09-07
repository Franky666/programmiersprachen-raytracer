#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <color.hpp>
#include <glm/vec3.hpp>

class Light
{
	public:
			//ctors dtors
			Light();
			Light(std::string const& name, glm::vec3 const& position, Color const& la, Color const& ld);

			//get - methods
			std::string const& name() const;
			glm::vec3 const& position() const;
			Color ld() const;
			Color la() const;

			//outstream methods
			std:: ostream& print(std::ostream&) const;


	private:
			std::string _name;
			glm::vec3 _position;
			Color _ld;
			Color _la;

};

//operators
std::ostream& operator<<(std::ostream&, Light const&);

#endif
