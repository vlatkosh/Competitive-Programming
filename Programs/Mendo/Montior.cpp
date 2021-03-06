#include <bits/stdc++.h>
using namespace std;
// printing
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _dbg(_it, args); }
void _dbg(istream_iterator<string> it) {++it;}
template<typename T, typename... Args>
void _dbg(istream_iterator<string> it, T a, Args... args) { cout << setw(8) << std::left << *it << " = " << setw(4) << std::right << a << "\n"; _dbg(++it, args...);}
template<typename T>
ostream& _containerprint(ostream &out, T const &val) {return (out << setw(4) << std::right << val << " ");}
template<typename T1, typename T2>
ostream& _containerprint(ostream &out, pair<T1, T2> const &val) {return (out << "{" << val.first << " " << val.second << "} ");}
template<template<typename, typename...> class TT, typename... Args>
ostream& operator<<(ostream &out, TT<Args...> const &cont) {for(auto&& elem : cont) { _containerprint(out, elem); } return out;}
// typedefs
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
// other
#define endl '\n'
#define all(v) begin(v), end(v)
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}









void Solve() {

  int m, n, k, p;
  cin >> m >> n >> k >> p;
  
  vector<bool> row(m+1, 0), col(n+1, 0);
  vector<int> rowsum(m+1, -1), colsum(n+1, -1);
  
  for (int i = 0; i < p; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    if (t == 1) row[x] = 1;
    else        col[y] = 1;
  }

  rowsum[0] = colsum[0] = 0;
  for (int x = 1; x <= m; ++x) {
    rowsum[x] = rowsum[x-1] + row[x];
  }
  for (int y = 1; y <= n; ++y) {
    colsum[y] = colsum[y-1] + col[y];
  }

  int fx = -1, fy = -1, fxsum = 1e9, fysum = 1e9;
  for (int x = 1; x+k-1 <= m; ++x) {
    int br = rowsum[x+k-1] - rowsum[x-1];
    if (br < fxsum) {
      fx = x;
      fxsum = br;
    }
  }
  for (int y = 1; y+k-1 <= n; ++y) {
    int br = colsum[y+k-1] - colsum[y-1];
    if (br < fysum) {
      fy = y;
      fysum = br;
    }
  }

  cout << fxsum + fysum << endl;


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
