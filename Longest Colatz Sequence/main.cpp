#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int NumOfTerms = 1000000;

int main() {
    long long maxTerms = 0, maxN = 0;

    for (long long cnt = 1; cnt < NumOfTerms; cnt++) {

        long long n = cnt, cntOfTerms = 1;

        for (; n != 1; cntOfTerms ++) {
            if (n & 1) n = 3 * n + 1; // neparan
            else n /= 2;
        }

        if (cntOfTerms > maxTerms) {
            maxTerms = cntOfTerms;
            maxN = cnt;
        }

        printf("%d\n", cnt);
    }

    printf("%d", maxN);
    return 0;
}
