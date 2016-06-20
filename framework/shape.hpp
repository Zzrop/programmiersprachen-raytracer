#ifndef SHAPE_BUW_HPP
#define SHAPE_BUW_HPP
#include "color.hpp"

class Shape
{
public:
	/*virtual*/ ~Shape();

	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual std::ostream& print(std::ostream& os) const;
	std::string name() const;
	Color color() const;

protected:
	Shape();
	Shape(std::string const& name, Color const& color);


private:
	std::string name_;
	Color color_;	
};

std::ostream& operator<<(std::ostream& os, Shape const& s);	
#endif
