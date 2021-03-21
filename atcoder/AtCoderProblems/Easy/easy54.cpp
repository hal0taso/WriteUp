#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
int main() {
  int n;
  set<string> s;
  string w;
  char h, t;
  cin >> n;
  cin >> w;
  s.insert(w);
  t = w[w.size() - 1];
  REP(i, n - 1) {
    cin >> w;
    h = w[0];
    if (s.find(w) != s.end() | h != t) {
      puts("No");
      return 0;
    }
    s.insert(w);
    t = w[w.size() - 1];
  }
  puts("Yes");
  return 0;
}
