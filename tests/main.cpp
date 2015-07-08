#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <iostream>


TEST_CASE("Box","[Box]")
{
	Box b1{};

	REQUIRE(b1.min().x == 0);
	REQUIRE(b1.min().y == 0);
	REQUIRE(b1.min().z == 0);

	REQUIRE(b1.max().x == 1.0f);
	REQUIRE(b1.max().y == 1.0f);
	REQUIRE(b1.max().z == 1.0f);

	glm::vec3 max{6};
	glm::vec3 min{3};
	Box b2{min, max};

	REQUIRE(b2.min().x == 3);
	REQUIRE(b2.min().y == 3);
	REQUIRE(b2.min().z == 3);

	REQUIRE(b2.max().x == 6);
	REQUIRE(b2.max().y == 6);
	REQUIRE(b2.max().z == 6);

	REQUIRE(b2.area() == 54);
	REQUIRE(b2.volume() == 27);

	Color red(255,0,0);
	//Box b3{min, max, "b3", red};
	
	//REQUIRE(b3.name() == "b3");
	//REQUIRE(b3.color() == red);

}

TEST_CASE("ostream","[ostream]")
{
	Color black(0,0,0);
	glm::vec3 max{6};
	glm::vec3 min{3};
	Box b1{max, min, "b", black};

	double r = 3;
	glm::vec3 v{3};

	std::cout << b1 << "\n";
}

TEST_CASE("intesersect", "[intersect]")
{
	Color black(0,0,0);
	glm::vec3 max{8};
	glm::vec3 min{4};
	Box b2{max, min, "b2", black};

	
	Ray r1{glm::vec3{2},glm::vec3{3}};		
	Ray r2{glm::vec3{9},glm::vec3{4}};
	Ray r3{glm::vec3{3},glm::vec3{15}};
	float t = 0;
	// hit
	REQUIRE(b2.intersect(r1, t) == true);
	// behind box - no hit
	REQUIRE(b2.intersect(r2, t) == false);
	// no hit
	REQUIRE(b2.intersect(r3, t) == true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
