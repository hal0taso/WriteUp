#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int N;
  cin >> N;
  if (N < 126)
    cout << 4 << endl;
  else if (N < 212)
    cout << 6 << endl;
  else
    cout << 8 << endl;

  return 0;
}
