#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int twosComplementToDecimal(char *binary)
{

    int decimal = 0;
    int length = strlen(binary);

    // Check if the most significant bit is 1 (indicating a negative number)
    bool isNegative = (binary[0] == '1');

    for (int i = 0; i < length; i++)
    {
        decimal = (decimal << 1) + (binary[i] - '0');
    }

    // If negative, adjust the decimal value
    if (isNegative)
    {
        decimal -= (1 << length);
    }

    return decimal;
}

char *decimalToTwosComplement(int decimal, int numBits)
{

    if (decimal < 0)
    {
        decimal = (1 << numBits) + decimal;
    }

    char *binary = (char *)malloc(numBits + 1);

    for (int i = numBits - 1; i >= 0; i--)
    {

        binary[i] = (decimal & 1) ? '1' : '0';
        decimal >>= 1;
    }

    binary[numBits] = '\0';

    return binary;
}

int main(int argc, char *argv[])
{

    bool decimalBool = false;
    bool binaryBool = false;
    bool numBitsBool = false;

    int decimal = 0;
    int numBits = 0;
    char *binary = NULL;

    for (int i = 1; i < argc; i++)
    {

        if (strcmp(argv[i], "-decimal") == 0)
        {
            decimal = atoi(argv[i + 1]);
            decimalBool = true;
        }

        if (strcmp(argv[i], "-bits") == 0)
        {
            numBits = atoi(argv[i + 1]);
            numBitsBool = true;
        }

        if (strcmp(argv[i], "-binary") == 0)
        {
            binary = argv[i + 1];
            binaryBool = true;
        }
    }

    if (decimalBool && numBitsBool)
    {

        char *binary = decimalToTwosComplement(decimal, numBits);
        printf("Decimal: %d\n", decimal);
        printf("Binary: %s\n", binary);

        free(binary);
    }

    if (binaryBool)
    {

        int decimal = twosComplementToDecimal(binary);
        printf("Binary: %s\n", binary);
        printf("Decimal: %d\n", decimal);
    }
}