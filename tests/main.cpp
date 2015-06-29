#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <iostream>


TEST_CASE("Sphere","[Sphere]")
{
	Sphere s1{};

	REQUIRE(s1.radius() == 0);
	REQUIRE(s1.mp().x == 0);
	REQUIRE(s1.mp().y == 0);
	REQUIRE(s1.mp().z == 0);

	double r = 3;
	glm::vec3 v{3};
	Sphere s2{v, r};

	REQUIRE(s2.radius() == 3);
	REQUIRE(s2.mp().x == 3);
	REQUIRE(s2.mp().y == 3);
	REQUIRE(s2.mp().z == 3);
	REQUIRE(Approx(s2.volume()) == 113.097);
	REQUIRE(Approx(s2.area()) == 113.097);


	Color red(255 , 0 , 0);
	glm::vec3 position (0);
	Sphere s3{v, r, "s3", red};

	REQUIRE(s3.name() == "s3");
	//REQUIRE(s3.color() == red);
}

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
	Box b2{max, min};

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

	std::cout << "===========================\n";
	std::cout << "======= Aufgabe 6.5 =======\n";
	std::cout << "===========================\n";

	Color black(0,0,0);
	glm::vec3 max{6};
	glm::vec3 min{3};
	Box b1{max, min, "b", black};

	double r = 3;
	glm::vec3 v{3};
	Sphere s1{v, r, "s", black};

	std::cout << b1 << "\n";
	std::cout << s1 << "\n";


}



TEST_CASE("intersectRaySphere","[intersect]")
{
	//Ray
	glm::vec3 ray_origin(0.0 ,0.0 ,0.0);
	
	glm::vec3 ray_direction(0.0 ,0.0 ,1.0);
	// Sphere
	
	glm::vec3 sphere_center(0.0 ,0.0 ,5.0);
	
	float sphere_radius(1.0);
	
	float distance(0.0);
	
	auto result = glm::intersectRaySphere(ray_origin ,ray_direction,sphere_center,sphere_radius,distance);
	
	REQUIRE(distance == Approx(4.0f));
}


TEST_CASE("Aufgabe6_8", "[Aufgabe6_8]")
{	
	std::cout << "===========================\n";
	std::cout << "======= Aufgabe 6.8 =======\n";
	std::cout << "===========================\n";
	Color red(255 , 0 , 0);
	glm::vec3 position (0);

	Sphere* s1 = new Sphere(position,1.2,"sphere0",red);
	Shape* s2 = new Sphere(position,1.2,"sphere1",red);
	s1 -> print(std::cout);
	s2 -> print(std::cout);
	delete s1;
	delete s2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
