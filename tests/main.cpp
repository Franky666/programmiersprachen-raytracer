#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <iostream>

#include <sdfloader.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>

/*
TEST_CASE("intesersect", "[intersect]")
{
	Material black{};
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

TEST_CASE("material", "[material]")
{
	Color red(255,0,0);
	Color black(0.0f, 0.0f, 0.0f);	

	// default c'tor
	Material m1{};
	//name
	REQUIRE(m1.name() == "untitled");
	// colors ka, kd, ks = standaarts
	REQUIRE(m1.ka() == black);	
	REQUIRE(m1.kd() == black);
	REQUIRE(m1.ks() == black);


	// user c'tor
	Material m2{"material", black, red, red, 0.0};
	//name
	REQUIRE(m2.name() == "material");
	// colors ka, kd, ks 
	REQUIRE(m2.ka() == black);	
	REQUIRE(m2.kd() == red);
	REQUIRE(m2.ks() == red);

}

TEST_CASE("sdfloader_material", "[sdfloader]")
{
	std::ifstream infile("/Users/Franky/repos/PLSE_2015/programmiersprachen-raytracer/tests/sdffile.txt");
	std::string line;
	std::vector<Material> materials;
	while(std::getline(infile, line)) {
		std::istringstream iss(line);
		std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
										std::istream_iterator<std::string>{}};

		if (tokens.size() > 2 
			&& tokens.at(0) == "define"
			&& tokens.at(1) == "material") {
			if(tokens.size() == 13) {
				std::string material_name = tokens.at(2);
				Color ka{std::stof(tokens.at(3)), std::stof(tokens.at(4)), std::stof(tokens.at(5))};
				Color kd{std::stof(tokens.at(6)), std::stof(tokens.at(7)), std::stof(tokens.at(8))};
				Color ks{std::stof(tokens.at(9)), std::stof(tokens.at(10)), std::stof(tokens.at(11))};
				float m = std::stof(tokens.at(12));
				Material material{material_name, ka, kd, ks, m};
				materials.push_back(material);
			} else {
				std::cerr << "invalid material definition found" << std::endl;
			}
		}
    }
	REQUIRE(materials.at(0).name() == "red");
	REQUIRE(materials.at(0).ka() == Color(1, 0, 0));
	REQUIRE(materials.at(0).kd() == Color(1, 0, 0));
	REQUIRE(materials.at(0).ks() == Color(1, 0, 0));
	REQUIRE(materials.at(0).m() == 1);

	REQUIRE(materials.at(1).name() == "blue");
	REQUIRE(materials.at(1).ka() == Color(0, 0, 1));
	REQUIRE(materials.at(1).kd() == Color(0, 0, 1));
	REQUIRE(materials.at(1).ks() == Color(0, 0, 1));
	REQUIRE(materials.at(1).m() == 1);
}
*/


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
