#include <vector>
#include <shape.hpp>

class Scene {
	public:
		Scene();
	
		void render() const;
		void add(Material* material);
		void add(Shape* shape);
		std::vector<Shape*> getShapes() const;
		std::vector<Material*> getMaterials() const;

	private:
		std::vector<Shape*> _shapes;	
		std::vector<Material*> _materials;
	// std::vector<Light> _lights;
	// std::vector<Camera> _cameras;
};
