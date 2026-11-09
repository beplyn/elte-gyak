#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *partition(int t[], int size)
{
  int *other = malloc(size * sizeof(int));

  if (other == NULL)
    return NULL;

  int evenIdx = 0;
  int oddIdx = size - 1;

  for (int i = 0; i < size; ++i)
  {
    if (t[i] % 2 == 0)
    {
      other[evenIdx] = t[i];
      evenIdx++;
    }
    else
    {
      other[oddIdx] = t[i];
      oddIdx--;
    }
  }

  return other;
}
int main(void)
{
  int t[] = {1, 2, 3, 4, 5};
  int size = sizeof(t) / sizeof(t[0]);
  int *other = partition(t, size);

  for (int i = 0; i < size; ++i)
    printf("%d\n", other[i]);

  free(other);

  return 0;
}
