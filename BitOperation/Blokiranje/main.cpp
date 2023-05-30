#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int nmax = 1e3, milion = 1000000;

int n, number = 0, value, m, x[nmax + 2][nmax + 2], indx[4] = {1, -1, 0, 0}, indy[4] = {0, 0, 1, -1}, depth = 2, counter = 1;

struct coordinate {
    int i, j;
    void set (int x, int y) {
        i = x;    // "konstruktor"
        j = y;
    }
    void print() {
        printf("%d %d\n", i, j);
    }
    int value() {
        return x[i][j];
    }
};

coordinate t, p, begin;

queue <coordinate> q, qsol; // kada budem isao po matrici da znam gde treba ici




void ispis() {
    freopen("main.out", "w", stdout);
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++)
            printf("%d ", x[i][j]);
        printf ("\n");
    }
    fclose(stdout);
    freopen("con", "w", stdout);
}

void input() {
    freopen("main.in", "r", stdin);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i <= n+1; i++)
        x[i][0] = x[i][m+1] = -1;
    for (int i = 0; i <= m + 1; i++)
        x[0][i] = x[n+1][i] = -1;
    char c;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            scanf("%c", &c);
            x[i][j] = (c == '.') - 1;
        }
        scanf("\n");
    }
    p.set(1,1);
    q.push(p);

}

void checkset(int i, int j, int depth, int value) {
    if (x[i][j] == value) {
        coordinate p;
        p.set(i, j);
        q.push(p);//stavi se u listu da se provere kasnije susedi
        if (depth ==  -2)
            x[i][j] += milion;
        else x[i][j] = depth;
    }
}

void bfs() {
    x[1][1] = 1;
    depth = 2, counter = 1;
    while (q.size() != 0) { // dok ne predje matricu
        for (int in = 0; in < counter; in++) { // dok ne ocisti sve odredjen dubine
            p = q.front();
            q.pop(); //brisem onaj koji je obradjen
            for (int j = 0; j < 4; j++)
                checkset(p.i + indx[j], p.j + indy[j], depth, 0); // proverava sve susede
        }
        counter = q.size();
        depth ++; // povecava dubinu
    }
    p.set(n, m);
    q.push(p);
    depth = x[n][m];
    counter = 1; // podesava ponovo sve

}


int equal(coordinate x, coordinate y) {
    if (x.value() == y.value())
        return 1;
    return 0;
}





void output() {
    printf("%d\n", qsol.size());
    while (qsol.size() != 0) {
        coordinate t;
        t = qsol.front();
        qsol.pop();
        t.print();
    }
}

void sp() {
    while(q.size() != 0) { // dok ponovo ne obradi potrebno
        for (int in = 0; in < counter; in++) { // prelazi dok ne dodje
            p = q.front(); //
            q.pop();
            for (int j = 0; j < 4; j++) {
                int it = p.i+indx[j], jt = p.j + indy[j];
                if (x[it][jt] == depth - 1) {
                    x[it][jt] += milion;
                    coordinate z;
                    z.set(it, jt);
                    q.push(z);
                    break;
                }
            }
        }
        counter = q.size();
        depth--;
    }
}

void putinqueue(coordinate begin, coordinate end) {
    while (!equal(begin, end)) {
        for (int i = 0; i < 4; i++) {
            int it = begin.i + indx[i], jt = begin.j + indy[i];
            if (begin.value() + 1 == x[it][jt]) {
                begin.set(it, jt);
                q.push(begin);
                break;
            }
        }


    }
}

void set() {
    while (q.size() != 0) {
        for (int j = 0; j < 4; j++) {
            int it = p.i + indx[j], jt = p.j + indy[j];
            coordinate r;
            r.set(it, jt);
            if (x[it][jt] <= milion && x[it][jt ]> 0) {
                q.push(r);
                x[it][jt] = 0;
            } else if (x[p.i][p.j] != t.value() && x[it][jt] > t.value()) {// sko je trazena tacka veca ona se uzima
                r.set(t.i, t.j);
                t.set(it, jt);
                putinqueue(r, t);
            }
        }
        q.pop();
        p = q.front();
    }

}

void loading() {

    if (depth != 0) {
        sp();
        p.set(1, 1);// oznacava odakle krecemo u pretrazi
        q.push(p);// oznacava odakle krecemo u trazenju resenja
        t.set(1,1);
        x[n][m] += milion;
        while (t.i != n || t.j != m) { // kada je doslo do kraja
            set();//podesi ostalo
            if ((t.value() != x[1][1]) && (t.value() != x[n][m]) && (qsol.size() == 0  || !equal(qsol.back(), t) )){

                qsol.push(t);
            }



            for (int j = 0; j < 4; j++) {
                int it = t.i + indx[j], jt = t.j + indy[j];
                if (x[it][jt] == t.value() +1) {

                    t.set(it, jt);
                    p.set(it, jt);
                    q.push(t);
                    if (!(t.i == n && t.j == m))
                        qsol.push(t);
                    break;
                }
            }
        }
    } else for(int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if ((i != 1 || j !=1) && (i != n || j != m) && (x[i][j] != -1)) {
                    coordinate t;
                    t.set(i, j);
                    qsol.push(t);
                }
}

int main() {
    input();
    bfs();
    loading();
    ispis();
    output();
}
