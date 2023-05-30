#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr int NUM_MAX = 1'000'000;

int main() {
    long long sum = 0;

    freopen("Izlaz.out", "w", stdout);

    for (int idx = 10; idx < NUM_MAX; idx++ ) {

        int tmpIdx = idx, sumOfFifthPower = 0;
        while (tmpIdx > 0) {
            int digit = tmpIdx % 10;
            sumOfFifthPower += digit * digit * digit * digit * digit;
            tmpIdx /= 10;
        }
        if (idx == sumOfFifthPower)
            sum += idx;
    }
    cout << sum;
    return 0;
}
