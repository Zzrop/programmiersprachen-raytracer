#include "sphere.hpp"

Sphere::Sphere()
  : Shape(), center_{glm::vec3{0.0,0.0,0.0}}, r_{0.5}{}

Sphere::Sphere(glm::vec3 const& m, float r)
  : Shape()
  , center_{m}
  , r_{r}
 {}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& m, float r)
  : Shape(name,color)
  , center_{m}
  , r_{r}
 {}


float Sphere::area() const
{
	return 4*M_PI*pow(r_,2.0);
}

float Sphere::volume() const
{
	return (4.0/3.0) * M_PI * pow(r_, 3.0);
}

glm::vec3 const& Sphere::mid() const {
	return center_;
}

float Sphere::r() const {
	return r_;
}