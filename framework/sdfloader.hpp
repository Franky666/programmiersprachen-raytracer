#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP
#include <string>
#include <scene.hpp>
#include <sstream>
#include <material.hpp>
#include <box.hpp>
#include <sphere.hpp>
#include <scene.hpp>
#include <camera.hpp>
#include <light.hpp>

class SDFLoader{
	
	public:
			//ctor dtor
			SDFLoader();
			SDFLoader(std::string const& filename);
			SDFLoader(std::string path, std::string filename);
			~SDFLoader();
			
			void load();

	private:
			void render(std::vector<std::string> const& tokens);
			void add_camera(std::vector<std::string> const& tokens);
			void define(std::vector<std::string> const& tokens);
			void define_sphere(std::vector<std::string> const& tokens);
			void define_box(std::vector<std::string> const& tokens);
			void define_shape(std::vector<std::string> const& tokens);
			void define_material(std::vector<std::string> const& tokens);
			void define_light(std::vector<std::string> const& tokens);

	private:
			Scene _scene;
			std::string _filename;
};
#endif
