#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr int NUM_MAX = 1001;

int main() {
    freopen("Izlaz.out", "w", stdout);
    long long sum = 1, prev = 1;
    for (int i = 2; i <= NUM_MAX / 2 + 1; i ++) {
        for (int j = 0; j < 4; j ++) {

            prev += 2 * (i - 1);
            sum += prev;
            cout << prev << " ";
        }
        cout << endl;
    }
    cout  << sum;
    return 0;
}
