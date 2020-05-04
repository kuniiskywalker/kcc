
```
gcc -std=c11 -o lang lang.c && ./lang 'a'
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
breakpoint {function name}
```

Execute

```
run
```


