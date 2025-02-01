#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

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
  int k;
  cin >> k;
  mint total = 1;
  FOR(i, 0, k + 1)
  total *= (h * w - i);
  mint denom = 0;
  if (k >= 4)
  {
    FOR(i, 3, h + 1)
    {
      FOR(j, 3, w + 1)
      {
        if (k <= (i - 2) * (j - 2) * (i - 2) * (j - 2))
        {
          mint tmp = (i - 2) * (j - 2) * (i - 2) * (j - 2);
          denom += tmp.val();
        }
      }
    }
  }
  return 0;
}
