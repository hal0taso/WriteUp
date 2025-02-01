#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <limits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

using Graph = vector<vector<int>>;
vector<ll> subtree;
vector<ll> Wp;
vector<ll> dist;

ll dfs(const Graph &G, int v, int p, int d)
{
    // 適当に根を固定した木とした時、
    // 各辺が数えられるのは |T[v]| * (|V| - |T[v]|) 回
    // ただし |T[v]| は vを根とする部分木の頂点数
    dist[v] = d;
    ll cnt = 1;
    for (int i = 0; i < (int)G[v].size(); ++i)
    {
        if (G[v][i] == p)
            continue;
        int tmp = dfs(G, G[v][i], v, d + 1);
        cnt += tmp;
    }
    subtree[v] = cnt;
    return cnt;
}

int main()
{
    ll n;
    cin >> n;
    Graph G(n);
    int u, v;
    REP(i, n - 1)
    {
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Wp.resize(n);
    subtree.resize(n);
    dist.resize(n);

    dfs(G, 0, -1, 0);
    ll tmp = 0;
    REP(i, n)
    {
        tmp += dist[i];
    }
    // cout << tmp << endl;
    ll ans = 0;
    REP(i, n)
    {
        ans += subtree[i] * (n - subtree[i]);
    }
    cout << ans << endl;
    return 0;
}