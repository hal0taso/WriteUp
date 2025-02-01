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

// adjacency list of a directed graph
using Graph = std::vector<std::vector<int>>;
vector<bool> seen;
vector<int> black, white;

void dfs(const Graph &G, int v, bool color)
{
    if (color)
        black.push_back(v);
    else
        white.push_back(v);
    seen[v] = true;
    for (auto next_v : G[v])
    {
        if (!seen[next_v])
            dfs(G, next_v, !color);
    }
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    Graph G(n);
    REP(i, n - 1)
    {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(n, false);
    dfs(G, 0, true);
    if (black.size() >= n / 2)
    {
        REP(i, n / 2 - 1)
        cout << black[i] + 1 << ' ';

        cout << black[n / 2 - 1] + 1 << '\n';
    }
    else
    {
        REP(i, n / 2 - 1)
        cout << white[i] + 1 << ' ';

        cout << white[n / 2 - 1] + 1 << '\n';
    }
    return 0;
}