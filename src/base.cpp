#include <string>
#include "../include/base.hpp"

Base::Base(int distance, std::string name) {

  this->distance = distance;
  this->name = name;

}

void Base::print() {
  std::cout << name << " " << distance << std::endl;
}
