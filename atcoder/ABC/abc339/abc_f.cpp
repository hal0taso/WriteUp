#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);
void debug_out()
{
  cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << H << " ";
  debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)
constexpr int MOD = 1000000000 + 7;

string multiplication(string &a, string &b)
{
  int n = a.size();
  int m = b.size();
  vector<int> res(n + m, 0);
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      int x = (a[i] - '0') * (b[j] - '0');
      int p1 = i + j;
      int p2 = i + j + 1;
      int sum = x + res[p2];
      res[p1] += sum / 10;
      res[p2] = sum % 10;
    }
  }
  string ans = "";
  for (int i = 0; i < res.size(); i++)
  {
    if (ans.size() == 0 && res[i] == 0)
      continue;
    ans += to_string(res[i]);
  }
  return ans.size() == 0 ? "0" : ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> a(n);
  int max_size = 0;
  REP(i, n)
  {
    cin >> a[i];
    max_size = max(max_size, (int)a[i].size());
  }
  sort(all(a));
  vector<string> mul;
  REP(i, n)
  {
    REP(j, n)
    {
      if (a[i].size() + a[j].size() + 1 > max_size)
        continue;
      mul.push_back(multiplication(a[i], a[j]));
    }
  }
  int ans = 0;
  sort(all(mul));
  REP(i, mul.size())
  {
    if (mul[i].size() > max_size)
      continue;
  }
}
