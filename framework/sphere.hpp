#ifndef SPHERE_BUW_HPP
#define SPHERE_BUW_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"
#include <math.h>

class Sphere : public Shape{

public:
	Sphere();
	Sphere(glm::vec3 const& m , float r);

	float area() const override;
	float volume() const override;

	glm::vec3 const& mid() const;
	float r() const;

protected:
	glm::vec3 center_;
	float r_;
};

#endif