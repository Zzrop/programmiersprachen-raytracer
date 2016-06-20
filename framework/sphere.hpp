#ifndef SPHERE_BUW_HPP
#define SPHERE_BUW_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"
#include "ray.hpp"
#include <math.h>

class Sphere : public Shape{

public:
	Sphere();
	Sphere(glm::vec3 const& m , float r);
	Sphere(std::string const& name, Color const& color, glm::vec3 const& m , float r);
	~Sphere();


	float area() const override;
	float volume() const override;

	glm::vec3 const& mid() const;
	float r() const;

	bool intersect(Ray const& ray, float& distance) const;

	std::ostream& print(std::ostream& os) const;

protected:
	glm::vec3 center_;
	float r_;
};

#endif
