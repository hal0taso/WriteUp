#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
void debug_out()
{
  cout << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cout << H << " ";
  debug_out(T...);
}

#ifdef LOCAL_DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;
constexpr ll INF = 1000000000000000000LL;

void print(vll v)
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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i, n)
  cin >> a[i];
  sort(all(a));
  vector<ll> ans;
  ans.push_back(0);
  while ((ll)ans.size() <= k)
  {
    ll next = INF;
    ll lb = ans[ans.size() - 1] + 1;
    REP(i, n)
    {
      auto it = lower_bound(all(ans), lb - a[i]);
      if (it != ans.end())
      {
        size_t pos = distance(ans.begin(), it);
        next = min(ans[pos] + a[i], next);
      }
    }

    ans.push_back(next);
  }

  // print(ans);
  cout << ans[k] << endl;
  return 0;
}
