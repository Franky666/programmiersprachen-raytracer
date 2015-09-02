// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include <renderer.hpp>

//tmp????
#include <camera.hpp>
#include <sphere.hpp>
#include <box.hpp>
#include <cmath>

Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render()
{



	// calc distance cam
	

	// Viewplane	
	//const std::size_t checkersize = 20;
	float height_ = 480;
	float width_ = 640;
	
	Camera cam_1("cam_1", 75.0f);
	// calculate camera distance

	//float d = (width_ * 0.5) / (0.5 * cam_1.fov());
	float d = (-(width_ * 0.5) / std::tan(0.5 * cam_1.fov() * M_PI / 180));
	cam_1.setPosition(glm::vec3(0.0f, 0.0f, d));
	
	Sphere s1{{-100.0, 30.0, -4.0}, 60};
	Box b1;
	Ray primaryRay;
	primaryRay.origin_ = cam_1.position();
	
	// Complete 
	//for (unsigned y = (height_ / 2); y > (-height_ / 2); --y) {
	//	for (unsigned x = (-width_ / 2); x < (width_ / 2); ++x) {
	for (unsigned y = 0; y < height_; ++y) {
		for (unsigned x = 0; x < width_; ++x) {
			Pixel p(x,y);
			// calculate point on viewplane
			float vpx = x - width_ * 0.5f;
			float vpy = y - height_ * 0.5f;
		
			glm::vec3 ray_direction = glm::vec3(vpx, vpy, 0.0f) - primaryRay.origin_;
			primaryRay.direction_ = glm::normalize(ray_direction);
			//std::cout << "DEBUG: " << primaryRay << std::endl;

			// for every object in scene ask if our primaryRay intersects an object
			float t = 100000000.0f; // far plane maximum
			bool intersection = s1.intersect(primaryRay, t);
			if (intersection) {
				std::cout << "Intersection at t = " << t << std::endl;
				p.color = Color(1.0, 0.0, 0.0);
			}

			write(p);
		}
	}

	

/*
	  for (unsigned y = 0; y < height_; ++y) {
    	for (unsigned x = 0; x < width_; ++x) {
     	 Pixel p(x,y);
     	 if ( ((x/checkersize)%2) != ((y/checkersize)%2)) {
        p.color = Color(0.0, 1.0, float(x)/height_);
      } else {
        p.color = Color(1.0, 0.0, float(y)/width_);
      }

      write(p);
    }
  }
  */
  
  ppm_.save(filename_);

}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}
