#include <bits/stdc++.h>
using namespace std;

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
constexpr long long INF = 1000000000000LL;

using Graph = vvi;

vector<int> dist;

void dfs(Graph &G, Graph &F, int v)
{
    if (dist[v] >= 0)
    {
        return;
    }
    if (F[v].size() == 0)
    {
        dist[v] = 0;
        return;
    }
    int tmp = 0;
    for (int prev_v : F[v])
    {
        dfs(G, F, prev_v);
        tmp = max(tmp, dist[prev_v]);
    }
    tmp++;
    dist[v] = tmp;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n), F(n);
    vector<int> outdeg(n, 0);
    dist.assign(n, -1);
    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        F[v].push_back(u);
        outdeg[u]++;
    }
    REP(v, n)
    {
        if (outdeg[v] == 0)
        {
            dfs(G, F, v);
        }
    }
    int ans = 0;
    REP(v, n)
    {
        ans = max(dist[v], ans);
    }
    cout << ans << '\n';

    return 0;
}