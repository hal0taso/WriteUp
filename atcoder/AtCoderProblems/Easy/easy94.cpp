#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MOD 1000000007

int op(int a, int b, int add) {
  if ((add & 1) == 0) {
    return a - b;
  } else if ((add & 1) == 1) {
    return a + b;
  }
}

int main() {
  string s;
  cin >> s;

  int a, b, c, d, ans, i;
  a = s[0] - '0';
  b = s[1] - '0';
  c = s[2] - '0';
  d = s[3] - '0';
  REP(i, 8) {
    if (op(op(op(a, b, (i & 1)), c, ((i >> 1) & 1)), d, ((i >> 2) & 1)) == 7) {
      ans = i;
    }
  }
  map<int, char> M;
  M[0] = '-';
  M[1] = '+';
  cout << a << M[ans & 1] << b << M[(ans >> 1) & 1] << c << M[(ans >> 2) & 1]
       << d << "=7" << endl;
  return 0;
}
