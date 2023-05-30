#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int DigitMax = 5, NumberMax = 1000;

int main () {
    int tmpDigit[DigitMax], maxProduct = 0;

    freopen("ulaz.in", "r", stdin);

    memset(tmpDigit, 0, sizeof(tmpDigit));

    for (int cnt = 0; cnt < NumberMax; cnt++) {
        int digitPos = cnt % DigitMax, product = 1;
        char chrNum;

        scanf("%c", &chrNum);
        tmpDigit[digitPos] = chrNum - '0';

        for (int cnt1 = 0; cnt1 < DigitMax; cnt1++)
            product *= tmpDigit[cnt1];

        maxProduct =  product > maxProduct ? product : maxProduct;
    }

    printf("%d", maxProduct);
}
