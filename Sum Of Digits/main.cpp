#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    freopen("ulaz.in", "r", stdin);
    char c;
    int sum = 0;

    scanf("%c", &c);

    while (c != '.') {
        if (c <= '9' && c >= '0') sum += c - '0';
        scanf("%c", &c);
    }

    printf("%d", sum);
    return 0;
}
