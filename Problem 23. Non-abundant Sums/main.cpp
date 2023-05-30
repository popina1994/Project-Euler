#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MEME_MAX = 28123;

long long meme[MEME_MAX + 1] = {0};
bool nonAbdunant[MEME_MAX + 1] = {0};


vector<int> v;



int main() {
    freopen("Izlaz.out", "w", stdout);

    for (int idxMeme = 1; idxMeme <= MEME_MAX; idxMeme ++)
        for (int idxMemeDiv = idxMeme * 2; idxMemeDiv <= MEME_MAX; idxMemeDiv += idxMeme)
            meme[idxMemeDiv] += idxMeme;

    for (int idx = 0; idx < MEME_MAX + 1; idx ++)
        if (meme[idx] > idx)
            v.push_back(idx);

    for (auto it1 = v.begin(); it1 != v.end(); it1++)
        for (auto it2 = v.begin(); it2 != v.end(); it2++)
            if (*it2 + *it1 <= MEME_MAX + 1)
                nonAbdunant[*it2 + *it1] = true;
    long long sum = 0;
    for (int idx = 0; idx <= MEME_MAX; idx++)
        if (!nonAbdunant[idx]) {
            printf("%d\n", idx);
            sum += idx;
        }
    cout << sum;
    return 0;
}
