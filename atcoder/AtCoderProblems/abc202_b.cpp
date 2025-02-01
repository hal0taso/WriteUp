#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  REP(i, n) {
    if (s[i] == '6') {
      s[i] = '9';
    } else if (s[i] == '9') {
      s[i] = '6';
    }
  }
  REP(i, n) { cout << s[n - 1 - i]; }
  cout << endl;
  return 0;
}
