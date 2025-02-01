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
  vector<int> v(30, 0);
  map<int, set<char>> m;
  int lvl = 0;
  REP(i, s.size())
  {
    if (s[i] == '(')
    {
      lvl++;
      m[lvl].clear();
    }
    else if (s[i] == ')')
    {
      for (char c : m[lvl])
      {
        v[c - 'a']--;
      }
      lvl--;
    }
    else
    {
      if (v[s[i] - 'a'] == 0)
      {
        v[s[i] - 'a']++;
        m[lvl].insert(s[i]);
      }
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}
