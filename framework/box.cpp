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

std::ostream& Box::print(std::ostream& os) const 
  {
    Shape::print(os);    
    os << "Min: (" << min().x << "," << min().y << "," << min().z << ") \n";
    os << "Max: (" << max().x << "," << max().y << "," << max().z << ")\n";
    os << "Flaecheninhalt: " << area() << "\n";
    os << "Volumen: " << volume() << "\n \n";
    return os;
  } 

  bool Box::intersect(Ray const& ray) const {

    float t1 = (max_.x - ray.origin.x) *(1.0/ray.direction.x);
    float t2 = (min_.x - ray.origin.x) *(1.0/ray.direction.x);
    float t3 = (max_.y - ray.origin.y) *(1.0/ray.direction.y);
    float t4 = (min_.y - ray.origin.y) *(1.0/ray.direction.y);
    float t5 = (max_.z - ray.origin.z) *(1.0/ray.direction.z);
    float t6 = (min_.z - ray.origin.z) *(1.0/ray.direction.z);

    //Range on x-Ebene for possible intersection
    float tmax = std::max(t1,t2);
    float tmin = std::min(t1,t2);
    //Range on y-Ebene for possible intersection after looking on x-Ebene
    tmax = std::min(std::max(t3,t4),tmax);
    tmin = std::max(std::min(t3,t4),tmin);
    //Range on z-Ebene for possible intersection after looking on x and y
    tmax = std::min(std::max(t5,t6),tmax);
    tmin = std::max(std::min(t5,t6),tmin);


    if (tmax > std::max(0.0f, tmin))
    {
        return true;
    }

    return false;

}
