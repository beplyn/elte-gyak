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
int main(int argc, char *argv[])
{
  for (int i = 0; i < argc; ++i)
    printf("%s\n", argv[i]);

  if (argc != 2)
  {
    printf("Usage: %s <num>\n", argv[0]);
    return 1;
  }

  int num = atoi(argv[1]);

  char word[100];
  if (strcmp(word, "end"))

    // strcmp("abc", "xyz") < 0
    // strcmp("xyz", "abc") > 0
    // strcmp("abc", "abc") == 0

    int t[] = {1, 2, 3, 4, 5};
  int size = sizeof(t) / sizeof(t[0]);
  int *other = partition(t, size);

  for (int i = 0; i < size; ++i)
    printf("%d\n", other[i]);

  free(other);

  return 0;
}
