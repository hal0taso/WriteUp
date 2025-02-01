#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> C(h);
  REP(i, h)
  {
    cin >> C[i];
  }
  REP(i, w)
  {
    int ans = 0;
    REP(j, h)
    {
      if (C[j][i] == '#')
        ans++;
    }
    cout << ans;
    if (i < w - 1)
      cout << ' ';
    else
      cout << '\n';
  }

  // cout << "YES" << endl;
  return 0;
}
