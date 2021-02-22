#include <iostream>
#include <string>
#include <fstream>

#include "../include/sorting.hpp"
#include "../include/base.hpp"

void insertion_sort(Base** bases_array, int length) {
  Base* aux;
  int j;
  for (int i = 0; i < length; i++) {
    aux = bases_array[i];
    j = i-1;
    while ((j >= 0) && (aux->get_distance() > bases_array[j]->get_distance())) {
      bases_array[j+1] = bases_array[j];
      j--;
    }
    bases_array[j+1] = aux;
  }
}

const double shrink_factor = 1.247330950103979;

int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap /= shrink_factor;

    if (gap < 1)
        return 1;
    return gap;
}

void comb_sort(Base** bases_array, int length) {

  int gap = length;
  bool swaps = true;
  Base* aux;

  while ( (gap > 1) || (swaps == true) ){

    gap = gap/shrink_factor < 1 ? 1 : gap/shrink_factor;

    swaps = false;

    for (int i=0; i<length-gap; i++) {

        if (bases_array[i]->get_distance() < bases_array[i+gap]->get_distance()) {
            aux = bases_array[i];
            bases_array[i] = bases_array[i+gap];
            bases_array[i+gap] = aux;
            // swap(a[i], a[i+gap]);
            swaps = true;
        }

    }
  }


}
