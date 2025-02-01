#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

constexpr long long INF = (1LL << 60);

// 辺の情報
struct Edge
{
    // 行先
    int to;

    // コスト
    long long cost;

    Edge(int v_to, long long v_cost)
    {
        to = v_to;
        cost = v_cost;
    }
};

using Graph = std::vector<std::vector<Edge>>;

// { distance, from }
using Pair = std::pair<long long, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph &graph, std::vector<long long> &distances, int startIndex)
{
    // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
    // デフォルトの priority_queue は降順に取り出すため std::greater を使う
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);

    while (!q.empty())
    {
        const long long distance = q.top().first;
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
            const long long d = (distances[from] + edge.cost);

            // d が現在の記録より小さければ更新
            if (d < distances[edge.to])
            {
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    long long c;
    Graph G(n);
    vector<long long> dist_s(n, INF), dist_t(n, INF);
    REP(i, m)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    Dijkstra(G, dist_s, 0);
    Dijkstra(G, dist_t, n - 1);
    REP(k, n)
    {
        cout << dist_s[k] + dist_t[k] << endl;
    }
    return 0;
}