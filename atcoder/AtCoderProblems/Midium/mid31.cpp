#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

bool comp(char a, char b) { return a > b; }

int main() {
  int n;
  cin >> n;
  int ai;
  int n_odd = 0;
  int n_4x = 0;
  REP(i, n) {
    cin >> ai;
    if (ai % 2 == 1)
      n_odd++;
    if (ai % 4 == 0)
      n_4x++;
  }
  if (n_odd <= n_4x)
    puts("Yes");
  else if (2 * n_odd == n + 1 && 2 * n_4x == n - 1)
    puts("Yes");
  else
    puts("No");

  return 0;
}
