#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int d, n;
  cin >> d >> n;
  if (n == 100)
    n++;
  REP(i, d) { n *= 100; }
  cout << n << endl;

  return 0;
}
