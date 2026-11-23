#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *tomb = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; ++i)
    *(tomb + i) = 7;

  for (int i = 0; i < 10; ++i)
  {
    printf("%d \t %d\n", *(tomb + i), i);
    // free(&tomb[i]);
  }
  return 0;
}
