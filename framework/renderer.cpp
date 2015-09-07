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
#include <sdfloader.hpp>

Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render(Scene const& scene, Camera& camera)
{


	// Viewplane	
	//const std::size_t checkersize = 20;
	
	//float d = (width_ * 0.5) / (0.5 * cam_1.fov());
	float d = (-(width_ * 0.5) / std::tan(0.5 * camera.fov() * M_PI / 180));
	camera.setPosition(glm::vec3(0.0f, 0.0f, d));
	
	Ray primaryRay;
	primaryRay.origin_ = camera.position();

	// global ambient light accumulation
	Color global_ambient{0, 0, 0};
	for (auto light_ptr : scene.lights()) {
		global_ambient += light_ptr->la();
	}

	// Complete 
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
			HitRecord hr;
			HitRecord temp_hr;
			float t = 10000000000.0f;
			std::shared_ptr<HitRecord> temp_hr_ptr = std::make_shared<HitRecord>(temp_hr);
			bool intersection = false;

			// find closest intersection
			for (auto shape_ptr : scene.shapes()) {
				intersection = shape_ptr->intersect(primaryRay, temp_hr_ptr );
				if (intersection && temp_hr_ptr->t < t) {
					// update t
					t = temp_hr_ptr->t;
					// update hr for shading
					hr = *temp_hr_ptr;
					//std::cout << "Intersection at t = " << t << std::endl;
				}
			}

			
			if (intersection) {
				// phong shading with closest object
				// ambient
				p.color = hr.material_ptr->ka() * global_ambient;
			
				// check if intersection point is in shadow 
				// TODO 

				for (auto light_ptr : scene.lights()) {
					// diffuse
					auto light_vec = glm::normalize(light_ptr->position() - hr.position);
					auto dot = glm::dot(hr.normal, light_vec);
					if (dot > 0) 
						p.color += hr.material_ptr->kd() * light_ptr->ld() * dot;
					// specular
					auto eye_vec = glm::normalize((2.0f * dot * hr.normal) - light_vec);
					auto dot2 = glm::dot(light_vec, eye_vec);
					if (dot2 > 0) {
						double value = std::abs(std::pow(dot2, hr.material_ptr->m()));
						p.color += hr.material_ptr->ks() * light_ptr->ld() * std::max(value, 0.0);
					}
				}
			}

			write(p);
		}
	}

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
