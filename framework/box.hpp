#ifndef BOX_BUW_HPP
#define BOX_BUW_HPP


class Box : public Shape{

public:
	
	float area() const override;
	float volume() const override;
}
#endif