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
