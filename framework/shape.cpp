#include "shape.hpp"

Shape::Shape()
	: name_{"noname"}
	, color_{Color{0.0,0.0,0.0}}
	{
		std::cout << "Default-Konstruktor-Aufruf fuer: " << name() << "\n";
	}

Shape::Shape(std::string const& n, Color const& color)
	: name_{n}
	, color_{color}
	{
		std::cout << "Konstruktor-Aufruf fuer: " << name() << "\n";
	}

Shape::~Shape() 
  {
    std::cout << "Destruktor-Aufruf fuer: " << name() << "\n";
  }

std::string Shape::name() const
	{
		return name_;
	}

Color Shape::color() const
	{
		return color_;
	}	

std::ostream& Shape::print(std::ostream& os) const 
	{
    	os << "Name: " << name() << "\n";
    	os << "Color: " << color();
    	return os;
	}

std::ostream& operator<<(std::ostream& os, Shape const& s) 
	{
    	return s.print(os);
	}
