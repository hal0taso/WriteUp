#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, q;
  int bi;
  vector<int> a;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> q;

  vector<pair<int, int>> p;
  p.resize(q);
  for (int i = 0; i < q; i++)
  {
    cin >> bi;
    p[i] = make_pair(bi, i);
  }
  sort(a.begin(), a.end());
  sort(p.begin(), p.end());
  int idx = 0;
  vector<pair<int, int>> ans(q);
  for (int i = 0; i < q; i++)
  {
    bi = p[i].first;
    int diff = abs(a[idx] - bi);
    while (diff > abs(a[idx + 1] - bi))
    {
      diff = abs(a[idx + 1] - bi);
      idx++;
    }
    ans[i] = make_pair(p[i].second, diff);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < q; i++)
  {
    cout << ans[i].second << endl;
  }

  // cout << "YES" << endl;
  return 0;
}
