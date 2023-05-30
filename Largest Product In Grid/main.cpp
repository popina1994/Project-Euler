#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int NumMax = 20,
          RowMax = 8,
          AdjacentMax = 4,
RowInc [RowMax][AdjacentMax] = { {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3},
    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, -1, -2, -3}, {0, -1, -2, -3}, {0, -1, -2, -3}
},
ColInc [RowMax][AdjacentMax] = { {0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, -2, -3},
    {0, 1, 2, 3}, {0, -1, -2, -3}, {0, 1, 2, 3}, {0, 0, 0, 0}, {0, -1, -2, -3}
};

int x[NumMax][NumMax];


int main() {
    int productMax = 0;

    freopen("ulaz.in", "r", stdin);

    for (int cnt1 = 0; cnt1 < NumMax; cnt1++)
        for (int cnt2 = 0; cnt2 < NumMax; cnt2++)
            scanf("%d", &x[cnt1][cnt2]);

    for (int row = 0; row < NumMax; row++)
        for (int col = 0; col < NumMax; col++)
            for (int cnt = 0; cnt < RowMax; cnt++) {
                int product = 1;

                for (int cnt1 = 0; cnt1 < AdjacentMax; cnt1++) {
                    int tmpRow = row + RowInc[cnt][cnt1],
                        tmpCol = col + ColInc[cnt][cnt1];

                    if (tmpRow >= NumMax || tmpRow <= 0 || tmpCol >= NumMax || tmpCol <= 0)
                        product = 0;
                    else product *= x[tmpRow][tmpCol];
                }

                if (product > productMax) productMax = product;
            }

    printf("%d", productMax);
    return 0;
}
