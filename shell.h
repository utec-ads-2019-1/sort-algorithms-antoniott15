#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort
{
public:
  ShellSort(void *elements, size_t size) : Sort(elements, size) {}

  void execute(void (*compare)(void *, int, int))
  {
    int *array = (int *)elements;
    int half = size / 2, temp, k, i, j;
    for (i = half; i > 0; i /= 2)
    {
      for (j = i; j < size; j++)
      {
        temp = array[j];
        for (k = j; k >= i; k -= i)
        {
          array[k - i] > temp ? array[k] = array[k - i] : false;
        }
        array[k] = temp;
      }
      compare(elements, array[k], array[k - i]);
    }
  }

  inline string name() { return "ShellSort"; }
};

#endif