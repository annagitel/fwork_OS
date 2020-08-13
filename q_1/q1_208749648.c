#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
// objdump -t a.out
//nm a.out

char globBuf[65536];            /* 1. global variable, stored on the heap (uninitialized data section - BSS ) */
int primes[] = { 2, 3, 5, 7 };  /* 2. global variable, stored on the heap (initialized data section) */

static int
square(int x)                   /* 3. function declaration - stored in the text section */
{
    int result;                 /* 4. stored in the function stack  */

    result = x * x;
    return result;              /* 5. passed using the eax register */
}

static void
doCalc(int val)                 /* 6. function declaration - stored in the text section */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7.  stored in the function stack */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* 8. function declaration - stored in the text section */
{
    static int key = 9973;      /* 9. local variable, (initialized data section)*/
    static char mbuf[10240000]; /* 10. local variable,(uninitialized data section - BSS )*/

    char* p = mbuf;                    /* 11. not allocated because its not initialized & not used */
	int s = square(5);
    doCalc(key);

    exit(EXIT_SUCCESS);
}

