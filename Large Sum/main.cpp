#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

const int DigitMax = 50, cifaraMax = 100;



int main() {
    std :: stack <int> num1, num2, sol;
    char c;


    freopen("ulaz.in", "r", stdin);

    for (int cntNumDigit = 0; cntNumDigit < DigitMax; cntNumDigit++) {
            scanf("%c", &c);
            while (c > '9' || c < '0') scanf("%c", &c);
            num1.push(c -'0');
        }

    for (int cnt1 = 0; cnt1 < cifaraMax - 1; cnt1 ++) {

        for (int cntNumDigit = 0; cntNumDigit < DigitMax; cntNumDigit++) {
            scanf("%c", &c);
            while (c > '9' || c < '0') scanf("%c", &c);
            num2.push(c -'0');
        }
        // stavlja dva broja na stek u obrnutom poretku od onog kojeg ga cita
        int prenos = 0;

        while (!num1.empty() || !num2.empty()) {
            int brojKojiStavim;

            if (num2.empty()) {
                brojKojiStavim = (num1.top() + prenos) % 10;
                prenos = (num1.top() + prenos) / 10;
            } else {
                brojKojiStavim = (num1.top() + num2.top() + prenos) % 10;
                prenos = (prenos + num1.top() + num2.top()) / 10;
            }
            sol.push(brojKojiStavim);

            num1.pop();
            if (!num2.empty()) num2.pop();
        }

        if (prenos)
            sol.push(prenos);

        while (!sol.empty()) {
            num1.push(sol.top());
            sol.pop();
        }
    }

    while (!num1.empty()) {
        sol.push(num1.top());
        num1.pop();
    }

    while (!sol.empty()) {
        printf("%d", sol.top());
        sol.pop();
    }
    return 0;
}


