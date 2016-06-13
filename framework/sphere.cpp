#include "sphere.hpp"

Sphere::Sphere()
  : Shape(), center_{glm::vec3{0.0,0.0,0.0}}, r_{0.0}{}

Sphere::Sphere(glm::vec3 const& m, float r)
  : Shape()
  , center_{m}
  , r_{r}
 {}

float Sphere::area() const
{
	return -1.0f;
}

float Sphere::volume() const
{
	return -1.0f;
}

glm::vec3 const& Sphere::mid() const {
	return center_;
};

float Sphere::r() const {
	return r_;
};