#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char **words = malloc(5 * sizeof(char *));
  int size = 0;
  int capacity = 5;

  char word[100];
  while (scanf("%s", word) == 1)
  {
    if (size == capacity)
    {
      capacity *= 2;
      words = realloc(words, capacity * sizeof(char *));
    }
    int len = strlen(word);
    words[size] = malloc(len + 1);
    strcpy(words[size], word);
    ++size;
  }

  for (int i = 0; i < size; ++i)
  {
    printf("%s\n", words[size - i - 1]);
    free(words[size - i - 1]);
  }
  return 0;
}
