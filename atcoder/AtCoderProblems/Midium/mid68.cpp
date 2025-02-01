#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

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
constexpr int INF = 1 << 30;

// constexpr int MOD = 1000000000 + 7;
using Graph = vector<vector<int>>;
void bfs(Graph G, int s, vector<int> &dist)
{
    // todo リストを表すキュー
    queue<int> que;

    // 頂点 0 を始点とする
    dist[s] = s;
    que.push(s);

    // キューが空になるまで探索する
    while (!que.empty())
    {
        // キューから頂点を取り出す
        int v = que.front();
        que.pop();

        // 頂点 v から 1 手で行ける頂点 next_v を探索
        for (auto next_v : G[v])
        {
            // 頂点 next_v が探索済みであれば何もしない
            if (dist[next_v] != -1)
            {
                continue;
            }

            // 頂点 next_v を探索する
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (string &s : A)
        cin >> s;
    Graph G(h * w);
    bool flag = true;
    pair<int, int> now = {0, 0}, goal(h - 1, w - 1);
    while (now != goal && flag)
    {
        bool tmp = false;
        pair<int, int> next;
        if (now.first + 1 < h && A[now.first + 1][now.second] == '#')
            tmp ^= true, next = {now.first + 1, now.second};
        if (now.second + 1 < w && A[now.first][now.second + 1] == '#')
            tmp ^= true, next = {now.first, now.second + 1};
        bool tmp2 = false;
        now = next;
        if (now.first > 0 && A[now.first - 1][now.second] == '#')
            tmp2 ^= true;
        if (now.second > 0 && A[now.first][now.second - 1] == '#')
            tmp2 ^= true;
        flag &= (tmp & tmp2);
    }
    if (flag)
        puts("Possible");
    else
        puts("Impossible");
    return 0;
}
