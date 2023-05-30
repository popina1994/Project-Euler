#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MinThree = 100, MaxThree = 999, ProductMax = 6;

void ConvertToString(int num, char stringBroj[], int &len) {
    int cnt;

    for (cnt = 0; num > 0; num /= 10)
       stringBroj[cnt++] = num % 10 + '0';
    len = cnt;
}

int main () {
    char stringBroj[ProductMax + 1];
    int len, maxPalindrom = 0;
    bool palindrom;

    for (int cnt1 = MinThree; cnt1 <= MaxThree; cnt1 ++)
        for (int cnt2 = MinThree; cnt2 <= MaxThree; cnt2 ++) {
            ConvertToString(cnt1 * cnt2, stringBroj, len);

            palindrom = true;
            for (int cnt3 = 0; cnt3 < len / 2; cnt3 ++)
                if (stringBroj[cnt3] != stringBroj[len - cnt3 - 1]) {
                    palindrom = false;
                    break;
                }

            if (palindrom && cnt1 * cnt2 > maxPalindrom)
                maxPalindrom = cnt1 * cnt2;
        }

    printf("%d", maxPalindrom);
return 0;
}
