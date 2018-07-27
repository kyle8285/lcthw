#include <stdio.h>
#include <stdint.h>

int main()
{
    /*
     * basic signed integer type
     * at least 16 bits, defaults to 32 bits
     * format specifier %i or %d
     */
    int _int = 1;
    printf("int: %10d\t sizeof(int): %lu\n", _int, sizeof(_int));

    /*
     * real floating-point type
     * usually referred to as single-precision
     * format specifier %f
     */
    float _float = 1.23432;
    printf("float: %10f\t sizeof(float): %lu\n", _float, sizeof(_float));

    /*
     * real floating-point type
     * usually referred to as double-precision
     * format specifier %lf
     */
    double _double = 32.13423;
    printf("double: %10lf\t sizeof(double): %lu\n", _double, sizeof(_double));

    /*
     * holds a single 1 byte character
     * it is an integer type
     * can be signed or unsigned
     * format specifier %c
     */
    char _char = 'a';
    printf("char: %10c\t sizeof(char): %lu\n", _char, sizeof(_char));

    return 0;
}
