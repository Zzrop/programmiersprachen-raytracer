#ifndef BOX_BUW_HPP
#define BOX_BUW_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"
#include <math.h>
#include "ray.hpp"

class Box : public Shape {

public:
	Box();
	Box(glm::vec3 const& a, glm::vec3 const& b);
	Box(std::string const& name, Color const& color, glm::vec3 const& a, glm::vec3 const& b);

	float area() const override;
	float volume() const override;
	glm::vec3 const& min() const;
	glm::vec3 const& max() const;

	bool intersect(Ray const& ray) const;

	std::ostream& print(std::ostream& os) const override;	

protected:
	glm::vec3 min_;
	glm::vec3 max_;

};
#endif