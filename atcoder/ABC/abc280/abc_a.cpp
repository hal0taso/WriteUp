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
  vector<string> S(h);
  int ans = 0;
  REP(i, h)
  {
    cin >> S[i];
    REP(j, w)
    {
      if (S[i][j] == '#')
        ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
