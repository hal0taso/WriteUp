#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  long long n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  long long ans = 5e12;
  for (int i = 0; i <= n; i++)
  {
    long long tmp = a * i;
    int l = 0, r = n - 1;

    while (l < r)
    {
      // cout << "(i, l, r, s[l], s[r]) = (" << i << ',' << l << ',' << r << ',' << s[l] << ',' << s[r] << ")\n";
      if (s[l] != s[r])
        tmp += b;
      l++, r--;
    }
    ans = min(ans, tmp);
    s = s.substr(1, n - 1) + s[0];
  }
  cout << ans << endl;
  return 0;
}