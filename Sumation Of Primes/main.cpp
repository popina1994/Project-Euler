#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int NumMax = 2e6, SqrtNumMax = 1415;

int notPrime[NumMax];

int main() {

    long long sum = 0;

    memset(notPrime, 0, sizeof(notPrime));

    for (int divisor = 2; divisor < NumMax; divisor ++)
        for (int divided = 2 * divisor; divided < NumMax; divided += divisor)
            notPrime[divided] = 1;

    for (int cnt = 2; cnt < NumMax; cnt++)
        if (!notPrime[cnt]) sum += cnt;

    printf("%lld", sum);
    return 0;
}

