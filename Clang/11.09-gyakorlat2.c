#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str)
{
  int len = strlen(str);

  for (int i = 0; i < len; ++i)
  {
    char temp = str[len - i - 1];
    str[len - i - 1] = str[i];
    str[i] = temp;
  }
}

char *reversed(char *str)
{
  int len = strlen(str);
  char *other = malloc(len + 1);

  for (int i = 0; i < len; ++i)
    other[len - i - 1] = str[i];

  other[len] = '\0';
  return other;
}

int main(void)
{
  char *p = reversed("hello");
  printf("%s\n", p);
  free(p);

  char str[100];
  scanf("%s", str);
  reverse(str);
  printf("%s\n", str);
  int *numbers = malloc(10 * sizeof(int));
  int size = 0;
  int capacity = 10;

  int num;

  while (scanf("%d", &num) == 1)
  {
    if (size == capacity)
    {
      capacity *= 2;
      numbers = realloc(numbers, capacity * sizeof(int));
      /* int *numbers2 = malloc(capacity * sizeof(int));

      for (int i = 0; i < size; ++i)
      {
        numbers2[i] = numbers[i];
      }
      free(numbers);
      numbers = numbers2;
    }
      numbers[size] = num;
      ++size;
      */
    }
    free(numbers);
  }

  return 0;
}
