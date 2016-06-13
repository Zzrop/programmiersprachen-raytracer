#ifndef BOX_BUW_HPP
#define BOX_BUW_HPP
#include <glm/vec3.hpp>


class Box : public Shape{

public:

	float area() const override;
	float volume() const override;

protected:
	glm::vec3 a_;
	glm::vec3 b_;

}
#endif