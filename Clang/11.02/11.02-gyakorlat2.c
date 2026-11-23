#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *f()
{
  int *p = malloc(sizeof(int));
  return p;
}

int main(void)
{
  char *words[5];

  char word[100];
  for (int i = 0; i < 5; ++i)
  {
    scanf("%s", word);
    int s = strlen(word);
    words[i] = malloc(s + 1);
    strcpy(words[i], word);
  }

  for (int i = 0; i < 5; ++i)
  {
    printf("%s\n", words[5 - i - 1]);
    free(words[5 - i - 1]);
  }
  return 0;
}
