#include <sdfloader.hpp>

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

// ctor dtor
SDFLoader::SDFLoader(std::string const& filename)
: _filename(filename), 
  _scene()
{}

SDFLoader::SDFLoader(std::string path, std::string filename)
: _path(path),
  _filename(filename)
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

void 
SDFLoader::readSDF(std::string const& path)
{
	std::ifstream file;
	std::string s;

	file.open(path, std::ios::in);

	while(!file.eof())
	{
		getline(file, s);

		std::istringstream iss{s};
		std::string sub;
		iss >> sub;
	

        if(sub == "define")
        {
            iss >> sub;
            
            if(sub == "material")
            {
                create_material(iss);
            }
            else if(sub == "shape")
            {
                iss >> sub;
                
                if(sub == "sphere")
                {
                    create_sphere(iss);
                }
                else if(sub == "box")
                {
                    //create_box(iss);
                }
                else if(sub == "composite")
                {
                    create_composite(iss);
                }
            }
            else if(sub == "light")
            {
                iss >> sub;
                if(sub == "diffuse")
                {
                    create_light(iss);
                }
                else if(sub == "ambient")
                {
                    //create_ambient(iss);
                }
            }
            else if(sub == "camera")
            {
                //create_cam(iss);
            }
        }
	}
}


void
create_composite(std::istringstream&)
{

}

void
create_material(std::istringstream& iss)
{
	std::string name;
	float r, g, b, m;
	iss >> name >> r >> g >> b;
	Color ka(r, g, b);
	
	iss >> r >> g >> b;
	Color kd(r, g, b);

	iss >> r >> g >> b >> m;
	Color ks(r, g, b);

	Material material = Material(name, ka, kd, ks, m);
}

void
create_sphere(std::istringstream& iss)
{
	/*std::string name, materialName;
	float x, y, z, r;

	iss >> name >> x >> y >> z;
	glm::vec3 mp(x, y, z);

	iss >> r;

	iss >> materialName;

	std::shared_ptr<Material> ma = _scene.getMaterial(materialName);
	std::shared_ptr<Shape> sphere = std::make_shared<Sphere>(Sphere(name, ma, mp, r));

	_scene.addShape(name, sphere);

	std::cout << name << " added " << std::endl;
	*/
}



void
issprint(std::stringstream&)
{
	
}
