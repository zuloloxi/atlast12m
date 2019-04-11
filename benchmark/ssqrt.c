/* ssqrt.c */
#include <stdio.h>
#include <math.h>

main()
{
    int i;
    char a[300];

    fputs("Ready to test: ", stdout);
    gets(a);

    for (i = 0; i < 100000; i++)
        sqrt(2.0);
    printf("Done.\n");
}

