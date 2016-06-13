#ifndef SHAPE_BUW_HPP
#define SHAPE_BUW_HPP

class Shape
{
public:
	Shape();

	virtual float area() const = 0;
	virtual float volume() const = 0;
};
#endif
