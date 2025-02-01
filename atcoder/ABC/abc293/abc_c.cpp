#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 1000000000LL;

void print(vd v)
{
  for (auto vi : v)
  {
    cout << vi << ' ';
  }
  cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
  for (auto vi : v)
  {
    cout << vi.first << ' ';
  }
  cout << '\n';
  for (auto vi : v)
  {
    cout << vi.second << ' ';
  }
  cout << '\n';
}

int main()
{
  int h, w;
  cin >> h >> w;
  vvi A(h, vi(w));
  REP(i, h)
  REP(j, w)
  cin >> A[i][j];
  int ans = 0;
  REP(i, 1 << h + w - 2)
  {
    vb pttn(h + w - 2, false);
    int cnt = 0;
    set<int> s = {A[h - 1][w - 1]};
    bool flg = true;
    REP(j, h + w - 2)
    {
      if ((i >> j) & 1 == 1)
      {
        cnt++;
        pttn[j] = true;
      }
    }
    if (cnt != h - 1)
      continue;
    int x = 0, y = 0;
    REP(j, h + w - 2)
    {
      if (s.find(A[x][y]) != s.end())
      {
        flg = false;
        break;
      }
      else
      {
        s.insert(A[x][y]);
      }
      if (pttn[j])
        x++;
      else
        y++;
    }
    if (flg)
      ans++;
  }
  cout << ans << '\n';
  return 0;
}
