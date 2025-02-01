#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  REP(i, m)
  {
    cin >> a[i];
  }
  stack<int> q;
  int e = 0;
  vector<int> ans;
  FOR(i, 1, n + 1)
  {
    q.push(i);
    if (m > 0 && a[e] == i)
    {
      e++;
      continue;
    }
    else
    {
      while (!q.empty())
      {
        int j = q.top();
        q.pop();
        ans.push_back(j);
      }
    }
  }
  REP(i, n)
  {
    cout << ans[i];
    if (i < n - 1)
      cout << ' ';
    else
      cout << '\n';
  }

  return 0;
}
