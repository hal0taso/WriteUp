#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i, n)
  cin >> s[i];
  vector<string> t(m);
  REP(i, m)
  cin >> t[i];
  int ans = 0;
  REP(i, n)
  {
    REP(j, m)
    {
      if (s[i].substr(3, 3) == t[j])
      {
        ans++;
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
