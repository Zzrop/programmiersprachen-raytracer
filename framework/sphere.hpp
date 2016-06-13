#ifndef SPHERE_BUW_HPP
#define SPHERE_BUW_HPP
#include <glm/vec3.hpp>


class Sphere : public Shape{

public:
	float area() const override;
	float volume() const override;

protected:
	glm::vec3 m_;
	float r_;
}

#endif