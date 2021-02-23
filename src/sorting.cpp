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
            swaps = true;
        }

    }
  }


}

// Criação heap mínimo
void heapify(Base** bases_array, int n, int i) {
    int min = i;
    int l = 2 * i + 1; // Filho da esquerda
    int r = 2 * i + 2; // Dilho da direita
    Base* aux;

    // Encontraremos qual dos dois filhos é o menor

    if (l < n && bases_array[l]->get_distance() < bases_array[min]->get_distance()){
      min = l;
    }


    if (r < n && bases_array[r]->get_distance() < bases_array[min]->get_distance()){
      min = r;
    }

    // Caso min seja diferente de i, ainda temos que refazer o heap
    // Ocorre se os dois filhos forem menores que o pai
    if (min != i) {
      aux = bases_array[min];
      bases_array[min] = bases_array[i];
      bases_array[i] = aux;

      heapify(bases_array, n, min);
    }

}

void heapSort(Base** bases_array, int length)
{
    Base* aux;
    // Tornando o array um heap mínimo
    for (int i = length; i >= 0; i--){
      heapify(bases_array, length, i);
    }



    for (int i = length - 1; i >= 0; i--) {
      // Extrai o menor elemento e recria o heap para os elementos restantes

        aux = bases_array[i];
        bases_array[i] = bases_array[0];
        bases_array[0] = aux;

        heapify(bases_array, i, 0);
    }

}
