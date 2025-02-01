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
  int N;
  cin >> N >> s;
  string ans = "";
  bool n = false;
  for (char c : s)
  {
    if (c == 'n')
      n = true;
    if (n == true && c == 'a')
    {
      ans += 'y';
      ans += c;
      n = false;
    }
    else
    {
      ans += c;
    }
    if (c != 'n')
      n = false;
  }
  cout << ans << endl;

  return 0;
}