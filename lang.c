#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

static char *p;
static char func[26][100];

static void error(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

static void read_until(char c, char*buf) {
  int i = 0;
  for(; *p != c; p++, buf++)
    *buf = *p;
  p++;
  *buf = '\0';
}

static void skip() {
  while (isspace(*p))
    p++;
}

static void expect(char c) {
  if (*p != c)
    error("%c expected: %s", p);
  p++;
}

static int eval(int arg);

static int eval_string(char *code, int arg) {
  char *orig = p;
  p = code;
  int val = eval(arg);
  p = orig;
  return val;
}

static int eval(int arg) {
  skip();

  // Function parameter
  if (*p == '.') {
    p++;
    return arg;
  }

  // Function definition
  if  ('A' <= *p && *p <= 'Z' && p[1] == '[') {
    char name = *p;
    p += 2;
    read_until(']', func[name - 'A']);
    return eval(arg);
  }

  // Function application
  if  ('A' <= *p && *p <= 'Z' && p[1] == '(') {
    char name = *p;
    p += 2;
    int newarg = eval(arg);
    expect(')');
    return eval_string(func[name - 'A'], newarg);
  }

  // Literal numbers
  if (isdigit(*p)) {
    int val = *p++ - '0';
    while (isdigit(*p))
      val = val * 10 + (*p++ - '0');
    return val;
  }

  // Arithmetic oprators
  if (strchr("+-*/", *p)) {
    int op = *p++;
    int x = eval(arg);
    int y = eval(arg);
    switch (op) {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    }
  }

  error("invalid character: %c", *p);
}

int main(int argc, char **argv) {
  p = argv[1];
  while (*p) {
    printf("%d\n", eval(0));
  }
  return 0;
}
