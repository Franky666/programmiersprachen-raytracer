#include <string>
#include <scene.hpp>

class SDFLoader {
	
	public:
			//ctor dtor
			SDFLoader();
			SDFLoader(std::string const& filename);
			SDFLoader(std::string path, std::string filename);
			~SDFLoader();
			
			Scene load();

			void readSDF(std::string const& path);
			void create_composite(std::istringstream&);
			void create_material(std::istringstream&);
			void create_sphere(std::istringstream&);
			void create_box(std::istringstream&);
			void create_light(std::istringstream&);
			void create_ambiet(std::istringstream&);
			void issprint(std::istringstream&);

	private:
			Scene _scene;
			std::string _filename;
			std::string _path;
};
