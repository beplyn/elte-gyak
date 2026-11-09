#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *numbers = malloc(10 * sizeof(int));
  int size = 0;
  int capacity = 10;

  int num;

  while (scanf("%d", &num) == 1)
  {
    if (size == capacity)
    {
      capacity *= 2;
      int *numbers2 = malloc(capacity * sizeof(int));

      for (int i = 0; i < size; ++i)
      {
        numbers2[i] = numbers[i];
      }
      free(numbers);
      numbers = numbers2;
    }

    numbers[size] = num;
    ++size;
  }

  return 0;
}
