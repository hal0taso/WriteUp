#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;
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

using mint = modint998244353;
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
  int q;
  cin >> q;
  mint s = 1;
  deque<int> deq;
  deq.push_back(1);
  mint n = 1;
  REP(i, q)
  {
    int op, x;
    cin >> op;
    if (op == 1)
    {
      cin >> x;
      s *= 10;
      s += x;
      deq.push_back(x);
      n *= 10;
    }
    if (op == 2)
    {
      mint h = deq.front();
      deq.pop_front();
      s -= h * n.val();
      n /= 10;
    }
    if (op == 3)
    {
      cout << s.val() << '\n';
    }
  }
  return 0;
}
