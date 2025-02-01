#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvd = vector<vector<double>>;
using vd = vector<double>;
using vvvb = vector<vector<vector<bool>>>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;

void print(vd v)
{
    for (auto vi : v)
    {
        cout << vi << ' ';
    }
    cout << '\n';
}

void print(vd v, int n)
{
    REP(i, n)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void print(vector<pair<ll, ll>> v)
{
    for (auto vi : v)
    {
        cout << vi.first << ' ';
    }
    cout << '\n';
    for (auto vi : v)
    {
        cout << vi.second << ' ';
    }
    cout << '\n';
}

vector<bool> seen;
using Graph = vvi;
vector<int> length;

void dfs(const Graph &G, int v, int r, int depth, int w)
{
    seen[v] = true;
    // cout << v / w << ',' << v % w << '\n';
    depth++;
    for (auto next_v : G[v])
    {
        if (next_v == r && length[r] < depth && depth >= 3)
            length[r] = depth;
        if (!seen[next_v])
            dfs(G, next_v, r, depth, w);
    }
    // 帰りがけに要素を追加(探索順に対応するDAGのトポロジカル順序を逆順にしたリストが得られる)
    seen[v] = false;
}
int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> C(h);
    REP(i, h)
    cin >> C[i];
    Graph G(h * w);
    length.assign(h * w, -1);
    REP(i, h)
    {
        REP(j, w)
        {
            int u = i * w + j;
            if (C[i][j] == '.')
            {
                for (int dx : {-1, 1})
                {
                    int v = (i + dx) * w + j;
                    if (i + dx >= 0 && i + dx < h)
                        if (C[i + dx][j] == '.')
                        {
                            G[u].push_back(v);
                        }
                }
                for (int dy : {-1, 1})
                {
                    int v = i * w + j + dy;
                    if (j + dy >= 0 && j + dy < w)
                    {
                        if (C[i][j + dy] == '.')
                        {
                            G[u].push_back(v);
                        }
                    }
                }
            }
        }
    }
    REP(i, h)
    REP(j, w)
    {
        // puts("D");
        int depth = 0;
        int r = i * w + j;
        seen.assign(h * w, false);
        dfs(G, r, r, depth, w);
    }
    int ans = -1;
    for (int tmp : length)
    {
        ans = max(ans, tmp);
    }
    cout << ans << '\n';

    return 0;
}