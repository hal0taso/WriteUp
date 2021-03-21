#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MOD 1000000007

int main() {
  int n, ans = 1, ai;
  cin >> n;
  REP(i, n) {
    cin >> ai;
    if (ai % 2 == 0) {
      ans *= 2;
    }
  }
  cout << pow(3, n) - ans << endl;
  return 0;
}
