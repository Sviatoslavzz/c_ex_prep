#include <stdio.h>
#include <stdlib.h>

void c_shift(char* path, int shift);

int main() {
  int mem_error = 0;
  char ch = 'a';
  char* path = NULL;
  path = calloc(2, sizeof(char));
  if (!path) mem_error = 1;

  int i = 0;
  while (!mem_error && scanf("%c", &ch) && ch != '\n' && ch != '\0') {
    path[i] = ch;
    path[i + 1] = '\0';
    char* ptr = NULL;
    i++;
    ptr = realloc(path, (i + 2) * sizeof(char));
    if (!ptr)
      mem_error = 1;
    else
      path = ptr;
  }

  if (mem_error)
    printf("memory allocation error");
  else {
    int shift = 0;
    scanf("%d%c", &shift, &ch);
    if (ch != '\n')
      printf("n/a");
    else
      c_shift(path, shift);
  }

  if (path) free(path);

  return 0;
}

void c_shift(char* path, int shift) {
  FILE* file = NULL;
  file = fopen(path, "r");

  if (file) {
    int ch = 1;
    while ((ch = fgetc(file)) != EOF) {
      if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
        if (ch >= 65 && ch <= 90) {
          ch -= 65;
        } else if (ch >= 97 && ch <= 122) {
          ch -= 71;
        }
        ch = ch + shift;
        if (ch > 0)
          ch %= 52;
        else {
          while (ch < 0) {
            ch = 52 + ch;
          }
        }
        if (ch >= 0 && ch <= 25) {
          ch += 65;
        } else if (ch >= 26 && ch <= 51) {
          ch += 71;
        }
      }
      printf("%c", ch);
    }
    fclose(file);
  } else {
    printf("n/a");
  }
}