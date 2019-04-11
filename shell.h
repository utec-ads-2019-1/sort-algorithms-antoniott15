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
        k = j;
        while (k >= i)
        {
          if (temp < array[k - i])
            array[k] = array[k - i];
          else
            break;
          k -= i;
        }
        array[k] = temp;
      }
      compare(elements, array[k], array[k - i]);
    }
  }

  inline string name() { return "ShellSort"; }
};

#endif