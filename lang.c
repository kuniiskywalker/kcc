#include <stdio.h>
#include <ctype.h>

static char *p;

static int eval() {
  if (isdigit(*p)) {
    int val = *p++ - '0';
    while (isdigit(*p))
      val = val * 10 + (*p++ - '0');
    return val;
  }
  return 0;
}

int main(int argc, char **argv) {
  p = argv[1];
  while (*p)
    printf("%d\n", eval());
  return 0;
}
