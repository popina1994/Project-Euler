#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

constexpr int NUM = 11, DEC = 10, BASE = 3;

constexpr int FAKT[DEC + 1] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };

int mod[NUM] = {0};


class Base3{
    int x[DEC] = { 0 };
    void Inc();
public:
    bool End() const;
    int Count() const;
    int Sum() const;
    int CountPermZero() const; // including leading zero
    int CountPerm() ;

    Base3 operator~();
    Base3 operator++(int);
    Base3& operator++();
    int operator[](int) const;

    friend ostream& operator<<(ostream& out, const Base3&);
};

bool Base3::End() const {
    for (int i = 0; i < DEC; i++)
        if (x[i] != 2)
            return false;
    return true;
}

int Base3::Count() const {
    int cnt = 0;
    for (int i = 0; i < DEC; i ++)
        cnt += x[i];
    return cnt;
}

int Base3::Sum() const {
    int sum = 0;
    for (int i = 0; i < DEC; i ++)
        sum += i * x[i];
    return sum;
}

void Base3::Inc() {
    int carry = 1;
    for (int i = DEC - 1; i >= 0 && carry != 0; i --) {
        if (x[i] + carry == BASE)
            x[i] = 0;
        else {
            x[i] += carry;
            carry = 0;
        }
    }
}

int Base3::CountPermZero() const {
    int perm = FAKT[DEC];
    for (int i = 0; i < DEC; i ++)
        perm /= FAKT[x[i]];
    return perm;
}

int Base3::CountPerm() {
    if (x[0] == 0)
        return CountPermZero();
    int perm = CountPermZero(), permNoZero = FAKT[DEC - 1];
    x[0] --;
    for (int i = 0; i < DEC; i ++)
        permNoZero /= FAKT[x[i]];
    x[0] ++;
    return perm - permNoZero;
}

Base3 Base3::operator~() {
    Base3 b3;
    for (int i = 0; i < DEC; i ++)
        b3.x[i] = BASE - 1 - x[i];
    return b3;
}

Base3 Base3::operator++(int) {
    Base3 b3(*this);
    Inc();
    return b3;
}

Base3& Base3::operator++() {
    Inc();
    return *this;
}

int Base3::operator[](int idx) const {
    return x[idx];
}

ostream& operator<<(ostream& out, const Base3& b3) {
    for (int i = 0; i < DEC; i++)
        cout << b3.x[i];
    return out;
}

int main() {
    int sum = 0;
    long long cnt = 0;


    for (int i = 0; i <= 9; i ++)
        sum += i;
    sum *= 2;
    freopen("main.out", "w", stdout);
    for (Base3 b3; !b3.End(); b3++) {
            int curSum = b3.Sum();
        if ( (b3.Count() == DEC) &&  ( ((sum -  2 * curSum) % NUM) == 0) ) {
            Base3 b3Reverse = ~b3; // complement
            cnt += static_cast<long long>(b3.CountPerm()) * static_cast<long long> (b3Reverse.CountPermZero());

        }
    }

    cout << cnt << endl;

    return 0;
}
