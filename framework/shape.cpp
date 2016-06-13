#include "shape.hpp"

Shape::Shape()
	: name_{"noname"}
	, color_{Color{0.0,0.0,0.0}}
	{}

Shape::Shape(std::string const& name, Color const& color)
	: name_{name}
	, color_{color}
	{}

std::string Shape::name() const
	{
		return name_;
	}

Color Shape::color() const
	{
		return color_;
	}	