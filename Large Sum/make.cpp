#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main () {
    ifstream ulaz;
    string s, sNew = "";

    ulaz.open("ulaz.in");

    while (!ulaz.eof()) {
        getline(ulaz, s);
        sNew += s;
    }

    cout << sNew.length();
}
