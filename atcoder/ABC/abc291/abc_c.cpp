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
  pair<int, int> p = {0, 0};
  set<pair<int, int>> S;
  S.insert(p);
  REP(i, n)
  {
    if (s[i] == 'R')
    {
      p.first++;
    }
    else if (s[i] == 'L')
    {
      p.first--;
    }
    else if (s[i] == 'U')
    {
      p.second++;
    }
    else
    {
      p.second--;
    }
    if (S.find(p) != S.end())
    {
      puts("Yes");
      return 0;
    }
    S.insert(p);
  }
  puts("No");
  return 0;
}
