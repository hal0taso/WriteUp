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
  REP(i, s.size())
  if (s[i] < 'a')
  {
    ans = i + 1;
  }
  cout << ans << endl;
  return 0;
}
