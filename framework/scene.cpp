 #include <scene.hpp>

 
Scene::Scene()
: _shapes()
{}

Scene::~Scene()
{}

void
Scene::render() const
{

}

void
Scene::add(std::shared_ptr<Material> material)
{
	_materials.push_back(material);
}

void 
Scene::add(std::shared_ptr<Shape> shape)
{
	_shapes.push_back(shape);
}	
		         
void
Scene::add(std::shared_ptr<Light> light)
{
	_lights.push_back(light);
}

void
Scene::add(std::shared_ptr<Camera> camera)
{
	_cameras.push_back(camera);
}


std::vector<std::shared_ptr<Shape>> const&
Scene::shapes() const
{
	return _shapes;
}

std::vector<std::shared_ptr<Material>> const&
Scene::materials() const
{
	return _materials;
}

std::vector<std::shared_ptr<Light>> const&
Scene::lights() const
{
	return _lights;
}

std::vector<std::shared_ptr<Camera>> const&
Scene::cameras() const
{
	return _cameras;
}

