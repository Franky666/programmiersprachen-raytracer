//#include <thread>
//#include <renderer.hpp>
//#include <fensterchen.hpp>
#include <iostream>
#include <sdfloader.hpp>
int main(int argc, char* argv[])
{
	std::string filename = argv[1];
	std::cout << "file: " << filename << std::endl;

	SDFLoader fileloader{filename};
	fileloader.load();
  //unsigned const width = 640;
  //unsigned const height = 480;
  //std::string const filename = "./checkerboard.ppm";

  // SDFLoader sdfloader("filename_from_argv");
  

  //Renderer app(width, height, filename);
  //std::thread thr([&app]() { app.render(); });
  
  // std::thread thr([&app]() { sdfloader.load(); });

  //Window win(glm::ivec2(width,height));

  //while (!win.shouldClose()) {
  //  if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
  //    win.stop();
  //  }

  //  glDrawPixels( width, height, GL_RGB, GL_FLOAT
  //              , app.colorbuffer().data());

  //  win.update();
  //}

  //thr.join();

  return 0;
}
