#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int NumMax = 1000;

int main() {

    for (int cnt1 = 1; cnt1 < NumMax; cnt1++)
        for (int cnt2 = 1; cnt2 < NumMax - cnt1; cnt2++) {
            int cnt3 = NumMax - cnt1 - cnt2;
            if (cnt1 * cnt1 + cnt2 * cnt2 == cnt3 * cnt3)
                printf("%d\n", cnt1 * cnt2 * cnt3);
        }

    return 0;
}
