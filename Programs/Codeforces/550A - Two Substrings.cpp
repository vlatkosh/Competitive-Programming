#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






void SOLVE() {

  string s, t = "";
  cin >> s;
  
  vi abp, bap;
  
  for (int i = 0; i < s.length()-1; ++i) {
    if (s[i] == 'A' && s[i+1] == 'B') {
      abp.push_back(i);
    } else if (s[i] == 'B' && s[i+1] == 'A') {
      bap.push_back(i);
    }
  }

  for (int i = 0; i < abp.size(); ++i) {
    for (int j = bap.size()-1; j >= 0; --j) {
      if (abs(bap[j] - abp[i]) > 1) {
        cout << "YES\n";
        return;
      }
    }
  }
    
  cout << "NO\n";
      
  




}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  SOLVE();
}















