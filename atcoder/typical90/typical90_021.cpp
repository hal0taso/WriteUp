#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

// Library to detect Strong Connected Components
// cf. https://manabitimes.jp/math/1250
// cf. https://pione.hatenablog.com/entry/2021/03/11/232159

// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;
vector<int> order, component;
vector<bool> seen;

void dfs(const Graph &G, int v)
{
    seen[v] = true;
    for (auto next_v : G[v])
    {
        if (!seen[next_v])
            dfs(G, next_v);
    }
    // 帰りがけに要素を追加(探索順に対応するDAGのトポロジカル順序を逆順にしたリストが得られる)
    order.push_back(v);
}
void rdfs(const Graph &rG, int v, int k)
{
    component[v] = k;
    for (auto next_v : rG[v])
    {
        if (component[next_v] < 0)
        {
            rdfs(rG, next_v, k);
        }
    }
}

int scc(const Graph &g)
{
    int n = g.size();
    Graph rg(n);
    component.assign(n, -1);
    seen.assign(n, false);
    int last_ptr = 0;
    REP(v, n)
    {
        for (auto nv : g[v])
            rg[nv].push_back(v);
    }
    REP(v, n)
    {
        if (!seen[v])
            dfs(g, v);
    }
    int k = 0;
    reverse(order.begin(), order.end());
    for (auto v : order)
        if (component[v] < 0)
            rdfs(rg, v, k), k++;
    return k;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    int a, b;
    set<pair<int, int>> s;
    REP(i, m)
    {
        cin >> a >> b;
        a--;
        b--;
        if (s.find({a, b}) == s.end())
            g[a].push_back(b);
        s.insert({a, b});
    }
    int k;
    k = scc(g);
    long long ans = 0;
    vector<ll> c_size(k, 0);
    REP(v, n)
    c_size[component[v]]++;
    REP(i, k)
    {
        ans += (c_size[i] * (c_size[i] - 1) / 2);
    }
    cout << ans << endl;
    return 0;
}