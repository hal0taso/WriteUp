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

int main()
{

  int n = 8;
  string s;
  cin >> s;
  vector<int> x;
  vector<int> y;
  int z;
  int cnt = 0;
  int dnt = 0;
  int qnt = 0;
  int knt = 0;
  int nnt = 0;
  REP(i, n)
  {
    if (s[i] == 'B')
      x.push_back(i), cnt++;
    if (s[i] == 'R')
      y.push_back(i), dnt++;
    if (s[i] == 'K')
      z = i, knt++;
    if (s[i] == 'Q')
      qnt++;
    if (s[i] == 'N')
      nnt++;
  }
  if (knt == 1 && qnt == 1 && cnt == 2 && dnt == 2 && nnt == 2)
  {
    if (x[0] % 2 != x[1] % 2)
      if (y[0] < z && z < y[1])
      {
        puts("Yes");
        return 0;
      }
  }
  puts("No");

  return 0;
}
