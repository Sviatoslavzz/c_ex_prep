#include <stdio.h>
#include <stdlib.h>

int main() {
  char c = 'a';
  char* line = NULL;

  line = malloc(1 * sizeof(char));
  if (!line) {
    printf("Memory allocation error");
    return 1;
  }

  int counter = 1;
  while (c != '\n') {
    char* tmp = realloc(line, (counter + 1) * sizeof(char));
    if (tmp) line = tmp;
    scanf("%c", &c);
    line[counter - 1] = c;
    line[counter] = '\0';
    ++counter;
  }

  printf("%s", line);

  free(line);

  return 0;
}