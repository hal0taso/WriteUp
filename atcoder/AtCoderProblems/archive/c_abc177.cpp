#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;

int main() {
  long long N;
  long long res;
  cin >> N;

  vector<long long> A(N);
  ll sum = 0;
  ll mod = 1e9 + 7;
  REP(i, N) {
    cin >> A[i];
    sum += A[i] % mod;
    sum %= mod;
  }

  res = 0;
  REP(i, N - 1) {
    sum -= A[i];
    if (sum < 0) {
      sum += mod;
    }
    res += (sum * A[i]) % mod;
    res %= mod;
  }
  cout << res << endl;
}
