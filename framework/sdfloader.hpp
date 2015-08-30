#include <string>
#include <scene.hpp>

class SDFLoader {
	public:
		SDFLoader(std::string const& filename);
		Scene load();
	private:
		Scene _scene;
		std::string _filename;
};
