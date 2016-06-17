#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include <glm/vec3.hpp>

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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
