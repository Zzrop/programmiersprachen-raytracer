#ifndef SHAPE_BUW_HPP
#define SHAPE_BUW_HPP
//#include "color.hpp"
#include "material.hpp"

class Shape
{
public:
	virtual ~Shape();

	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual std::ostream& print(std::ostream& os) const;
	std::string name() const;
	Material material() const;

protected:
	Shape();
	Shape(std::string const& name, Material const& material);


private:
	std::string name_;
	Material material_;	
};

std::ostream& operator<<(std::ostream& os, Shape const& s);	
#endif
