#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    ll has[2][101] = {};
    for (int j = 0; j < 2; ++j){
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++has[j][x];
        }
    }
    ll ans = 0;
    for (int a = 1; a <= 100; ++a) {
        for (int b=1; b <= 100; ++b) {
            if (a+b >= k && has[0][a] && has[1][b]) {
                ans += has[0][a] * has[1][b];
            }
        }
    }
    cout << ans;
}
