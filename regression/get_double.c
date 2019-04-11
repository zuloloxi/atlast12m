#include <stdio.h>
#include <math.h>

double ConvertNumberToFloat(unsigned long number, int isDoublePrecision)
{
    int mantissaShift = isDoublePrecision ? 52 : 23;
    unsigned long exponentMask = isDoublePrecision ? 0x7FF0000000000000 : 0x7f800000;
    int bias = isDoublePrecision ? 1023 : 127;
    int signShift = isDoublePrecision ? 63 : 31;

    int sign = !((number >> signShift) & 0x01);
    int exponent = ((number & exponentMask) >> mantissaShift) - bias;

    int power = -1;
    double total = 0.0;
    for ( int i = 0; i < mantissaShift; i++ )
    {
        int calc = (number >> (mantissaShift-i-1)) & 0x01;
        total += calc * pow(2.0, power);
        power--;
    }
    total += 1.0;

    double value = sign * pow(2.0, exponent) * total;

    return value;
}

float GetSinglePrecision(unsigned int number)
{
    return (float)ConvertNumberToFloat(number, 0);
}

double GetDoublePrecision(unsigned long number)
{
    return ConvertNumberToFloat(number, 1);
}

int main()
{
    unsigned int singleValue = 0x40490FDB; // 3.141592...
    float singlePrecision = GetSinglePrecision(singleValue);
    printf("IEEE754 Single (from 32bit 0x%08X): %.7f\n",singleValue,singlePrecision);

    unsigned long doubleValue = 0x400921FB54442D18; // 3.141592653589793... 
    double doublePrecision = GetDoublePrecision(doubleValue);
    printf("IEEE754 Double (from 64bit 0x%016lX): %.16f\n",doubleValue,doublePrecision);
}