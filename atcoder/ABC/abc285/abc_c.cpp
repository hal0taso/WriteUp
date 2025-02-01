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
  long long ans = 0;
  for (int i = 0; i < s.size(); i++)
  {
    ans *= 26;
    int x = s[i] - 'A' + 1;
    ans += x;
  }
  cout << ans << endl;
  return 0;
}