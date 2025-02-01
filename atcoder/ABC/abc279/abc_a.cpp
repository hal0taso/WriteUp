#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  for (char si : s)
  {
    if (si == 'v')
      ans++;
    else
      ans += 2;
  }
  cout << ans << endl;
  // cout << "YES" << endl;
  return 0;
}
