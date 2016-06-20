#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
//#include "ray.hpp"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("test box", "[test box]")
{
	Color black{0.0,0.0,0.0};
	Box box1;
	glm::vec3 v1{0.0,0.0,0.0};
	glm::vec3 v2{1.0,1.0,1.0};
	REQUIRE(box1.min() == v1);
	REQUIRE(box1.max() == v2);
	REQUIRE(box1.volume() == 1.0);
	REQUIRE(box1.area() == 6.0);
	REQUIRE(box1.name() == "noname");
	REQUIRE(box1.color() == black);


	glm::vec3 v3{-1.0,-1.0,-1.0};
	glm::vec3 v4{1.0,1.0,1.0};
	Box box2{v3,v4};
	REQUIRE(box2.min() == v3);
	REQUIRE(box2.max() == v4);
	REQUIRE(box2.volume() == 8.0);
	REQUIRE(box2.area() == 24.0);
	REQUIRE(box2.name() == "noname");
	REQUIRE(box2.color() == black);

	Color red{1.0,0.0,0.0};
	Box box3{"red box", red, v3,v4};
	REQUIRE(box3.min() == v3);
	REQUIRE(box3.max() == v4);
	REQUIRE(box3.volume() == 8.0);
	REQUIRE(box3.area() == 24.0);
	REQUIRE(box3.name() == "red box");
	REQUIRE(box3.color() == red);
	std::cout << box3;
}

TEST_CASE("test sphere", "[test sphere]")
{
	Color black{0.0,0.0,0.0};
	Sphere sphere1;
	glm::vec3 v1{0.0,0.0,0.0};
	glm::vec3 v2{1.0,1.0,1.0};
	REQUIRE(sphere1.mid() == v1);
	REQUIRE(sphere1.volume() == Approx(0.5236));
	REQUIRE(sphere1.area() == Approx(3.14159));
	REQUIRE(sphere1.name() == "noname");
	REQUIRE(sphere1.color() == black);

	Sphere sphere2{v2, 1.0};
	REQUIRE(sphere2.mid() == v2);
	REQUIRE(sphere2.volume() == Approx(4.18879));
	REQUIRE(sphere2.area() == Approx(12.56637));
	REQUIRE(sphere2.name() == "noname");
	REQUIRE(sphere2.color() == black);

	Color green{0.0,1.0,0.0};
	Sphere sphere3{"green sphere", green, v2, 1.0};
	REQUIRE(sphere3.mid() == v2);
	REQUIRE(sphere3.volume() == Approx(4.18879));
	REQUIRE(sphere3.area() == Approx(12.56637));
	REQUIRE(sphere3.name() == "green sphere");
	REQUIRE(sphere3.color() == green);	
	std::cout << sphere3;
}

TEST_CASE("intersectRaySphere", "[intersect]")
{
	//Ray
	glm::vec3 ray_origin{0.0,0.0,0.0};
	//ray direction has to be normalized!
	//you can use:
	//v = glm::normalize(some_vector)
	glm::vec3 ray_direction{0.0,0.0,1.0};

	//Sphere
	glm::vec3 sphere_center{0.0,0.0,5.0};
	float sphere_radius{1.0};

	float distance{0.0};
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction, sphere_center, sphere_radius, distance);
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("Sphere intersect", "[sphere-intersect]")
{
	//Ray
	glm::vec3 ray_origin{0.0,0.0,0.0};
	//ray direction has to be normalized!
	//you can use:
	//v = glm::normalize(some_vector)
	glm::vec3 ray_direction1{0.0,0.0,1.0};
	glm::vec3 ray_direction2{1.0,0.0,0.0};

	//Sphere
	glm::vec3 sphere_center{0.0,0.0,5.0};
	float sphere_radius{1.0};

	Sphere s1{sphere_center,sphere_radius};

	float distance{0.0};
	Ray r1{ray_origin, ray_direction1};
	Ray r2{ray_origin, ray_direction2};
	REQUIRE(s1.intersect(r1,distance) == true);
	REQUIRE(s1.intersect(r2,distance) == false);
}

TEST_CASE("Virtual destruktor stuff", "[virtual]")
{
	Color red{255.0,0.0,0.0};
	glm::vec3 position{0.0};

	Sphere* s1 = new Sphere("sphere0",red, position, 1.2);
	Shape* s2 = new Sphere("sphere1",red, position, 1.2);

	s1->print(std::cout);
	s2->print(std::cout);

	delete s1;
	delete s2;
}

TEST_CASE("intersectRayBox", "[Box-intersect]")
{
	//Ray
	glm::vec3 ray_origin1{0.0,0.0,0.0};
	glm::vec3 ray_origin2{0.5,0.5,0.0};
	//ray direction has to be normalized!
	//you can use:
	//v = glm::normalize(some_vector)
	glm::vec3 ray_direction1{0.0,0.0,1.0};
	glm::vec3 ray_direction2{1.0,0.0,0.0};
	glm::vec3 v1{1.0,1.0,1.0};

	glm::vec3 ray_direction3 = glm::normalize(v1);


	//Sphere
	glm::vec3 min1{-0.5,-0.5,5.0};
	glm::vec3 min2{2.0,2.0,2.0};
	glm::vec3 max1{0.5,0.5,6.0};
	glm::vec3 max3{4.5,4.5,4.5};

	Box b1{min1,max1};
	Box b2{min2,max3};
	
	Ray r1{ray_origin1,ray_direction1};
	Ray r2{ray_origin1,ray_direction2};
	Ray r3{ray_origin2,ray_direction1};
	Ray r4{ray_origin1,ray_direction3};

	REQUIRE(b1.intersect(r1) == true);
	REQUIRE(b1.intersect(r2) == false);
	REQUIRE(b1.intersect(r3) == true);
	REQUIRE(b2.intersect(r4) == true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
