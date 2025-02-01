#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i <= n - 1; i++)
  {
    int ans = 0;
    for (int k = 1; k <= n - i; k++)
    {
      if (s[k - 1] != s[k + i - 1])
        ans = k;
      else
        break;
    }
    cout << ans << endl;
  }
  return 0;
}