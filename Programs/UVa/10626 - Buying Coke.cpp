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
#ifdef _DEBUG
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
#endif
// other
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const int mod = 1e9+7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




int total;
int C;
int dp[151][151][51];

int F(int b, int n5, int n10) {
  if (b == C) return 0;
  if (dp[b][n5][n10] != -1) return dp[b][n5][n10];
  int n1 = total - (8*b + 5*n5 + 10*n10);
  int res = 1e9;
  if (n1 >= 8)             res = min(res, 8 + F(b+1, n5, n10));
  if (n1 >= 3 && n5 >= 1)  res = min(res, 4 + F(b+1, n5-1, n10));
  if (n1 >= 3 && n10 >= 1) res = min(res, 4 + F(b+1, n5+1, n10-1));
  if (n5 >= 2)             res = min(res, 2 + F(b+1, n5-2, n10));
  if (n10 >= 1)            res = min(res, 1 + F(b+1, n5, n10-1));
  return dp[b][n5][n10] = res;
}

void Solve() {
  int n1, n5, n10;
  cin >> C >> n1 >> n5 >> n10;
  total = n1 + 5*n5 + 10*n10;
  memset(dp, -1, sizeof(dp));
  cout << F(0, n5, n10) << endl;






}

void Input() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    Solve();
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Input();
}
