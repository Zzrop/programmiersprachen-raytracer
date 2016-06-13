#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include <glm/vec3.hpp>

TEST_CASE("test box", "[test box]")
{
	Box box1;
	glm::vec3 v1{0.0,0.0,0.0};
	glm::vec3 v2{1.0,1.0,1.0};
	REQUIRE(box1.min() == v1);
	REQUIRE(box1.max() == v2);
	REQUIRE(box1.volume() == 1.0);
	REQUIRE(box1.area() == 6.0);


	glm::vec3 v3{-1.0,-1.0,-1.0};
	glm::vec3 v4{1.0,1.0,1.0};
	Box box2{v3,v4};
	REQUIRE(box2.min() == v3);
	REQUIRE(box2.max() == v4);
	REQUIRE(box2.volume() == 8.0);
	REQUIRE(box2.area() == 24.0);
}

TEST_CASE("test sphere", "[test sphere]")
{
	Sphere sphere1;
	glm::vec3 v1{0.0,0.0,0.0};
	glm::vec3 v2{1.0,1.0,1.0};
	REQUIRE(sphere1.mid() == v1);
//	REQUIRE(sphere1.volume() == 1.0);
//	REQUIRE(sphere1.area() == 6.0);

	Sphere sphere2{v2, 2.0};
	REQUIRE(sphere2.mid() == v2);
//	REQUIRE(sphere2.volume() == 8.0);
//	REQUIRE(sphere2.area() == 24.0);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
