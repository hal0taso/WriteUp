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

constexpr int MOD = 1000000000 + 7;

pair<int, int> solve(int n, int l, int k, int lb, int ub, vector<int> &a)
{
  int m = a[l];
  // cerr << m << "|" << l << "=" << k << '\n';
  // cerr << m << "|lb:" << lb << '\n';
  // cerr << m << "|ub:" << ub << '\n';
  pair<int, int> ret;
  if (l == n - 1)
  {
    ret = {0, 0};
    return ret;
  }
  vector<int> small, large;
  FOR(i, l + 1, n)
  if (a[i] < m)
    small.push_back(a[i]);
  else
    large.push_back(a[i]);
  // cerr << m << "|"
  //      << "small:" << small.size() << ", large:" << large.size() << '\n';
  sort(all(small));
  sort(all(large));
  reverse(all(large));
  if (k - lb < (int)small.size())
  {
    int r;
    for (r = l + 1; r < n; r++)
      if (a[r] == small[k - lb])
        break;
    ret = {l, r};
  }
  else if (ub - k < (int)large.size())
  {
    // cerr << k << '\n';
    // in the case that k > 0 && k <= large.size()
    int r;
    for (r = l + 1; r < n; r++)
      if (a[r] == large[ub - k])
        break;
    ret = {l, r};
  }
  else
  {
    ret = solve(n, l + 1, k, lb + small.size(), ub - large.size(), a);
  }
  return ret;
}

int main()
{
  int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> A(N);
  for (auto &x : A)
    cin >> x;
  int lb = 1, ub = N * (N + 1) / 2;
  auto ans = solve(N, 0, K, lb, ub, A);
  // while (!S.empty())
  // {
  //   int s = 0;
  //   int tmp = *S.begin();
  //   auto it = lower_bound(a.begin() + s, a.end(), tmp);
  //   int pos = distance(a.begin(), it);
  //   while (pos != s && k > 0)
  //   {
  //     k--;
  //     S.erase(tmp);
  //     tmp = *S.begin();
  //     it = lower_bound(a.begin() + s, a.end(), tmp);
  //     pos = distance(a.begin(), it);
  //   }
  //   if (k > (n - s) * (n - s + 1) / 2)
  //   {
  //     S.erase(tmp);
  //     tmp = *S.begin();
  //     k -= (n - s) * (n - s + 1) / 2;
  //   }
  //   else
  //   {
  //     s++;
  //   }

  //   do
  //   {

  //     S.erase(tmp);
  //     tmp = *S.begin();
  //     it = lower_bound(a.begin() + s, a.end(), tmp);
  //     pos = distance(a.begin(), it);
  //   } while (pos != s && k > 0);
  // }
  /* REP(l, n)
  {
    FOR(r, l, n)
    {
      cerr << "DEBUG: " << l << "," << r << '\n';
      REP(i, n)
      {
        if (i > r || i < l)
          cerr << a[i] << ' ';
        else
          cerr << a[r - (i - l)] << ' ';
      }
      cerr << '\n';
    }
  } */
  REP(i, N)
  {
    if (i > ans.second || i < ans.first)
      cout << A[i];
    else
      cout << A[ans.second - (i - ans.first)];
    if (i < N - 1)
      cout << ' ';
    else
      cout << "\n";
  }
  return 0;
}