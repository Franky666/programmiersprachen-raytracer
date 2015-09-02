// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

//tmp????
#include "camera.hpp"
#include "sphere.hpp"
#include "box.hpp"


Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render()
{

	Camera cam_1;
	Sphere s1{{0.0, 0.0, 0.0},{2}};
	Box b1;
	Ray r1;


	// calc distance cam
	

	// Viewplane	
	//const std::size_t checkersize = 20;
	float height_ = 480;
	float width_ = 640;
	int x,y;
	
	// Complete 
	// for (unsigned y = (height_ / 2); y > (-height_ / 2); --y);
	//	for (unsigned x = (-width_ / 2); x < (width_ / 2); ++x);
	Pixel p(x,y);

	// first quadrant 
	for (unsigned y = (height_ / 2); y > 0; --y){
		for (x = (-width_ / 2); x < 0; ++x){
			if (s1.intersect(r1,(0.0, 0.0, 10))){
				p.color = Color(1.0, 0.0, 0.0);
			}
			else {
				p.color = Color(0.0, 0.0, 0.0);
			}
		}
	}
	write(p);

	
	//second quadrant
	for (unsigned y = (height_ / 2); y > 0; --y){
		for (x = 0; x < (width_ / 2); ++x){
			if (s1.intersect){
				p.color = Color(1.0, 0.0, 0.0);
			}
			else {
				p.color = Color(0.0, 0.0, 0.0);
			}
		}
	}
	write(p);

	//third quadrant
	for (unsigned y = 0; y > (-height_ / 2); --y){
		for (int x = (-width_ / 2); x < 0; ++x){
			if (s1.intersect){
				p.color = Color(1.0, 0.0, 0.0);
			}
			else {
				p.color = Color(0.0, 0.0, 0.0);
			}
		}
	}
	write(p);


	//fourth
	for (unsigned y = 0; y > (-height_ / 2); --y){
		for (int x = 0; x < (width_ / 2); ++x){
			if (s1.intersect){
				p.color = Color(1.0, 0.0, 0.0);
			}
			else {
				p.color = Color(0.0, 0.0, 0.0);
			}
		}
	}
	write(p);

	

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
