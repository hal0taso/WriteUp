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

bool gakkari(vector<vector<int>> &c, vector<int> &order)
{
  vector<set<int>> col(3);
  vector<set<int>> row(3);
  vector<set<int>> naname(2);
  vector<int> cn(3, 0);
  vector<int> rn(3, 0);
  vector<int> nn(2, 0);
  REP(i, 9)
  {
    int x = order[i] / 3;
    int y = order[i] % 3;
    int e = c[x][y];
    cn[x]++;
    rn[y]++;
    if (cn[x] == 2 && col[x].find(e) != col[x].end())
    {

      return true;
    }
    col[x].insert(e);
    if (rn[y] == 2 && row[y].find(e) != row[y].end())
    {
      return true;
    }
    row[y].insert(e);
    if (x == y)
    {
      nn[0]++;
      if (nn[0] == 2 && naname[0].find(e) != naname[0].end())
      {
        return true;
      }
      naname[0].insert(e);
    }
    if (x + y == 2)
    {
      nn[1]++;
      if (nn[1] == 2 && naname[1].find(e) != naname[1].end())
      {
        return true;
      }
      naname[1].insert(e);
    }
  }
  return false;
}

int main()
{
  vector c(3, vector(3, 0));
  REP(i, 3)
  {
    REP(j, 3)
    {
      cin >> c[i][j];
    }
  }
  int a = 1;
  FOR(i, 1, 10)
  {
    a *= i;
  }
  int b = 0;

  vector<int> order;
  REP(i, 9)
  {
    order.push_back(i);
  }

  do
  {
    if (!gakkari(c, order))
      b++;
  } while (next_permutation(all(order)));
  std::cout << std::fixed;
  std::cout << std::setprecision(10);

  cout << (double)b / (double)a << '\n';

  return 0;
}