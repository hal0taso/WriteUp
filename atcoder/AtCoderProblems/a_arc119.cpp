#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  long long n;
  cin >> n;
  long long a = 0, b = 0, c = 0;
  long long ans = n, res;
  long long tmp = 1;
  while ((tmp) <= n) {
    res = (n / tmp) + (n % tmp) + b;
    if (res < ans) {
      ans = res;
    }
    tmp *= 2;
    b++;
  }
  cout << ans << endl;

  return 0;
}
