#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>
#include <sys/time.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using namespace std;

void debug_out()
{
    cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << H << " ";
    debug_out(T...);
}

#define debug(...) debug_out(__VA_ARGS__)

// 遅延伝搬SegmentTree
template <typename _T>
class LazySegmentTree
{
    using F = std::function<_T(_T, _T)>;

private:
    int n;
    int size;
    int height;

public:
    _T IdentityNode; // 値データの単位元
    _T IdentityLazy; // 遅延データの単位元

    F CombineNodeFunc; // 値データの作用
    F CombineLazyFunc; // 遅延データの伝搬作用
    F ReflectFunc;     // 遅延データを値データにどう反映させるか
    std::vector<_T> node;
    std::vector<_T> lazy;

    LazySegmentTree(int _n, const _T &identityNode, const _T &identityLazy,
                    const F &combineNodeFunc, const F &combineLazyFunc,
                    const F &reflectFunc)
    {
        n = _n;
        size = 1;
        height = 0;
        while (size < n)
            size <<= 1, height++;
        IdentityNode = identityNode;
        IdentityLazy = identityLazy;
        CombineNodeFunc = combineNodeFunc;
        CombineLazyFunc = combineLazyFunc;
        ReflectFunc = reflectFunc;
        node = std::vector<_T>(2 * size, IdentityNode);
        lazy = std::vector<_T>(2 * size, IdentityLazy);
    }

private:
    _T reflect_lazy(int index)
    {
        return ReflectFunc(node[index], lazy[index]);
    }

    void propergate_from_top(int index)
    {
        index += size;
        for (int h = height; h > 0; h--)
        {
            int i = index >> h;
            if (lazy[i] != IdentityLazy)
            {
                lazy[i << 1 | 0] = CombineLazyFunc(lazy[i << 1 | 0], lazy[i]);
                lazy[i << 1 | 1] = CombineLazyFunc(lazy[i << 1 | 1], lazy[i]);
                node[i] = reflect_lazy(i);
                lazy[i] = IdentityLazy;
            }
        }
    }

    void update_from_bottom(int index)
    {
        index = (index + size) >> 1;
        while (index > 0)
        {
            node[index] = CombineNodeFunc(reflect_lazy(index << 1 | 0), reflect_lazy(index << 1 | 1));
            index >>= 1;
        }
    }

public:
    void build(std::vector<_T> array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            node[i + n] = array[i];
        }
        for (size_t i = n - 1; i > 0; i--)
        {
            size_t l = i << 1 | 0;
            size_t r = i << 1 | 1;
            node[i] = CombineNodeFunc(node[l], node[r]);
        }
    }

    void update(int l, int r, _T value)
    {
        propergate_from_top(l);
        propergate_from_top(r - 1);
        int l_lazy = l + size;
        int r_lazy = r + size;
        while (l_lazy < r_lazy)
        {
            if (l_lazy & 1)
            {
                lazy[l_lazy] = CombineLazyFunc(lazy[l_lazy], value);
                l_lazy++;
            }
            if (r_lazy & 1)
            {
                r_lazy--;
                lazy[r_lazy] = CombineLazyFunc(lazy[r_lazy], value);
            }
            l_lazy >>= 1;
            r_lazy >>= 1;
        }
        update_from_bottom(l);
        update_from_bottom(r - 1);
    }

    void update(int index, _T value)
    {
        update(index, index + 1, value);
    }

    _T fold(int l, int r)
    {
        propergate_from_top(l);
        propergate_from_top(r - 1);
        l += size;
        r += size;
        _T value_l = IdentityNode;
        _T value_r = IdentityNode;
        while (l < r)
        {
            if (l & 1)
            {
                value_l = CombineNodeFunc(value_l, reflect_lazy(l));
                l++;
            }
            if (r & 1)
            {
                r--;
                value_r = CombineNodeFunc(reflect_lazy(r), value_r);
            }
            l >>= 1;
            r >>= 1;
        }
        return CombineNodeFunc(value_l, value_r);
    }
};

// using node = std::pair<int, int>;
struct node
{
    int x;
    int y;
    node(int _x, int _y)
    {
        x = _x;
        y = _y;
    };

    bool operator<(const node &other)
    {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator>(const node &other)
    {
        return x > other.x || (x == other.x && y > other.y);
    }

    bool operator==(const node &other)
    {
        return x == other.x && y == other.y;
    }
};

struct crop
{
    int k;
    int s;
    int d;
    int value;
    crop(int _k, int _x, int _y)
    {
        k = _k;
        s = _x;
        d = _y;
        value = d - s + 1;
    };

    bool operator<(const crop &other)
    {
        return value < other.value;
    }

    bool operator>(const crop &other)
    {
        return value > other.value;
    }

    bool operator==(const crop &other)
    {
        return value == other.value;
    }
};

ll getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ll result = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
    // cerr << result << endl;
    return result;
}

int T, K, H, W, i0;
vector<int> S, D;
vector<crop> Crop;
const double TIME_LIMIT = 1900;
const int INF = 1e6;

vector<vector<bool>> h, v;
// vector<vector<bool>> used; // 使用中

bool operator<(const node &node1, const node &node2)
{
    return node1.x < node2.x || (node1.x == node2.x && node1.y < node2.y);
}

using Graph = std::vector<std::vector<std::vector<node>>>; // node = {i, j}, G[i][j] = {i1, j1};
using Schedule = vector<vector<LazySegmentTree<int>>>;

void bfs(Graph G, node s, vector<vector<int>> &dist, Graph &BFSTree)
{
    // todo リストを表すキュー
    int time = 0;

    priority_queue<pair<pair<int, int>, node>> que; // {{dist, time}, node}
                                                    // queue<node> que;

    // 頂点 0 を始点とする
    dist[s.x][s.y] = 0;
    que.push({{0, time}, s});

    // キューが空になるまで探索する
    while (!que.empty())
    {
        // キューから頂点を取り出す
        // node v = que.front();
        auto [_, v] = que.top();
        time++;
        que.pop();

        // 頂点 v から 1 手で行ける頂点 next_v を探索
        for (auto next_v : G[v.x][v.y])
        {
            // 頂点 next_v が探索済みであれば何もしない
            if (dist[next_v.x][next_v.y] != -1)
            {
                continue;
            }

            // 頂点 next_v を探索する
            dist[next_v.x][next_v.y] = dist[v.x][v.y] + 1;
            BFSTree[v.x][v.y].push_back(next_v);
            BFSTree[next_v.x][next_v.y].push_back(v);
            que.push({{-dist[next_v.x][next_v.y], time}, next_v});
        }
    }
}

void read_input()
{
    cin >> T >> H >> W >> i0;
    h.resize(H - 1, vector(W, false));
    for (int i = 0; i < H - 1; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j)
            if (s[j] == '1')
                h[i][j] = true;
    }
    v.resize(H, vector(W - 1, false));
    for (int i = 0; i < H; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W - 1; ++j)
            if (s[j] == '1')
                v[i][j] = true;
    }
    cin >> K;
    S.resize(K);
    D.resize(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> S[i] >> D[i];
        Crop.push_back(crop(i, S[i], D[i]));
    }

    // used.resize(H, vector(W, false));
}

struct Work
{
    int k, i, j, s;
};

struct STATE
{
    Graph G;
    vector<vector<bool>> used;
    int score;
    STATE(const Graph &_G)
    {
        G = _G;
        used = vector(H, vector(W, false));
        score = 0;
    }
    STATE(){};

    bool reachable()
    {
        vector<vector<int>> dist = vector(H, vector(W, -1));
        queue<node> que;
        node s(i0, 0);
        dist[i0][0] = 0;
        que.push(s);
        while (!que.empty())
        {
            // キューから頂点を取り出す
            node v = que.front();
            que.pop();
            if (used[v.x][v.y])
                continue;
            // 頂点 v から 1 手で行ける頂点 next_v を探索
            for (auto next_v : G[v.x][v.y])
            {
                // 頂点 next_v が探索済みであれば何もしない
                if (dist[next_v.x][next_v.y] != -1)
                {
                    continue;
                }
                dist[next_v.x][next_v.y] = dist[v.x][v.y] + 1;
                que.push(next_v);
            }
        }
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                if (dist[i][j] < 0)
                    return false;
            }
        }
        return true;
    }

    void chg(int i, int j)
    {
        used[i][j] = !used[i][j];
        if (used[i][j])
            score--;
        else
            score++;
    }
    void use(int i, int j)
    {
        used[i][j] = true;
        score++;
    }
    void rm(int i, int j)
    {
        used[i][j] = false;
        score--;
    }
};

bool reachable(int i, int j, const Graph &adj, const vector<vector<bool>> &used)
{
    if (used[i][j] || used[i0][0])
    {
        return false;
    }
    else if (i == i0 && j == 0)
    {
        return true;
    }
    queue<pair<int, int>> q;
    q.emplace(i0, 0);
    vector visited(H, vector(W, false));
    visited[i0][0] = true;
    while (!q.empty())
    {
        const auto [i1, j1] = q.front();
        q.pop();
        for (const auto &[i2, j2] : adj[i1][j1])
        {
            if (i2 == i && j2 == j)
            {
                return true;
            }
            else if (!used[i2][j2] && !visited[i2][j2])
            {
                visited[i2][j2] = true;
                q.emplace(i2, j2);
            }
        }
    }

    return false;
}

bool is_valid_plan(const vector<Work> &plan, const Graph &adj)
{
    vector<vector<Work>> plant_list(T + 1), harvest_list(T + 1);
    for (const Work &w : plan)
    {
        plant_list[w.s].push_back(w);
        harvest_list[D[w.k]].push_back(w);
    }

    vector used(H, vector(W, false));
    for (int t = 1; t <= T; ++t)
    {
        // planting phase
        for (const Work &w : plant_list[t])
        {
            if (!reachable(w.i, w.j, adj, used))
            {
                return false;
            }
        }
        for (const Work &w : plant_list[t])
        {
            if (used[w.i][w.j])
            {
                return false;
            }
            else
            {
                used[w.i][w.j] = true;
            }
        }

        // harvesting phase
        for (const Work &w : harvest_list[t])
        {
            used[w.i][w.j] = false;
        }
        for (const Work &w : harvest_list[t])
        {
            if (!reachable(w.i, w.j, adj, used))
            {
                return false;
            }
        }
    }

    return true;
}

// 状態遷移
void modify(STATE &state)
{
    for (int k = 0; k < H; k++)
    {
        int i = rand() % H;
        int j = rand() % W;
        state.chg(i, j);
        if (!state.reachable())
            state.chg(i, j);
    }
}

void init(STATE &state)
{
    debug("Run BFS");
    Graph BFSTree(H, vector(W, vector<node>()));
    node s(i0, 0);
    vector<vector<int>> dist(H, vector(W, -1));
    bfs(state.G, s, dist, BFSTree);

    debug("Compute degree");
    vector<vector<int>> deg(H, vector(W, 0));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            deg[i][j] = BFSTree[i][j].size();
        }
    }

    debug("Get leaf nodes");
    vector<node> que; // que[1]: available, que[1]: unavailable
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (deg[i][j] == 1)
                state.use(i, j);

    debug("# of Leaf:", state.score);
}

void sa(const Graph &G, vector<node> &ret)
{
    STATE state(G);
    // puts("INIT");
    init(state);
    int init_score = state.score;
    double start_temp = H * W, end_temp = 1; // 適当な値を入れる（後述）
    double start_time = getTime();           // 開始時刻
    int cnt = 0;
    debug("[", cnt, "]START=", start_time);
    int best_score = init_score;
    STATE best_state = state;

    while (true)
    {
        cnt++;                       // 時間の許す限り回す
        double now_time = getTime(); // 現在時刻
        if (now_time - start_time > TIME_LIMIT)
            break;

        STATE new_state = state;
        modify(new_state);
        int new_score = new_state.score;
        int pre_score = state.score;

        // 温度関数
        double temp = start_temp + (end_temp - start_temp) * (now_time - start_time) / TIME_LIMIT;
        // 遷移確率関数(最大化の場合)
        double prob = exp((new_score - pre_score) / temp);
        debug("[", cnt, "]NOW=", now_time, ", SCORE=", new_score);

        if (prob > (rand() % INF) / (double)INF)
        { // 確率probで遷移する
            state = new_state;
        }
        if (new_score > best_score)
        {
            best_state = new_state;
        }
    }

    debug("OUTPUT RESULT");
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (best_state.used[i][j])
                ret.push_back(node(i, j));
    debug("END SA");
}

int main()
{
    debug("Read input");
    read_input();

    // construct a graph
    debug("Construct a graph");
    Graph G(H, vector(W, vector<node>()));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (i + 1 < H && !h[i][j])
            {
                // no waterway between (i, j) and (i + 1, j)
                G[i][j].emplace_back(i + 1, j);
                G[i + 1][j].emplace_back(i, j);
            }
            if (j + 1 < W && !v[i][j])
            {
                // no waterway between (i, j) and (i, j + 1)
                G[i][j].emplace_back(i, j + 1);
                G[i][j + 1].emplace_back(i, j);
            }
        }
    }
    // int _n, const T &identityNode, const T &identityLazy,
    //                 const F &combineNodeFunc, const F &combineLazyFunc,
    //                 const F &reflectFunc
    // debug("Run BFS");
    // Graph BFSTree(H, vector(W, vector<node>()));
    // node s(i0, 0);
    // vector<vector<int>> dist(H, vector(W, -1));
    // bfs(G, s, dist, BFSTree);

    // debug("Compute degree");
    // vector<vector<int>> deg(H, vector(W, 0));
    // for (int i = 0; i < H; ++i)
    // {
    //     for (int j = 0; j < W; ++j)
    //     {
    //         deg[i][j] = BFSTree[i][j].size();
    //         // debug("deg:", i, j, "=", deg[i][j]);
    //         // debug("dist:", i, j, "=", dist[i][j]);
    //     }
    // }

    // debug("Get leaf nodes");
    // vector<node> que; // que[1]: available, que[1]: unavailable
    // for (int i = 0; i < H; ++i)
    //     for (int j = 0; j < W; ++j)
    //         if (deg[i][j] == 1)
    //             que.emplace_back(i, j);
    // debug("# of Leaf:", que.size());

    vector<node> que;
    sa(G, que);

    debug("Create Schedule");
    std::function<int(int, int)> func = [](int l, int r)
    { return std::max(l, r); };
    Schedule Sch = vector(H, vector(W, LazySegmentTree<int>(T, 0, 0, func, func, func)));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            Sch[i][j].build(vector<int>(T, 0));

    debug("Assign crops to leafs");
    sort(Crop.begin(), Crop.end());
    reverse(Crop.begin(), Crop.end());
    vector<Work> plan;
    for (int k = 0; k < K; ++k)
    {
        bool found = false;
        for (node v : que)
        {
            if (found)
                break;
            if (Sch[v.x][v.y].fold(Crop[k].s, Crop[k].d + 1) == 0)
            {
                found = true;
                plan.push_back({Crop[k].k, v.x, v.y, Crop[k].s});
                Sch[v.x][v.y].update(Crop[k].s, Crop[k].d + 1, 1);
            }
        }
    }

    // write output
    cout << plan.size() << '\n';
    for (const Work &w : plan)
    {
        cout << w.k + 1 << ' ' << w.i << ' ' << w.j << ' ' << w.s << '\n';
    }
}
