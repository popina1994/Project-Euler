#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int NUM_MONTHS = 12;

enum Day { MON = 0, TUE, WED, THU, FRI, SAT, SUN };

class Date {
    int d, m, y;
    Day curDay;
    bool LeapYear() const; // returns true if year is leap
    inline int DaysInCurMonth() const;
    void NextDate(); // returns next date of current date
public:
    Date(int _d = 1, int _m = 1, int _y = 1900, Day _curDay = MON) : d(_d), m(_m), y(_y), curDay(_curDay) {}
    Date& operator++();
    Date operator++(int);

    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;

    friend ostream& operator<<(ostream& out, const Date&);

    Day GetCurDay() const;
    int GetDay() const;

    static const int NUM_DAYS[NUM_MONTHS+1];
};

const int Date::NUM_DAYS[NUM_MONTHS + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Date::LeapYear() const {
    return ( (y % 4 == 0) && (y % 100 != 0) ) || (y % 400 == 0);
}

int Date::DaysInCurMonth() const {
    if ( (m == 2) && LeapYear())
        return NUM_DAYS[m] + 1;
    return NUM_DAYS[m];
}

void Date::NextDate() {
    if (d == DaysInCurMonth()) {
        d = 1;
        if (m == NUM_MONTHS) {
            m = 1; y++;
        }
        else m++;
    }
    else d++;
    curDay = static_cast<Day>((curDay + 1) % 7);

}

Date& Date::operator++() {
    NextDate();
    return *this;
}

Date Date::operator++(int) {
    Date d(*this);
    NextDate();
    return d;
}

bool Date::operator==(const Date& date) const {
    return d == date.d && y == date.y && m == date.m;
}

bool Date::operator!=(const Date& date) const {
    return d != date.d || y != date.y || m != date.m;
}

Day Date::GetCurDay() const {
    return curDay;
}

int Date::GetDay() const {
    return d;
}

ostream& operator<<(ostream& out, const Date& d) {
    const char* days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    return out << d.d << " - " << d.m << " - " << d.y << " " << days[d.curDay];

}

int main() {
    Date end(31, 12, 2000), it, begin(1, 1, 1901);
    int cnt = 0;

    while (it != begin)
        it++;

    for (; it != end; it++) {
        if ( (it.GetCurDay() == SUN) && (it.GetDay() == 1) ) {
            cout << it << endl;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
