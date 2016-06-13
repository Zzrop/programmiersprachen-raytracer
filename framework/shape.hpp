#ifndef SHAPE_BUW_HPP
#define SHAPE_BUW_HPP
#include "color.hpp"

class Shape
{
public:
	Shape();
	Shape(std::string const& name, Color const& color);

	virtual float area() const = 0;
	virtual float volume() const = 0;
	std::string name() const;
	Color color() const;

protected:
	std::string name_;
	Color color_;	
};
#endif
