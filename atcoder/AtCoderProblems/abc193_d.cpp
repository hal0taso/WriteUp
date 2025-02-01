#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int score(string s) {
  vector<int> a(10);
  for (char c : s) {
    a[c - '0']++;
  }
  int res = 0;
  for (int i = 1; i <= 9; ++i) {
    int x = 1;
    REP(j, a[i]) { x *= 10; }
    res += i * x;
  }
  return res;
}

int main() {
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;
  vector<int> c(10, k);
  c[0] = 0;
  REP(i, 4) {
    c[s[i] - '0']--;
    c[t[i] - '0']--;
  }
  ll cnt = 0;
  for (int a = 1; a <= 9; a++) {
    for (int b = 1; b <= 9; b++) {
      s[4] = '0' + a;
      t[4] = '0' + b;
      if (score(s) > score(t)) {
        if (a == b) {
          cnt += (ll)c[a] * (c[a] - 1);
        } else {
          cnt += (ll)c[a] * c[b];
        }
      }
    }
  }
  ll C = 0;
  REP(i, 10) { C += c[i]; }
  ll tot = C * (C - 1);
  double ans = (double)cnt / tot;
  cout << ans << endl;
  return 0;
}
