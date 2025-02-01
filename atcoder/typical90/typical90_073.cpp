#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
// using namespace atcoder;
// using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;

constexpr long long MOD = 1000000007;

vector<bool> seen;
using Graph = vvi;
// vector<int> length;

/*
1b
+- 2a
   +- 3b
      +-7a
      +-4a
        +-5b
        +-6b
*/
vector<ll> dfs(const Graph &G, const vi &c, int v)
{
    seen[v] = true;
    vector<ll> dp(3, 0); // dp[k][v] = # of the combination in the case that comp[v] = k;
    // 0: only a
    // 1: only b
    // 2: both a and b
    // cout << v / w << ',' << v % w << '\n';
    dp[c[v]] = 1;
    // cout << v << '\n';
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        auto ret = dfs(G, c, next_v);
        // vの連結成分がa, b両方になるケース
        // 1. vの連結成分がaのみで, 子next_vの連結成分がbのみ, もしくは(a,b)両方のとき: (v, next_v)を選ぶ1通り
        // 2. vの連結成分がbのみで, 子next_vの連結成分がbのみ, もしくは(a,b)両方のとき: (v, next_v)を選ぶ1通り
        // 3. vの連結成分がa,b両方で, 子next_vの連結成分がaのみ, もしくはbのみ: (v, next_v)を選ぶ1通り
        // 4. vの連結成分がa,b両方で, 子next_vの連結成分がa, b両方: (v, next_v)を選ぶ/選ばない2通り
        ll val2 = (dp[0] * (ret[1] + ret[2])) % MOD + (dp[1] * (ret[0] + ret[2])) % MOD + (dp[2] * (ret[0] + ret[1])) % MOD + (2 * dp[2] * ret[2]) % MOD;
        // vの連結成分がaのみになるケース
        // 1. vがaで, 子next_vの連結成分がaのみ: (v, next_v) を選ぶ
        // 2. vがaで, 子next_vの連結成分がab両方: (v, next_v) を選ばない
        if (c[v] == 0)
            dp[0] = (dp[0] * (ret[0] + ret[2])) % MOD;
        else
            dp[1] = (dp[1] * (ret[1] + ret[2])) % MOD;
        dp[2] = val2 % MOD;
    }
    // cout << v << "=(" << dp[0] << "," << dp[1] << "," << dp[2] << ")" << '\n';
    // 帰りがけに要素を追加(探索順に対応するDAGのトポロジカル順序を逆順にしたリストが得られる)
    // seen[v] = false;
    return dp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(n, 0);
    seen.assign(n, false);
    char ci;
    REP(i, n)
    {
        cin >> ci;
        if (ci == 'a')
            c[i] = 0;
        else
            c[i] = 1;
    }
    Graph G(n);
    REP(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<ll> dp = dfs(G, c, 0);
    cout << dp[2] << endl;

    return 0;
}