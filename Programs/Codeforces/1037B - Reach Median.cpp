#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






void Solve() {

  int n, m;
  cin >> n >> m;
  
  vi v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(all(v));
  
  int i = n/2;
  ll ans = abs(v[i] - m);
  v[i] = m;
  for (int j = i+1; j < n; ++j) {
    if (v[j] < m) {
      ans += m - v[j];
    } else {
      break;
    }
  }
  for (int j = i-1; j >= 0; --j) {
    if (v[j] > m) {
      ans += v[j] - m;
    } else {
      break;
    }
  }
  
  cout << ans << endl;
  
  
  
  
  
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}











