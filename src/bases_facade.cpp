#include <iostream>
#include <string>
#include <fstream>

#include "../include/base.hpp"
#include "../include/sorting.hpp"
#include "../include/bases_facade.hpp"

BasesFacade::BasesFacade(std::ifstream &basesFile, int basesNumber) {

  this->capacity = basesNumber;

  std::string t;

  for (int i = 0; i < basesNumber; i++) {

    getline(basesFile, t);

    int distance = this->get_distance_from_string(t);
    std::string name = this->get_name_from_string(t);

    basesArray[i] = new Base(distance, name);

  }


}

std::string BasesFacade::get_name_from_string(std::string line) {
  std::string name = line.substr(0, line.find(" "));
  return name;
}

int BasesFacade::get_distance_from_string(std::string line) {
  int distance = std::stoi(line.substr(line.find(" ")+1, line.length()));
  return distance;
}


void BasesFacade::print() {

  for (int i = 0; i < capacity; i++) {
      basesArray[i]->print();
  }

}

void BasesFacade::sort(char which_algorithm) {

  switch (which_algorithm) {

    case 'i':
      insertion_sort(basesArray, capacity);
      std::cout<<"insertion"<<std::endl;
      break;

    case 'c':
      comb_sort(basesArray, capacity);
      std::cout<<"comb"<<std::endl;
      break;

    case 'h':
      heapSort(basesArray, capacity);
      std::cout<<"heap"<<std::endl;
      break;

    case 'q':
      quick_sort(basesArray, capacity);
      std::cout<<"quick"<<std::endl;
      break;

    case 'm':
      modified_quick_sort(basesArray, capacity);
      std::cout<<"modified_quick"<<std::endl;
      break;

    default:
      throw "Não Existente";

  }

}
