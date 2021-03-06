#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





void _SOLVE_() {
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  if (sx + sy != ex + ey) {
    cout << -1;
    return;
  }
  int dist[100002];
  memset(dist, -1, sizeof(dist));
  dist[sx] = 0;
  queue<int> q;
  q.push(sx);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (x + 1 < 100000 && dist[x + 1] == -1) {
      dist[x + 1] = dist[x] + 1;
      q.push(x + 1);
    }
    int t = x - 1 - (2 * x) % 31;
    if (t > 0 && dist[t] == -1) {
      dist[t] = dist[x] + 1;
      q.push(t);
    }
  }
  cout << dist[ex] << endl;

}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
