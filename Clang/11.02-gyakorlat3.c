#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int *t = malloc(sizeof(int) * 10);
  int size = 0;
  int capacity = 10;

  int num;
  while (scanf("%d", &num) == 1)
  {
    if (size < capacity)
    {
      t[size = num];
      ++size;
    }
    else
    {
      capacity *= 2;
      int *t2 = malloc(capacity * sizeof(int));

      for (int i = 0; i < size; ++i)
      {
        t2[i] = t[i];
      }
      free(t);
      t = t2;
      t[size] = num;
      ++size;
    }
  }
  return 0;
}
