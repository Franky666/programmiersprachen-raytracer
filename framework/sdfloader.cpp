#include <sdfloader.hpp>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <thread>
#include <renderer.hpp>
#include <fensterchen.hpp>

// ctor dtor
SDFLoader::SDFLoader()
{}

SDFLoader::SDFLoader(std::string const& filename)
: _filename(filename), 
  _scene()
{}

void
SDFLoader::render(std::vector<std::string> const& tokens)
{

// parse tokens
	//load();
	
	std::string camera_name = tokens[1];
	std::string ppm_filename = tokens[2];
	unsigned int width = std::stoi(tokens[3]);
	unsigned int height = std::stoi(tokens[4]);


	// fetch camera by name from scene:
	
	std::shared_ptr<Camera> camera;
	for(auto camera_ptr : _scene.cameras()) {
	    if (camera_ptr->name() == camera_name) { 
			camera = camera_ptr;
		}
	}
	if (!camera)
		throw std::runtime_error("SDF error, camera not found");

 	std::cout << "Creating renderer object..." << std::endl;
	Renderer renderer(width, height, ppm_filename);
	
    std::thread thr([&renderer, this, &camera]() { renderer.render(_scene, *camera); });

  // std::thread thr([&app]() { sdfloader.load(); });

    Window win(glm::ivec2(width,height));

    while (!win.shouldClose()) {
        if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
           win.stop();
        }

        glDrawPixels( width, height, GL_RGB, GL_FLOAT
                     , renderer.colorbuffer().data());

        win.update();
    }

    thr.join();

}

void
SDFLoader::define_camera(std::vector<std::string> const& tokens) 
{
	std::string name = tokens[2];
	float fov{std::stof(tokens[3])};
	Camera camera(name, fov);
	_scene.add(std::make_shared<Camera>(camera));
	std::cout << "Added camera " << name << " with fov: " << fov << std::endl;
}

void 
SDFLoader::define_sphere(std::vector<std::string> const& tokens)
{
	std::string name = tokens[3];
	glm::vec3 center{std::stof(tokens[4]), std::stof(tokens[5]), std::stof(tokens[6])};
	float radius = std::stof(tokens[7]);
	std::string material_name = tokens[8];

	std::vector<std::shared_ptr<Material>> materials = _scene.materials();
	for(auto material_ptr : materials) {
		std::cout << "Looking at material: " << material_ptr->name() << std::endl;
		if (material_ptr->name() == material_name) {
			Sphere sphere(center, radius, name, *material_ptr);
			_scene.add(std::make_shared<Sphere>(sphere));
			return;
		}
	}
	//material not found - throw exception
	throw std::runtime_error("illegal sphere definition (material not found)");
		
}

void
SDFLoader::define_box(std::vector<std::string> const& tokens)
{
	std::string name = tokens[3];
	glm::vec3 p1{std::stof(tokens[4]), std::stof(tokens[5]), std::stof(tokens[6])};
	glm::vec3 p2{std::stof(tokens[7]), std::stof(tokens[8]), std::stof(tokens[9])};
	std::string material_name = tokens[10];
	std::cout << material_name << std::endl;
	std::vector<std::shared_ptr<Material>> materials = _scene.materials();
	for(auto material_ptr : materials) {
		std::cout << "Looking at material: " << material_ptr->name() << std::endl;
		if(material_ptr->name() == material_name){
			Box box(p1, p2, name, *material_ptr);
			//std::cout << box.name() << *material_ptr;
			_scene.add(std::make_shared<Box>(box));
			return;
		} 
	}
	//material not found - throw exception;
	throw std::runtime_error("illegal box defintion (material not found)");

}

void
SDFLoader::define_shape(std::vector<std::string> const& tokens)
{
	if (tokens[2] == "sphere" && tokens.size() == 9) {
		define_sphere(tokens);
	} else if (tokens[2] == "box" && tokens.size() == 11) {
		define_box(tokens);
	} else {
		throw std::runtime_error("illegal shape definition");
	}
}

void 
SDFLoader::define_material(std::vector<std::string> const& tokens)
{
	std::string name = tokens[2];
	Color Ka{std::stof(tokens[3]), std::stof(tokens[4]), std::stof(tokens[5])};
	Color Kd{std::stof(tokens[6]), std::stof(tokens[7]), std::stof(tokens[8])};
	Color Ks{std::stof(tokens[9]), std::stof(tokens[10]), std::stof(tokens[11])};
	float m = std::stof(tokens[12]);

	Material material(name, Ka, Kd, Ks, m);
	_scene.add(std::make_shared<Material>(material));
}

void 
SDFLoader::define_light(std::vector<std::string> const& tokens)
{
	std::string name = tokens[2];
	glm::vec3 pos{std::stof(tokens[3]), std::stof(tokens[4]), std::stof(tokens[5])};
	Color La{std::stof(tokens[6]), std::stof(tokens[7]), std::stof(tokens[8])};
	Color Ld{std::stof(tokens[9]), std::stof(tokens[10]), std::stof(tokens[11])};

	Light light(name, pos, La, Ld);
	_scene.add(std::make_shared<Light>(light));
}

void
SDFLoader::define(std::vector<std::string> const& tokens)
{
	if (tokens[1] == "shape") {
		define_shape(tokens);
	} else if (tokens[1] == "material" && tokens.size() == 13) {
		define_material(tokens);
	} else if (tokens[1] == "light" && tokens.size() == 12) {
		define_light(tokens);
    } else if (tokens[1] == "camera" && tokens.size() == 4) {
		define_camera(tokens);
	} else {
		throw std::runtime_error("illegal definition (general)");
	}
}


void 
SDFLoader::load()
{
	std::ifstream infile(_filename);
	std::string line;
	while(std::getline(infile, line)) {
		std::istringstream iss(line);
		std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
										std::istream_iterator<std::string>{}};
		if (tokens.size() > 0 && tokens[0].substr(0, 1) == "#") {
			continue;
		}
		if (tokens[0] == "render" && tokens.size() == 5) {
			render(tokens);
		} else if(tokens[0] == "define") {
			define(tokens);
		} else {
			throw std::runtime_error("illegal sdf line");
		}
	}
}

SDFLoader::~SDFLoader()
{}

//void 
//SDFLoader::readSDF(std::string const& path)
//{
//	std::ifstream file;
//	std::string s;
//
//	file.open(path, std::ios::in);
//
//	
//
//	while(!file.eof())
//	{
//		getline(file, s);
//
//		std::istringstream iss{s};
//		std::string sub;
//		iss >> sub;
//	
//        if(sub == "define")
//        {
//            iss >> sub;
//            
//            if(sub == "material")
//            {
//                create_material(iss);
//            }
//            else if(sub == "shape")
//            {
//                iss >> sub;
//                
//                if(sub == "sphere")
//                {
//                    create_sphere(iss);
//                }
//                else if(sub == "box")
//                {
//                    //create_box(iss);
//                }
//                else if(sub == "composite")
//                {
//                    create_composite(iss);
//                }
//            }
//            else if(sub == "light")
//            {
//                iss >> sub;
//                if(sub == "diffuse")
//                {
//                    create_light(iss);
//                }
//                else if(sub == "ambient")
//                {
//                    //create_ambient(iss);
//                }
//            }
//            else if(sub == "camera")
//            {
//                //create_cam(iss);
//            }
//        }
//	}
//}
//
//
//void
//create_composite(std::istringstream&)
//{
//
//}
//
//void
//create_material(std::istringstream& iss)
//{
//	std::string name;
//	float r, g, b, m;
//	iss >> name >> r >> g >> b;
//	Color ka(r, g, b);
//	
//	iss >> r >> g >> b;
//	Color kd(r, g, b);
//
//	iss >> r >> g >> b >> m;
//	Color ks(r, g, b);
//
//	Material material = Material(name, ka, kd, ks, m);
//}
//
//void
//create_sphere(std::istringstream& iss)
//{
//	/*std::string name, materialName;
//	float x, y, z, r;
//
//	iss >> name >> x >> y >> z;
//	glm::vec3 mp(x, y, z);
//
//	iss >> r;
//
//	iss >> materialName;
//
//	std::shared_ptr<Material> ma = _scene.getMaterial(materialName);
//	std::shared_ptr<Shape> sphere = std::make_shared<Sphere>(Sphere(name, ma, mp, r));
//
//	_scene.addShape(name, sphere);
//
//	std::cout << name << " added " << std::endl;
//	*/
//}
//
//void
//create_light(std::istringstream& iss)
//{
//	
//}
//
//void 
//create_ambient(std::istringstream& iss)
//{
//	
//}
//
//
//void
//issprint(std::stringstream& iss)
//{
//	
//}
