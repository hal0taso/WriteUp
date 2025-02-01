#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

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

using mint = atcoder::modint1000000007;
using Graph = vector<vector<int>>;

const int MAX = 510000;
vector<mint> fac(MAX), finv(MAX), inv(MAX);

// テーブルを作る前処理
void COMinit()
{
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * finv[k] * finv[n - k];
}

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n + 2, 1), c(n + 2, 1);
    Graph G(n + 2); //, RG(n + 2);
    r[n + 1] = h, c[n + 1] = w;
    vector<int> indeg(n + 2, 0);
    // 0: (1, 1),
    // n+1: (h, w)
    FOR(i, 1, n + 1)
    {
        cin >> r[i] >> c[i];
    }
    G[0].push_back(n + 1);
    indeg[n + 1]++;
    FOR(i, 1, n + 1)
    {
        G[0].push_back(i);
        G[i].push_back(n + 1);
        indeg[i]++;
        indeg[n + 1]++;

        FOR(j, 1, n + 1)
        {
            if (i != j && r[i] <= r[j] && c[i] <= c[j])
            {
                G[i].push_back(j);
                indeg[j]++;
            }
        }
    }
    // \binom(l, k) where 1 <= l <= HW, 1 <= k <= HW を前計算
    COMinit();

    // dp[v][k]: 頂点rから頂点vまでに経路内部の点をk回以上通過する経路数
    vector<mint> dp(n + 2, 0);
    dp[0] = -1;
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int next_v : G[v])
        {
            dp[next_v] += -COM(r[next_v] - r[v] + c[next_v] - c[v], r[next_v] - r[v]) * dp[v];
            indeg[next_v]--;
            if (indeg[next_v] == 0)
            {
                que.push(next_v);
            }
        }
    }
    cout << dp[n + 1].val() << '\n';
    return 0;
}