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

bool test(int S, int c, vector<int>&a, int r, int k){
  int cnt = 0;
  REP(i, c){
    if((S >> a[i]) & 1)
      cnt++;
  }
  if(cnt >= k && r == 0){
    return true;
  }else if (cnt < k && r == 1){
    return true;
  }else {
    return false;
  }
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A;
  vector<int> C(m), R(m);
  REP(i, m){
    cin >> C[i];
    vector<int> a(C[i]);
    REP(j, C[i]){
      cin >> a[j];
      a[j]--;
    }
    A.push_back(a);
    string r;
    cin >> r;
    if (r == "o")
      R[i] = 0;
    else if(r == "x"){
      R[i] = 1;
    }
  }
  int ans = 0;
  REP(S, 1 << n){
    int tmp = 1;
    for (int i = 0; i < m; i++)
      if (!test(S, C[i], A[i], R[i], k)){
        tmp = 0;
        break;
      }
    if (tmp == 0)
      continue;

    ans += tmp;
  }
  cout << ans << endl;
}
