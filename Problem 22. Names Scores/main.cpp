#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> v;

int main() {
    string s;
    string curString;
    freopen("Ulaz.in", "r", stdin);
    freopen("Izlaz.out", "w", stdout);

    getline(cin, s);
    bool end = true;
    for (int idx = 0; idx < s.length(); idx++) {
        if (!end){
            if (s[idx] != '"')
                curString.append(1, s[idx]);
            else {
                end = true;
                v.push_back(curString);
                curString.clear();
            }
        }
        else if (s[idx] == '"')
            end = false;
    }
    sort(v.begin(), v.end());
    long long score = 0;
    for (int idxVector = 0; idxVector < v.size(); idxVector++) {
        long long curScore = 0;
        for (int idx = 0; idx < v[idxVector].length(); idx ++)
            curScore += v[idxVector][idx] - 'A' + 1;

        score += curScore * (idxVector + 1);



    }
    cout << score;

    return 0;
}
