#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

constexpr int INF = (1LL << 30);

// directed edge
struct Edge
{
    // head of edge
    int to;

    // weight
    int cost;

    Edge(int v_to, int v_cost)
    {
        to = v_to;
        cost = v_cost;
    }
};

// adjacency list of a directed graph
using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<int, int>;

// Dijkstra algorithm
// Running time: O((V+E)log(V))
// cf. https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/dijkstra
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph &graph, std::vector<int> &distances, int startIndex)
{
    // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
    // デフォルトの priority_queue は降順に取り出すため std::greater を使う
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);

    while (!q.empty())
    {
        const int distance = q.top().first;
        const int from = q.top().second;
        q.pop();

        // 最短距離でなければ処理しない
        if (distances[from] < distance)
        {
            continue;
        }

        // 現在の頂点からの各辺について
        for (const auto &edge : graph[from])
        {
            // to までの新しい距離
            const int d = (distances[from] + edge.cost);

            // d が現在の記録より小さければ更新
            if (d < distances[edge.to])
            {
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int to_d1(int x, int y, int h, int w)
{
    return x * w + y;
}

pair<int, int> to_d2(int v, int h, int w)
{
    return {v / w, v % w};
}

int main()
{
    int H, W;
    cin >> H >> W;
    int N = H * W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vector<string> S(H);
    REP(i, H)
    {
        cin >> S[i];
    }
    int s = to_d1(rs, cs, H, W);
    int t = to_d1(rt, ct, H, W);
    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(4 * N);
    vector<int> dist_s(4 * N, INF);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int u, v;
            u = to_d1(i, j, H, W);
            for (int k1 = 0; k1 < 4; k1++)
            {
                for (int k2 = 0; k2 < 4; k2++)
                {
                    if (u == s || u == t)
                        G[4 * u + k1].emplace_back(4 * u + k2, 0);
                    else
                        G[4 * u + k1].emplace_back(4 * u + k2, 1);
                }
            }
            if (i < H - 1)
            {
                if (S[i][j] == '.' && S[i + 1][j] == '.')
                {
                    v = to_d1(i + 1, j, H, W);
                    G[4 * u].emplace_back(4 * v, 0);
                    G[4 * v + 1].emplace_back(4 * u + 1, 0);
                }
            }
            if (j < W - 1)
            {
                if (S[i][j] == '.' && S[i][j + 1] == '.')
                {
                    v = to_d1(i, j + 1, H, W);
                    G[4 * u + 2].emplace_back(4 * v + 2, 0);
                    G[4 * v + 3].emplace_back(4 * u + 3, 0);
                }
            }
        }
    }
    Dijkstra(G, dist_s, 4 * s);
    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    cout << dist_s[4 * t] << endl;
    return 0;
}