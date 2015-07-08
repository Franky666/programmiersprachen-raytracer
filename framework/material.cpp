#include "material.hpp"

Material::Material()
: _name{"untitled"}, _ka{0.0f, 0.0f, 0.0f}, _kd{0.0f, 0.0f, 0.0f}, _ks{0.0f, 0.0f, 0.0f}, _m{0.0}
{
}

Material::~Material()
{
}

Material::Material(std::string const& name, Color ka, Color kd, Color ks, float const& m)
: _name{name}, _ka{ka}, _kd{kd}, _ks{ks}, _m{m}
{}

std::string const& Material::name() const
{
	return _name;
}

Color Material::ka() const
{
	return _ka;
}

Color Material::kd() const
{
	return _kd;
}

Color Material::ks() const
{
	return _ks;
}

float Material::m() const
{
	return _m;
}

std::ostream& operator<<(std::ostream& os, Material const& ma)
{
	os << "[" << ma._name << ma._ka << "," << ma._kd << "," << ma._ks << "," << ma._m << "]";
}
