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
/*
ll pow(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}
*/

vector<vector<mint>> mul(vector<vector<mint>> &a, vector<vector<mint>> &b)
{
    int n = a.size();
    vector ret(n, vector<mint>(n, 0));
    REP(i, n)
    {
        REP(j, n)
        {
            REP(k, n)
            ret[i][j] += a[i][k] * b[k][j];
        }
    }
    return ret;
}
vector<vector<mint>> pow(vector<vector<mint>> &a, ll k)
{
    int n = a.size();
    vector res(n, vector<mint>(n, 0));
    REP(i, n)
    res[i][i] = 1;
    for (; k; k >>= 1)
    {
        if (k & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
    }
    return res;
}
int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector a(n, vector<mint>(n));
    int ai;
    REP(i, n)
    REP(j, n)
    {
        cin >> ai;
        a[i][j] = ai;
    }
    vector<vector<mint>> ret = pow(a, k);
    mint ans = 0;
    REP(i, n)
    REP(j, n)
    ans += ret[i][j];
    cout << ans.val() << '\n';
    return 0;
}