#include <stdbool.h>
#include <stdio.h>

/*
 *
 * American Express uses 15-digit numbers.
 *
 * MasterCard uses 16-digit numbers.
 *
 * Visa uses 13- and 16-digit numbers.
 */

int main(void)
{
    char input[16];
    int num[16], cnt = 0;

    // Get input credit card numbers from user
    printf("Number: ");
    for (; cnt < sizeof(input); cnt++) {
        scanf("%c", &input[cnt]);
        if (input[cnt] == '\n')
            break;
    }

    // Invalid length of numbers
    if (cnt < 13)
        goto invalid;

    // Checks whether input is digit
    for (int i = 0; i < cnt; i++) {
        num[i] = input[i] - 48;
        if (num[i] < 0 || num[i] > 9)
            goto invalid;
    }

    // Luhn’s Algorithm
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
        int d;
        if (cnt & 0x1)
            d = (i & 0x1) ? num[i] * 2 : num[i];
        else
            d = (i & 0x1) ? num[i] : num[i] * 2;

        sum += d / 10;
        sum += d % 10;
    }

    if (sum % 10)
        goto invalid;

    // American Express
    if (cnt == 15) {
        int two_d = num[0] * 10 + num[1];
        if (two_d != 34 && two_d != 37)
            goto invalid;
        printf("AMEX\n");
        return 0;
    }

    // Visa
    if ((cnt == 13 || cnt == 16) && num[0] == 4) {
        printf("VISA\n");
        return 0;
    }

    // Mastercard
    if (cnt == 16) {
        int two_d = num[0] * 10 + num[1];
        if (two_d < 51 || two_d > 55)
            goto invalid;
        printf("MASTERCARD\n");
        return 0;
    }

invalid:
  printf("INVALID\n");
  return -1;
}
