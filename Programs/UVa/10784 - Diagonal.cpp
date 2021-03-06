#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
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







void MAIN() {

  int TC = 1;
  ll N;

  while(cin >> N, N != 0) {

    ll lo = 1, hi = 44800000, mid;
    ll n = hi;

    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (mid*mid - 3*mid >= 2*N) {
        n = mid;
        hi = mid-1;
      } else {
        lo = mid+1;
      }
    }

    cout << "Case " << TC++ << ": " << n << endl;

  }

}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  MAIN();
}













