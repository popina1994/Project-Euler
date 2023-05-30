#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int maxLines = 100;

int x[maxLines][maxLines] = {0}, meme[maxLines][maxLines] = {0};

int main() {
    freopen("Ulaz.in", "r", stdin);
    freopen("Izlaz.out", "w", stdout);
    for (int row = 0; row < maxLines; row++) {
        for (int col = 0; col <= row; col ++) {
            scanf("%d", &x[row][col]);
            printf("%d ", x[row][col]);
        }
        printf("\n");
    }

    meme[0][0] = x[0][0];
    for (int row = 1; row < maxLines; row++)
        for (int col = 0; col <= row; col ++) {
            int left = 0, right = 0;
            if (col - 1 >= 0)
                left = meme[row - 1][col - 1];
            right = meme[row - 1][col];
            meme[row][col] = max(left, right) + x[row][col];
        }

    int curMax = 0;
    for (int col = 0; col < maxLines; col++) {
        curMax = max(curMax, meme[maxLines-1][col]);
    }
    cout << curMax;


    return 0;
}
