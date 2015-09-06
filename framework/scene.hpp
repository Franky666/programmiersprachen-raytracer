#ifndef SCENE_HPP
#define SCENE_HPP
#include <vector>
#include <memory>
#include <shape.hpp>
#include <material.hpp>
#include <light.hpp>
#include <camera.hpp>

class Scene {
	
	public:
		Scene();
		~Scene();

		void render() const;
		void add(std::shared_ptr<Material> material);
		void add(std::shared_ptr<Shape> shape);
		void add(std::shared_ptr<Light> light);
		void add(std::shared_ptr<Camera> camera);

		std::vector<std::shared_ptr<Shape>> const& shapes() const;
		std::vector<std::shared_ptr<Material>> const& materials() const;
		std::vector<std::shared_ptr<Light>> const& lights() const;
		std::vector<std::shared_ptr<Camera>> const& cameras() const;

	private:
		std::vector<std::shared_ptr<Shape>> _shapes;	
		std::vector<std::shared_ptr<Material>> _materials;
	    std::vector<std::shared_ptr<Light>> _lights;
	    std::vector<std::shared_ptr<Camera>> _cameras;
};
#endif
