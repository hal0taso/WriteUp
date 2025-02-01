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

using Graph = vector<vector<int>>;

void dfs(Graph &G, int v, vector<bool> &seen, vector<vector<mint>> &comb)
{
    seen[v] = true;
    for (int next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(G, next_v, seen, comb);
        // black: 1
        // white: 0`
        comb[0][v] *= (comb[0][next_v] + comb[1][next_v]);
        comb[1][v] *= (comb[0][next_v]);
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    REP(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<bool> seen(n, false);
    vector comb(2, vector<mint>(n, 1));
    dfs(G, 0, seen, comb);
    cout << (comb[0][0] + comb[1][0]).val() << '\n';

    return 0;
}