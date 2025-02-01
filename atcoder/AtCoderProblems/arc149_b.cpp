#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
const int INF = 1 << 30;

int LIS(const vector<int> &A)
{
  // dp[i] := 長さ i+1 の部分増加列の末尾としてありうる最小値
  vector<int> dp;
  for (auto &&x : A)
  {
    int i = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
    if (i >= int(dp.size()))
    {
      dp.emplace_back(x);
    }
    else
    {
      dp[i] = x;
    }
  }
  return dp.size();
}

int main()
{
  int n;
  vector<int> a, b;
  vector<pair<int, int>> p;
  cin >> n;
  a.resize(n);
  b.resize(n);
  p.resize(n);
  REP(i, n)
  {
    cin >> a[i];
  }
  REP(i, n)
  {
    cin >> b[i];
  }
  REP(i, n)
  {
    p[i] = make_pair(a[i], b[i]);
  }
  sort(p.begin(), p.end());
  REP(i, n)
  {
    b[i] = p[i].second;
  }
  cout << n + LIS(b) << endl;

  return 0;
}
