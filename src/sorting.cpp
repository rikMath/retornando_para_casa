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

// Criação heap
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
    // Tornando o array um heap
    for (int i = length; i >= 0; i--){
      heapify(bases_array, length, i);
    }



    for (int i = length - 1; i >= 0; i--) {
      // Extrai o maior elemento e recria o heap para os elementos restantes

        aux = bases_array[i];
        bases_array[i] = bases_array[0];
        bases_array[0] = aux;

        heapify(bases_array, i, 0);
    }

}

void partition(int Esq, int Dir,int *i, int *j, Base** bases_array) {
  Base* x;
  Base* w;

  *i = Esq; *j = Dir;
  x = bases_array[(*i + *j)/2]; /* obtem o pivo x */
  do {
    while (x->get_distance() < bases_array[*i]->get_distance()) (*i)++;
    while (x->get_distance() > bases_array[*j]->get_distance()) (*j)--;
    if (*i <= *j) {
      w = bases_array[*i];
      bases_array[*i] = bases_array[*j];
      bases_array[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}


void ordenate_quick_sort(Base** bases_array, int left, int right) {

  int i, j;
  partition(left, right, &i, &j, bases_array);
  if (left < j) ordenate_quick_sort(bases_array, left, j);
  if (i < right) ordenate_quick_sort(bases_array, i, right);

}

void quick_sort(Base** bases_array, int length) {
  ordenate_quick_sort(bases_array, 0, length-1);
}

void modified_ordenate_quick_sort(Base** bases_array, int left, int right) {

  if (right-left > 10) {
    int i, j;
    partition(left, right, &i, &j, bases_array);
    if (left < j) ordenate_quick_sort(bases_array, left, j);
    if (i < right) ordenate_quick_sort(bases_array, i, right);
  } else {

    Base* aux;
    int j;
    for (int i = left; i <= right; i++) {
      aux = bases_array[i];
      j = i-1;
      while ((j >= 0) && (aux->get_distance() > bases_array[j]->get_distance())) {
        bases_array[j+1] = bases_array[j];
        j--;
      }
      bases_array[j+1] = aux;
    }

  }


}

void modified_quick_sort(Base** bases_array, int length) {
  modified_ordenate_quick_sort(bases_array, 0, length-1);
}
