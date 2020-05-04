#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

static char *p;

static void error(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

static void skip() {
  while (isspace(*p))
    p++;
}

static int eval() {
  skip();

  if (isdigit(*p)) {
    int val = *p++ - '0';
    while (isdigit(*p))
      val = val * 10 + (*p++ - '0');
    return val;
  }

  if (*p == '+') {
    p++;
    return eval() + eval();
  }

  if (*p == '-') {
    p++;
    return eval() - eval();
  }

  error("invalid character: %c", *p);
}

int main(int argc, char **argv) {
  p = argv[1];
  while (*p)
    printf("%d\n", eval());
  return 0;
}
