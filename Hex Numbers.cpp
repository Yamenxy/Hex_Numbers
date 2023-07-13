#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hexToDec(char* hex) {
    int len = strlen(hex);
    int dec = 0;

    for (int i = 0; i < len; i++) {
        int digitValue;

        if (hex[i] >= '0' && hex[i] <= '9') {
            digitValue = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digitValue = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digitValue = hex[i] - 'a' + 10;
        } else {
            printf("INVALID INPUT!\a\n");
            return -1;
        }

        dec += digitValue * pow(16, len - i - 1);
    }

    return dec;
}

char* decToHex(int dec) {
    char* hex = (char*)malloc(100 * sizeof(char));
    int i = 0;

    while (dec != 0) {
        int remainder = dec % 16;

        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A';
        }

        dec /= 16;
        i++;
    }

    hex[i] = '\0';

    int len = strlen(hex);
    for (int j = 0; j < len / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }

    return hex;
}

int main() {
    int x;
    char y[100];

    printf("1) From Hexa To Dec\n2) From Dec to Hexa\nEnter The Choice: ");
    scanf("%d", &x);

    if (x == 1) {
        printf("Enter The Number: ");
        scanf("%s", y);
        int dec = hexToDec(y);
        if (dec != -1) {
            printf("Decimal: %d\n", dec);
        }
    } else if (x == 2) {
        printf("Enter The Number: ");
        scanf("%d", &x);
        char* hex = decToHex(x);
        printf("Hexadecimal: %s\n", hex);
        free(hex);
    } else {
        printf("INVALID CHOICE!\n");
    }

    return 0;
}
