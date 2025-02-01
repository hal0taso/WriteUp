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
  int cnt = 0;
  REP(i, s.size())
  {
    if (s[i] == '0')
    {
      if (i < s.size() && s[i + 1] == '0')
      {
        i++;
      }
    }
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}