#include "shape.hpp"

Shape::Shape()
	: name_{"noname"}
	, material_{}
	{
		//std::cout << "Default-Konstruktor-Aufruf fuer: " << name() << "\n";
	}

Shape::Shape(std::string const& n, Material const& mat)
	: name_{n}
	, material_{mat}
	{
	//	std::cout << "Konstruktor-Aufruf fuer: " << name() << "\n";
	}

Shape::~Shape() 
  {
//    std::cout << "Destruktor-Aufruf fuer: " << name() << "\n";
  }

std::string Shape::name() const
	{
		return name_;
	}

Material Shape::material() const
	{
		return material_;
	}	

std::ostream& Shape::print(std::ostream& os) const 
	{
    	os << "Name: " << name() << "\n"; 	//name_
    	os << "Material: " << material();
    	return os;
	}

std::ostream& operator<<(std::ostream& os, Shape const& s) 
	{
    	return s.print(os);
	}
