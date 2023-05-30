#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int TestMax = 1e4;

int sumDivisor[TestMax];

int main() {
    int counter = 0;

    memset(sumDivisor, 0, sizeof(sumDivisor));

    for (int cnt1 = 1; cnt1 < TestMax; cnt1++)
        for (int cnt2 = 2 * cnt1; cnt2 < TestMax; cnt2 += cnt1)
            sumDivisor[cnt2] += cnt1;

    for (int cnt1 = 1; cnt1 < TestMax - 1; cnt1++)
        for (int cnt2 = cnt1; cnt2 < TestMax; cnt2++)
            if (sumDivisor[cnt1] == cnt2 && sumDivisor[cnt2] == cnt1 && cnt1 != cnt2) {
                printf("%d %d\n", cnt1, cnt2);
                counter += cnt1 + cnt2;

            }

    printf("%d", counter);
    return 0;
}
