#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int TopLimit = 100;

int main () {
    int SumSquare = 0, SquareSum = 0;

    for (int cnt = 1; cnt <= TopLimit; cnt ++) {
        SumSquare += cnt * cnt;
        SquareSum += cnt;
    }

    printf("%d", SquareSum * SquareSum - SumSquare);
}
