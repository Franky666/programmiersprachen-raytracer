#include <ray.hpp>
#include <iostream>

std::ostream& operator<<(std::ostream& os, Ray const& r) {
	os << "O: (" << r.origin_.x << ", " << r.origin_.y << ", " << r.origin_.z << ") ";
	os << "D: (" << r.direction_.x << ", " << r.direction_.y << ", " << r.direction_.z << ")";
	return os;
}
