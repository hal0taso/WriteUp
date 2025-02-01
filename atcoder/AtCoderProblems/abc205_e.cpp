#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

using modint = atcoder::modint1000000007;

modint path(const int X, const int Y) {
  if (X < 0 or Y < 0)
    return 0;
  modint ret = 1;
  for (int i = 1; i <= X + Y; ++i)
    ret *= i;
  for (int i = 1; i <= X; ++i)
    ret /= i;
  for (int i = 1; i <= Y; ++i)
    ret /= i;
  return ret;
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  if (N > M + K) {
    cout << 0 << '\n';
  } else {
    cout << (path(N, M) - path(N - K - 1, M + K + 1)).val() << endl;
  }
  return 0;
}
