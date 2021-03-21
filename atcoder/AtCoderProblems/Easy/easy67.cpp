#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (long i = a; i < b; ++i)
#define REP(i, n) for (long i = 0; i < n; ++i)

int main() {
  long n;
  map<string, long> S;
  string si;
  long c = 0;
  cin >> n;
  REP(i, n) {
    cin >> si;
    if (S.find(si) == S.end()) {
      S[si] = 1;
    } else {
      S[si]++;
    }
    if (c < S[si]) {
      c = S[si];
    }
  }
  for (auto it = S.begin(); it != S.end(); it++) {
    if (c == it->second) {
      cout << it->first << endl;
    }
  }
  return 0;
}
