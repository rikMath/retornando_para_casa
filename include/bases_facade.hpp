#include <iostream>
#include <string>
#include <fstream>

#include "./base.hpp"

#ifndef BASES_FACADE_H
#define BASES_FACADE_H

class BasesFacade {
private:

  int capacity;
  Base* basesArray[200000];

  std::string get_name_from_string(std::string);
  int get_distance_from_string(std::string);

public:
  BasesFacade (std::ifstream &basesFile, int basesNumber);
  // virtual ~BasesFacade ();
  void print();
  void print_initial();
  void sort(char);
};

#endif
