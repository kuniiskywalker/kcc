kcc
====

Tiny self-hosted C compiler for practice.

## Description

Practice based on the following code

https://gist.github.com/rui314/a13acb5bbea0fb4bd66eaa4db4ac93d2

## Usage

### Execute

```
gcc -std=c11 -o lang lang.c && ./lang 'F[P(a) F(b  + a b)] F(1 1)'|head -30
```

### Test

```
./runTest
```

## How to debug

When debugging with gdb, it is necessary to compile with the following option "-g -O0" when compiling.

"-g" is add debug info.

"-O0" is do not optimize.

```
$ gcc -g -O0 lang.c
```

Execute the a.out file created by compiling earlier on gdb

```
$ gdb --args ./a.exe "+ 1 1"
```

Add break point for function

```
breakpoint {function name or line number}
```

Execute

```
run
```



