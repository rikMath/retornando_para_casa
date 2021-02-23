#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "../include/base.hpp"
#include "../include/bases_facade.hpp"
#include "../include/sorting.hpp"

using namespace std;

void measure_time (char type, BasesFacade& bases) {
  auto t1 = std::chrono::high_resolution_clock::now();

  bases.sort(type);

  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

  std::cout << "Tempo em microsegundos " << duration << std::endl;
}

int main(int argc, char const *argv[]) {
  ifstream basesFile (argv[1]);
  int basesNumber = stoi(string(argv[2]));
  BasesFacade bases(basesFile, basesNumber);

  measure_time('q', bases);

  // bases.print();
  return 0;
}
