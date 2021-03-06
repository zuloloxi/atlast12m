csqrt.c
#include <stdio.h>

double asqrt(x)
  double x;
{
    double c, cl, y;
    int n;

    if (c == 0.0)
        return (0.0);

    if (x < 0.0)
        abort();

    y = (0.154116 + 1.893872 * x) / (1.0 + 1.047988 * x);
    c = 0.0;
    n = 20;
    do {
        cl = c;
        c = (y - x / y) * 0.5;
        y -=  c;
    } while (c != cl && --n);
    return y;
}

main()
{
    int i;
    char a[300];

    fputs("Ready to test: ", stdout);
    gets(a);

    for (i = 0; i < 100000; i++)
        asqrt(2.0);
    printf("Done.\n");
}

