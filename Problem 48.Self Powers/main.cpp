#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr int NUM_MAX = 1000;

int main() {
    long long sum = 0;

    freopen("Izlaz.out", "w", stdout);

    for (int idx = 1; idx <= NUM_MAX; idx ++) {
        long long pow = 1;

        for (int idxPow = 1; idxPow <= idx; idxPow++)
            pow = (pow * idx) % 10'000'000'000;
        cout << pow << endl;
        sum = (sum + pow) % 10'000'000'000;
    }
    cout << sum;
    return 0;
}
