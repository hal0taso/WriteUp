#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
  int N, K;
  int x;
  int res = 0;

  cin >> N;
  cin >> K;
  REP(i, N) {
    cin >> x;
    res += min(x, K - x);
  }
  cout << res * 2 << endl;
}
