#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

constexpr const int PRIME_FACT_MAX = 100;

bool isPrime [PRIME_FACT_MAX + 1] = {0};

vector <int> prime;

void CalculatePrimes(bool prime[], int n) {
    for (int i = 2; i <= n; i ++)
        prime[i] = true;

    for (int i = 2; i <= n / 2; i++)
        for (int j = 2 * i; j <= n; j += i)
            prime[j] = false;
}

void PushPrimes(bool prime[], vector<int>& v, int n) {
    for (int i = 0; i <= n; i ++)
    if (prime[i])
        v.push_back(i);
}

struct Number {
    vector<unsigned int> primeRepresentation;
    Number(int primeNum)  {
        primeRepresentation.resize(primeNum, 0);
    }
    bool operator<(const Number& n1) const {
        for (int idx = primeRepresentation.size() - 1; idx >= 0; idx --)
            if (primeRepresentation[idx] < n1.primeRepresentation[idx])
                return true;
            else
                if (primeRepresentation[idx] > n1.primeRepresentation[idx])
                return false;
        return false;
    }

    bool operator==(const Number& n1) const {
        for (int idx = primeRepresentation.size() -1; idx >= 0; idx --)
            if (n1.primeRepresentation[idx] != primeRepresentation[idx])
                return  false;
        return true;
    }

    friend ostream& operator<<(ostream& out, const Number& n) {
        for (unsigned int idx = 0; idx < n.primeRepresentation.size(); idx ++)
            out << prime[idx] << "^" << n.primeRepresentation[idx] << " ";
        return out;
    }
};

set <Number> s;



int main() {
    CalculatePrimes(isPrime, PRIME_FACT_MAX);
    PushPrimes(isPrime, prime, PRIME_FACT_MAX);

    freopen("izlaz.out", "w", stdout);

    for (int a = 2; a <= 100; a++)
        for (int b = 2; b <= 100; b++) {
            Number n(prime.size());
            int curA = a;

            for (unsigned int i = 0; i < prime.size(); i++)
            while ( (curA % prime[i]) == 0) {
                    n.primeRepresentation[i] ++;
                    curA /= prime[i];
            }
            for (int i = 0; i < prime.size(); i++)
                n.primeRepresentation[i] *= b;
            s.insert(n);
            //cout << n << endl;
        }

    cout << s.size();

    return 0;
}
