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

Box::Box(std::string const& name, Color const& color, glm::vec3 const& a, glm::vec3 const& b)
  : Shape(name, color)
  , min_{a}
  , max_{b}
 {}
 
float Box::area() const
{
	return 2*(max_.x - min_.x)*(max_.z - min_.z)+ 2*(max_.x - min_.x)*(max_.y - min_.y) + 2*(max_.y - min_.y)*(max_.z - min_.z);
}

float Box::volume() const
{
	return (max_.x - min_.x) * (max_.y - min_.y) * (max_.z - min_.z);
}

glm::vec3 const& Box::min() const {
	return min_;
}

glm::vec3 const& Box::max() const {
	return max_;
}