#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main () {

    for (int cnt1 = 1; ; cnt1++) {
        bool found = true;
        for (int cnt2 = 1; cnt2 <= 20; cnt2 ++)
            if (cnt1 % cnt2 != 0) {
                printf("%d %d\n", cnt1, cnt2);
                found = false;
                break;
            }

        if (found) {
            printf("%d", cnt1);
            break;
        }
    }

    return 0;
}
