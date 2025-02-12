#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


char *decimalToTwosComplement(int decimal, int numBits){

    if(decimal < 0){
        decimal = (1 << numBits) + decimal; 
    }

    char *binary = (char *)malloc(numBits + 1);

    for(int i = numBits - 1; i >= 0; i--){

        binary[i] = (decimal & 1) ? '1' : '0';
        decimal >>= 1;
    }

    binary[numBits] = '\0';
}


int main(int argc, char *argv[]){

    
    int decimal = -16; 

    int numBits = 12; 

    char *binary = decimalToTwosComplement(decimal, numBits);

    printf("Decimal: %d\n", decimal);
    printf("Binary: %s\n", binary);

    free(binary);

}