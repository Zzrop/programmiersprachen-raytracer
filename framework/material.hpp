#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP

#include <iostream>
#include "color.hpp"

struct Material
{
	Material(std::string const& n, Color const& a, Color const& d, Color const& s, float o):
	name(n),
	ka(a),
	kd(d),
	ks(s),
	m(o)
	{}

	Material():
	name("no mat name"),
	ka{},
	kd{},
	ks{},
	m{1.0}
	{}

	Material(std::string const& n, Color const& c):
	name(n),
	ka{c},
	kd{c},
	ks{c},
	m{1.0}
	{}

	std::string name;
	Color ka, kd, ks;
	float m;

	friend std::ostream& operator<<(std::ostream& os, Material const& mat)
	{
		os << " " << mat.name <<" \n"  << "Ambiente: " << mat.ka << "Difus: " << mat.kd <<"Specular: " << mat.ks << "Opacity: " << mat.m <<" \n";
		return os;
	}

	bool operator==(Material const& rhs) {
    return(name == rhs.name && ka == rhs.ka && kd == rhs.kd && ks == rhs.ks && m == rhs.m);
  }
};

#endif