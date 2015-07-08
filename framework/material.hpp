#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <iostream>
#include "color.hpp"

class Material
{
	public:
		Material();
		Material(std::string const& name, Color ka, Color kd, Color ks, float const& m);
		~Material();
		
		//getter
		std::string const& name() const;
		Color const& ka() const;
		Color const& kd() const;
		Color const& ks() const;
		float const& m() const;
		

		friend std::ostream& operator<<(std::ostream& os, Material const& ma);

	private:
		std::string _name;
		Color _ka, _kd, _ks;
		float _m;

};


#endif
