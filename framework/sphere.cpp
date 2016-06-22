#include "sphere.hpp"
#include <glm/gtx/intersect.hpp>

Sphere::Sphere()
  : Shape(), center_{glm::vec3{0.0,0.0,0.0}}, r_{0.5}{}

Sphere::Sphere(glm::vec3 const& m, float r)
  : Shape()
  , center_{m}
  , r_{r}
 {}

Sphere::Sphere(std::string const& n, Color const& color, glm::vec3 const& m, float r)
  : Shape(n,color)
  , center_{m}
  , r_{r}
 {std::cout << "Sphere-Konstruktor-Aufruf fuer: " << name() << "\n";}

Sphere::~Sphere(){std::cout << "Sphere-Destruktor-Aufruf fuer: " << name() << "\n";}

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

std::ostream& Sphere::print(std::ostream& os) const 
  {
    Shape::print(os);    
    os << "Mittelpunkt: (" << mid().x << "," << mid().y << "," << mid().z << ") \n"; //glm::to_string(glm::vec3)
    os << "Radius: " << r() << "\n";
    os << "Flaecheninhalt: " << area() << "\n";
    os << "Volumen: " << volume() << "\n \n";
    return os;
  } 

bool Sphere::intersect(Ray const& ray, float& distance) const 
  {
    return glm::intersectRaySphere(ray.origin, glm::normalize(ray.direction), center_, r_ * r_, distance);
  }