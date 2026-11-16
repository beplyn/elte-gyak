#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char **words = malloc(5 * sizeof(char *));
  char word[100];

  int size = 0;
  int capacity = 5;

  while (scanf("%s", word) == 1)
  {
    if (size == capacity)
    {
      capacity *= 2;
      words = realloc(words, capacity * sizeof(char *));
    }

    int length = strlen(word);
    words[size] = malloc((length + 1) * sizeof(char));

    strcpy(words[size], word);
    ++size;
  }
  for (int i = 0; i < size; ++i)
  {
    printf("%s\n", words[size - i - 1]);
    free(words[size - i - 1]);
  }
}
