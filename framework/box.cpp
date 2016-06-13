#include "box.hpp"

Box::Box()
  : Shape()
  , min_{glm::vec3{0.0,0.0,0.0}}
  , max_{glm::vec3{1.0,1.0,1.0}}
 {}

Box::Box(glm::vec3 const& a, glm::vec3 const& b)
  : Shape()
  , min_{a}
  , max_{b}
 {}

float Box::area() const
{
	return -1.0f;
}

float Box::volume() const
{
	return -1.0f;
}

glm::vec3 const& Box::min() const {
	return min_;
}

glm::vec3 const& Box::max() const {
	return max_;
}