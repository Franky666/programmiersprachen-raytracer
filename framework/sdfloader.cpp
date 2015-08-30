#include <sdfloader.hpp>

#include <fstream>
#include <string>
#include <sstream>

SDFLoader::SDFLoader(std::string const& filename)
: _filename(filename), _scene()
{}

Scene 
SDFLoader::load()
{
	Scene scene;
	
	std::ifstream infile(_filename);
	std::string line;
	while(std::getline(infile, line)) {

	}

	return scene;
}
