#include <stdio.h>
#include <stdlib.h>

int main() {
  char c = 'a';
  int num = 0;
  int* arr = NULL;
  arr = calloc(1, sizeof(int));

  int index = 1;
  while (scanf("%d%c", &num, &c) && num != -1 && (c == ' ' || c == '\n')) {
    arr[index - 1] = num;
    int* tmp = realloc(arr, (index + 1) * sizeof(int));
    if (tmp) arr = tmp;
    ++index;
  }

  int * pointer = arr;

  for (int i = 0; i < index - 1; ++i) {
    printf("%d ", *pointer++);
  }

  free(arr);

  return 0;
}