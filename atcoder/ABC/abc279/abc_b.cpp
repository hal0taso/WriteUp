#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
ll MOD = 998244353;
int main()
{
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  REP(i, n)
  {
    if (s.substr(i, m) == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  // cout << "YES" << endl;
  return 0;
}
