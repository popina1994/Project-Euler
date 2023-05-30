#include <stdio.h>
#include <stdlib.h>

int main() {
    int sum = 0, i;
    freopen("izlaz.out", "w", stdout);
    for (i = 2; i < 1000; i ++) {
        if ( (i % 3 == 0) || (i % 5 == 0) )
            sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
