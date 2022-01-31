#include <stdio.h>

//char型のビット並びを表示
void PrintBitC(unsigned char c)
{
    unsigned char bit = 1 << 7;
    while (bit != 0)
    {
        if (c & bit)
            putchar('1');
        else
            putchar('0');
        bit >>= 1;
    }
    putchar('\n');
}

int main()
{
    unsigned char c5 = 5;
    unsigned char c12 = 12;
    unsigned char ret;

    //retには4が代入される
    ret = c5 & c12;

    //00000101
    printf("%3d: ", c5);
    PrintBitC(c5);

    //00001100
    printf("%3d: ", c12);
    PrintBitC(c12);

    //00000100
    printf("%3d: ", ret);
    PrintBitC(ret);

    getchar();
}