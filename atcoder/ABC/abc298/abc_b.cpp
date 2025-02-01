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
constexpr ll INF = 1000000000LL;

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

bool f(vector<vector<int>> &a, vector<vector<int>> &b)
{
  int n = a.size();
  REP(i, n)
  REP(j, n)
  {
    if (a[i][j] == 1 && a[i][j] != b[i][j])
    {
      return false;
    }
  }
  return true;
}

vector<vector<int>> r(vector<vector<int>> &a)
{
  int n = a.size();
  vector<vector<int>> res(n, vector<int>(n));
  REP(i, n)
  REP(j, n)
  {
    res[i][j] = a[n - j - 1][i];
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector a(n, vector<int>(n)), b(n, vector<int>(n));
  REP(i, n)
  REP(j, n)
  cin >> a[i][j];
  REP(i, n)
  REP(j, n)
  cin >> b[i][j];
  REP(i, 4)
  {
    bool ret = f(a, b);
    if (ret)
    {
      puts("Yes");
      return 0;
    }
    a = r(a);
  }
  puts("No");
  return 0;
}
