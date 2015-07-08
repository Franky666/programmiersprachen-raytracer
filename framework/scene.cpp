 #include <scene.hpp>

 
 Scene::Scene()
 : _shapes()
 {}

 void 
 Scene::add(Shape* shape)
 {
	_shapes.push_back(shape);
 }	
		          
std::vector<Shape*> 
Scene::getShapes() const
{
	return _shapes;
}
