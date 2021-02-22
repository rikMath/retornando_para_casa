#include <iostream>
#include <string>
#include <fstream>

#include "../include/base.hpp"
#include "../include/bases_facade.hpp"
#include "../include/sorting.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream basesFile (argv[1]);
  int basesNumber = stoi(string(argv[2]));
  BasesFacade bases(basesFile, basesNumber);
  bases.sort('i');
  bases.print();
  return 0;
}
