# Dogfault - A Doggo Themed Segfault Handler

Dogfault replaces the default segmentation fault handler with a dog themed handler that will print diagnostic information about the segfault as well as a stack trace before exiting the program.

Now instead of seeing `Segmentation fault (core dumped)` every time you get a segfault, you can be greeted by an 11/10 good boy!

## Use
Simply `#include` the dogfault header in the file that contains `main`. Setup is automatic.

In order for dogfault to access function names for its stack trace, source files must be compiled with the `-rdynamic` flag. Without this flag function addresses will be printed without their corresponding function name.

As an example:
```C
/* example.c */
#include <dogfault.h>

void foo(void);
void bar(void);

int main(void)
{
    foo();

    printf("This will never be printed\n");
    return EXIT_SUCCESS;
}

void foo(void)
{
    bar();
}

void bar(void)
{
    raise(SIGSEGV); // segfault
}
```
```
# In the dogfault directory
$ gcc example.c -I. -rdynamic
$ ./a.out 
                        __
 ,                    ," e`--o  *bark*
((                   (  | __,'   Segmentation fault at address: 0x3e8000077bd
 \\~----------------' \_;/       Fetching stacktrace!
 (                      /       *bark*
 /) ._______________.  )
(( (               (( (
 ``-'               ``-'
./a.out() [0x400b7c]
/lib/x86_64-linux-gnu/libc.so.6(+0x354b0) [0x7fdc4c5374b0]
/lib/x86_64-linux-gnu/libc.so.6(gsignal+0x38) [0x7fdc4c537428]
./a.out(bar+0xe) [0x400cef]
./a.out(foo+0x9) [0x400cde]
./a.out(main+0x9) [0x400cc4]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0) [0x7fdc4c522830]
./a.out(_start+0x29) [0x400a49]

```

## Supported compilers
+ GCC
+ clang

## License
The Unlicense
