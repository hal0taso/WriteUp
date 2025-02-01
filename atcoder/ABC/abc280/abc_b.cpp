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
  int n;

  cin >> n;
  vector<int> s(n);
  vector<int> ans(n);
  long long accum = 0;
  REP(i, n)
  {
    cin >> s[i];
  }

  FOR(i, 0, n - 1)
  {
    s[n - i - 1] -= s[n - i - 2];
  }
  REP(i, n)
  {
    if (i < n - 1)
      cout << s[i] << ' ';
    else
      cout << s[i] << endl;
  }

  return 0;
}
