#include <stdio.h>

static char *p;

static int eval() {
  p++;
  return 0;
}

int main(int argc, char **argv) {
  p = argv[1];
  while (*p)
    printf("%d\n", eval());
  return 0;
}
