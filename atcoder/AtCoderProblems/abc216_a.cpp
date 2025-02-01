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
  if (s[s.size() - 1] - '0' < 3)
    cout << s.substr(0, s.size() - 2) << "-" << endl;
  else if (s[s.size() - 1] - '0' < 7)
    cout << s.substr(0, s.size() - 2) << endl;
  else
    cout << s.substr(0, s.size() - 2) << "+" << endl;

  return 0;
}
