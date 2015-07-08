#include <vector>
#include <shape.hpp>

class Scene {
	public:
		Scene();
		void add(Shape* shape);
		std::vector<Shape*> getShapes() const;
		
	private:
		std::vector<Shape*> _shapes;	
	// std::vector<Light> _lights;
	// std::vector<Camera> _cameras;
};
