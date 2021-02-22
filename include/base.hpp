#include <iostream>
#include <string>

#ifndef BASE_H
#define BASE_H

class Base {
private:
  int distance;
  std::string name;

public:
  Base (int, std::string);
  // virtual ~Base ();

  inline int get_distance() const {return distance;}
  void print();
};

#endif
