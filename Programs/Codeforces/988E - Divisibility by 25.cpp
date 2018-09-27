#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <functional>
#include <iterator>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
// printing
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _dbg(_it, args); }
void _dbg(istream_iterator<string> it){++it;}
template<typename T, typename... Args>
void _dbg(istream_iterator<string> it, T a, Args... args){
  if (*it=="'\\n'" || *it=="\"\\n\"" || *it=="endl") { cout << "\n"; }
  else { cout << setw(8) << std::left << *it << " = " << setw(4) << std::right << a << "\n"; }
  _dbg(++it, args...); }
template<typename T>
std::ostream& _containerprint(std::ostream &out, T const &val) { return (out << setw(4) << val << " "); }
template<typename T1, typename T2>
std::ostream& _containerprint(std::ostream &out, std::pair<T1, T2> const &val) { return (out << "{" << setw(4) << val.first << " " << setw(4) << val.second << "} "); }
template<template<typename, typename...> class TT, typename... Args>
std::ostream& operator<<(std::ostream &out, const TT<Args...> &cont) { for(auto&& elem : cont) { _containerprint(out, elem); } return out; }
std::ostream& operator<<(std::ostream &out, const std::string &s) { return operator << <char>(out, s); }
// other
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}


















int go(string &s, int i, int j) {
  int res = 0;
  if (i == 0) {
    int k = 1;
    while (k < (int)s.length() && s[k] == '0') ++k;
    if (k == (int)s.length()) return -1e9;
    while (k > 1) {
      swap(s[k-1], s[k]);
      --k;
      ++res;
    }
  }
  while (i < j) {
    swap(s[i], s[i+1]);
    ++i;
    ++res;
  }
  return res;
}

void Solve() {
  string s, u, t;
  cin >> s;
  
  int n = s.length();
  
  if (n == 1) {
    cout << -1 << endl;
    return;
  }
  if ((10*(s[n-2]-'0') + s[n-1]-'0') % 25 == 0) {
    cout << 0 << endl;
    return;
  }
  
  int ans = 1e9;
  
  for (int j = 0; j < n; ++j) {
    t = s;
    int moves1 = go(t, j, n-1);
    for (int i = 0; i < n-1; ++i) {
      if ((10*(t[i]-'0') + t[n-1]-'0') % 25 == 0) {
        u = t;
        int moves2 = go(u, i, n-2);
        ans = min(ans, moves1 + moves2);
      }
    }
  }
  

  if (ans == 1e9) ans = -1;
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
