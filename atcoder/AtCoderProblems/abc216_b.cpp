#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main() {
  int n;
  cin >> n;
  map<pair<string, string>, int> M;
  string s, t;
  REP(i, n) {
    cin >> s >> t;
    pair<string, string> p = make_pair(s, t);
    M[p]++;
    if (M[p] > 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
