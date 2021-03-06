/*
https://szkopul.edu.pl/problemset/problem/dABzva_j1-BvzKMsyxkuRoue/site/?key=statement
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1001;

int R, C;
vector<pii> edges[2]; // by weight (0 or 1)
bool wall[2][maxn][maxn];

inline int fix(int r, int c) {
    return r*C + c;
}

struct DSU {
    int n;
    vector<int> p, rank;
    DSU(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rank.assign(n, 0);
    }
    inline int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }
    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        p[y] = x;
        return true;
    }
} dsu(maxn*maxn);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C-1; ++c) {
            char ch;
            cin >> ch;
            edges[ch == 'C'].emplace_back(fix(r, c), fix(r, c+1));
        }
    }
    for (int r = 0; r < R-1; ++r) {
        for (int c = 0; c < C; ++c) {
            char ch;
            cin >> ch;
            edges[ch == 'C'].emplace_back(fix(r, c), fix(r+1, c));
        }
    }
    int cost = edges[1].size();
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            wall[0][r][c] = wall[1][r][c] = true;
        }
    }
    for (int w = 0; w < 2; ++w) {
        for (auto& p : edges[w]) {
            if (dsu.unite(p.first, p.second)) {
                cost -= w;
                int r1 = p.first / C, c1 = p.first % C;
                int r2 = p.second / C, c2 = p.second % C;
                if (r1 == r2) {
                    wall[0][r1][c1] = false;
                } else {
                    wall[1][r1][c1] = false;
                }
            }
        }
    }
    cout << R*(C-1) + (R-1)*C - (R*C - 1) << " " << cost << endl;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C-1; ++c) {
            cout << (wall[0][r][c] ? 'Z' : '.');
        }
        cout << endl;
    }
    for (int r = 0; r < R-1; ++r) {
        for (int c = 0; c < C; ++c) {
            cout << (wall[1][r][c] ? 'Z' : '.');
        }
        cout << endl;
    }
    // cout << "X";
    // for (int c = 0; c < C; ++c) {
    //     cout << "XXXX";
    // }
    // cout << "\n";
    // for (int r = 0; r < R; ++r) {
    //     cout << "X";
    //     for (int c = 0; c < C; ++c) {
    //         cout << "   ";
    //         if (wall[0][r][c]) {
    //             cout << "X";
    //         } else {
    //             cout << ".";
    //         }
    //     }
    //     cout << "\nX";
    //     for (int c = 0; c < C; ++c) {
    //         if (wall[1][r][c]) {
    //             cout << "XXX";
    //         } else {
    //             cout << " . ";
    //         }
    //         cout << "X";
    //     }
    //     cout << "\n";
    // }
}
