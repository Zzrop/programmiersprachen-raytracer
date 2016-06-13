#ifndef BOX_BUW_HPP
#define BOX_BUW_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape {

public:
	Box();
	Box(glm::vec3 const& a, glm::vec3 const& b);

	float area() const override;
	float volume() const override;
	glm::vec3 const& min() const;
	glm::vec3 const& max() const;

protected:
	glm::vec3 min_;
	glm::vec3 max_;

};
#endif