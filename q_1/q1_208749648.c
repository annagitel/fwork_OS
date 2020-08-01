#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
// objdump -t a.out
//nm a.out

char globBuf[65536];            /* 1. Where is allocated? 0000000000404080 g     O .bss   0000000000010000              globBuf, 0000000000404080 B globBuf*/
int primes[] = { 2, 3, 5, 7 };  /* 2. Where is allocated? 0000000000404040 g     O .data  0000000000000010              primes, 0000000000404040 D primes*/

static int
square(int x)                   /* 3. Where is allocated? 0000000000401136 l     F .text  0000000000000015              square, 0000000000401136 t square*/
{
    int result;                 /* 4. Where is allocated? */

    result = x * x;
    return result;              /* 5. How the return value is passed? */
}

static void
doCalc(int val)                 /* 6. Where is allocated? 000000000040114b l     F .text  000000000000005d              doCalc,000000000040114b t doCalc */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. Where is allocated? */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* 8. Where is allocated? 00000000004011a8 g     F .text  0000000000000026              main, 00000000004011a8 T main*/
{
    static int key = 9973;      /* 9. Where is allocated? 0000000000404050 l     O .data  0000000000000004              key.1, 0000000000404050 d key.1*/
    static char mbuf[10240000]; /* 10. Where is allocated? 0000000000414080 l     O .bss   00000000009c4000              mbuf.0,0000000000414080 b mbuf.0 */
    char* p;                    /* 11. Where is allocated? */


    doCalc(key);

    exit(EXIT_SUCCESS);
}
//https://linux.die.net/man/1/nm
//https://www.howtoforge.com/linux-objdump-command/