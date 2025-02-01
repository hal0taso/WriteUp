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
    if (i == 0 || i == s.size() - 1)
    {
      if (s[i] - 'A' >= 0 && s[i] - 'A' < 26)
      {
        continue;
      }
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
    else
    {
      if (i == 1)
      {
        if (s[i] - '0' >= 1 && s[i] - '0' < 10)
        {
        }
        else
        {
          cout << "No" << endl;
          return 0;
        }
      }
      if (s[i] - '0' >= 0 && s[i] - '0' < 10)
      {
        cnt++;
      }
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  if (cnt != 6)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}