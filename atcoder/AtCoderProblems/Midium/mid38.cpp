#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main() {
  int N;
  int M;
  int di;
  int ti;
  map<int, int> D;
  bool flag = true;
  cin >> N;
  REP(i, N) {
    cin >> di;
    D[di]++;
  }
  cin >> M;
  REP(i, M) {
    cin >> ti;
    D[ti]--;
    if (D[ti] < 0)
      flag = false;
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
}
