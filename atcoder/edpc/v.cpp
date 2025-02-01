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
ll m;

/* Rerooting: 全方位木 DP
    問題ごとに以下を書き換える
    - 型DPと単位元
    - 型DPに対する二項演算 merge
    - まとめたDPを用いて新たな部分木のDPを計算する add_root
    計算量: O(N)
*/
struct Rerooting
{
    /* start 問題ごとに書き換え */
    struct DP
    { // DP の型
        long long dp;
        DP(long long dp_) : dp(dp_) {}
    };
    const DP identity = 1LL; // DP(-1); // 単位元(末端の値は add_root(identity) になるので注意)
    function<DP(DP, DP)> merge = [](DP dp_cum, DP d) -> DP
    {
        return DP(dp_cum.dp * d.dp % m);
    };
    function<DP(DP)> add_root = [](DP d) -> DP
    {
        return DP((d.dp + 1 + m) % m);
    };
    /* end 問題ごとに書き換え */
    // グラフの定義
    struct Edge
    {
        int to;
    };
    using Graph = vector<vector<Edge>>;
    vector<vector<DP>> dp; // dp[v][i]: vから出るi番目の有向辺に対応する部分木のDP
    vector<DP> ans;        // ans[v]: 頂点vを根とする木の答え
    Graph G;
    Rerooting(int N) : G(N)
    {
        dp.resize(N);
        ans.assign(N, identity);
    }
    void add_edge(int a, int b)
    {
        G[a].push_back({b});
    }
    void build()
    {
        dfs(0);           // 普通に木DP
        bfs(0, identity); // 残りの部分木に対応するDPを計算
    }
    DP dfs(int v, int p = -1)
    { // 頂点v, 親p
        DP dp_cum = identity;
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, identity);
        for (int i = 0; i < deg; i++)
        {
            int u = G[v][i].to;
            if (u == p)
                continue;
            dp[v][i] = dfs(u, v);
            dp_cum = merge(dp_cum, dp[v][i]);
        }
        return add_root(dp_cum);
    }
    void bfs(int v, const DP &dp_p, int p = -1)
    { // bfs だが、実装が楽なので中身は dfs になっている
        int deg = G[v].size();
        for (int i = 0; i < deg; i++)
        { // 前のbfsで計算した有向辺に対応する部分木のDPを保存
            if (G[v][i].to == p)
                dp[v][i] = dp_p;
        }
        vector<DP> dp_l(deg + 1, identity), dp_r(deg + 1, identity); // 累積merge
        for (int i = 0; i < deg; i++)
        {
            dp_l[i + 1] = merge(dp_l[i], dp[v][i]);
        }
        for (int i = deg - 1; i >= 0; i--)
        {
            dp_r[i] = merge(dp_r[i + 1], dp[v][i]);
        }
        ans[v] = add_root(dp_l[deg]); // 頂点 v の答え
        for (int i = 0; i < deg; i++)
        { // 一つ隣の頂点に対しても同様に計算
            int u = G[v][i].to;
            if (u == p)
                continue;
            bfs(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};
int main()
{
    int n;
    cin >> n >> m;
    Rerooting reroot(n);
    REP(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        reroot.add_edge(u, v);
        reroot.add_edge(v, u);
    }
    reroot.build();
    REP(i, n)
    {
        cout << (reroot.ans[i].dp - 1 + m) % m << '\n';
    }
    return 0;
}