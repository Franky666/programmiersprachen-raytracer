#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <iostream>
#include "color.hpp"

class Material
{
	public:
			//ctor dtor
			Material();
			Material(std::string const& name, Color ka, Color kd, Color ks, float const& m);
			~Material();

			//getter
			std::string const& name() const;
			Color ka() const;
			Color kd() const;
			Color ks() const;
			float m() const;

			friend std::ostream& operator<<(std::ostream& os, Material const& ma);

	private:
			std::string _name;
			Color _ka, _kd, _ks;
			float _m;
};

#endif
