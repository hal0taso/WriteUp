#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

// constant value
constexpr long long INF = 1000000000LL;
const long long TIME_LIMIT = 4000;

// utility functions, structs, etc...
long long getTime()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  long long result = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
  // cerr << result << endl;
  return result;
}

void print(vector<ll> &ans)
{
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i];
    if (i < ans.size() - 1)
      cout << ' ';
    else
      cout << '\n';
  }
}

void print(vector<int> &ans)
{
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i];
    if (i < ans.size() - 1)
      cout << ' ';
    else
      cout << '\n';
  }
}

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

// global variables
map<pair<int, int>, int> edge2idx; // edge -> index
map<int, pair<int, int>> idx2edge; // index -> edge
mt19937_64 get_rand_mt(0);         // generate random value (fix seed to 0)
Graph G;

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

void Dijkstra(const Graph &graph, std::vector<int> &distances, int startIndex, int k, const vector<vector<int>> &pi)
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
      // k日目に工事中なら処理しない
      if (pi[from][edge.to] == k)
      {
        continue;
      }
      // to までの新しい距離
      const int d = (distances[from] + edge.cost);

      // d が現在の記録より小さければ更新
      if (d < distances[edge.to])
      {
        distances[edge.to] = d;
        q.emplace(d, edge.to);
      }
    }
  }
}

// void Dijkstra(const Graph &graph, std::vector<int> &distances, int startIndex, int k, const vector<int> &ans)
// {
//   // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
//   // デフォルトの priority_queue は降順に取り出すため std::greater を使う
//   std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
//   q.emplace((distances[startIndex] = 0), startIndex);

//   while (!q.empty())
//   {
//     const int distance = q.top().first;
//     const int from = q.top().second;
//     q.pop();

//     // 最短距離でなければ処理しない
//     if (distances[from] < distance)
//     {
//       continue;
//     }

//     // 現在の頂点からの各辺について
//     for (const auto &edge : graph[from])
//     {
//       // k日目に工事中なら処理しない
//       if (ans[edge2idx[{from, edge.to}]] == k)
//       {
//         continue;
//       }
//       // to までの新しい距離
//       const int d = (distances[from] + edge.cost);

//       // d が現在の記録より小さければ更新
//       if (d < distances[edge.to])
//       {
//         distances[edge.to] = d;
//         q.emplace(d, edge.to);
//       }
//     }
//   }
// }

// 状態
struct STATE
{
  int n, m, d, k;
  // ll f;
  // vector<vector<vector<long long>>> pi_dist;
  vector<ll> fk;
  // vector<ll> f;
  vector<int> ans;            // idx(edge) to day
  map<int, set<int>> ansdict; // ans to set of idx
  vector<vector<int>> pi;
  STATE() {}

  STATE(int _n, int _m, int _d, int _k) //, Graph &_G)
  {
    n = _n, m = _m, d = _d, k = _k;
    // G = _G;
    vector<vector<int>> dist;
    dist.assign(_n, vector<int>(_n, INF));

    // REP(v, _n)
    // {
    //   Dijkstra(G, dist[v], v);
    // }
    // f = 0LL;
    // FOR(u, 0, _n)
    // {
    //   FOR(v, u + 1, _n)
    //   {
    //     f += dist[u][v];
    //   }
    // }
    fk.assign(_d + 1, -1LL);
    // fk.assign(_d, -1);
  }
};

// 状態の初期化
void init(STATE &state)
{
  // TODO: ansの初期化, fkの初期化
  int n = state.n, m = state.m, d = state.d;
  state.ans.resize(m);
  // state.fk.assign(d, INF); // とりあえずサイズ決めてINF入れる
  state.pi.assign(n, vector<int>(n, -1));
  // state.pi_dist.assign(d, vector<vector<ll>>(n, vector<ll>(n, d)));

  // int k;
  REP(i, m)
  {
    // とりあえず均等に割り振り
    state.ans[i] = (i % d) + 1;
  }
  // ランダムシャッフル
  shuffle(state.ans.begin(), state.ans.end(), get_rand_mt);
  REP(i, m)
  {
    // とりあえず均等に割り振り
    pair<int, int> p = idx2edge[i];
    int ans = state.ans[i];
    state.pi[p.first][p.second] = ans;
    state.pi[p.second][p.first] = ans;
    state.ansdict[ans].insert(i);
  }
  // REP(_k, d)
  // {
  //   vector<vector<long long>> dist;
  //   dist.assign(n, vector<ll>(n, INF));
  //   REP(v, n)
  //   {
  //     Dijkstra(state.G, dist[v], v, _k + 1, state.pi);
  //   }
  //   FOR(u, 0, n)
  //   {
  //     FOR(v, u + 1, n)
  //     {
  //       state.fk[_k] += (dist[u][v] - state.dist[u][v]);
  //     }
  //   }
  // }
}

// 状態遷移
// int modify(STATE &state)
// {
//   // ランダムシャッフル
//   int i1, i2;
//   int d1 = 0, d2 = 0;
//   while (d1 == d2)
//   {
//     d1 = rand() % state.d;
//     d2 = rand() % state.d;
//   }
//   i1 = rand() % state.m;
//   i2 = rand() % state.m;
//   // 枝の入れ替え
//   pair<int, int> e1 = idx2edge[i1];
//   pair<int, int> e2 = idx2edge[i2];
//   // vector debug = {i1, i2, state.ans[i1], state.ans[i2]};
//   swap(state.ans[i1], state.ans[i2]);
//   swap(state.pi[e1.first][e1.second], state.pi[e2.first][e2.second]);
//   swap(state.pi[e1.second][e1.first], state.pi[e2.second][e2.first]);

//   int n = state.n, d = state.d;
//   // 取り替えた日だけ更新すれば良い
//   if (state.ans[i1] == state.ans[i2])
//     return 0;
//   for (int day : {state.ans[i1], state.ans[i2]})
//   {
//     vector<vector<long long>> dist;
//     dist.assign(n, vector<ll>(n, INF));
//     REP(v, n)
//     {
//       Dijkstra(G, dist[v], v, day, state.pi);
//     }
//     ll fk = 0;
//     FOR(u, 0, n)
//     {
//       FOR(v, u + 1, n)
//       {
//         fk += dist[u][v];
//       }
//     }
//     state.fk[day] = fk;
//   }
//   return 0;
// }

long long modify(STATE &state, STATE &new_state, int shiftsize)
{
  int n = new_state.n, d = new_state.d;

  // ランダムシャッフル
  int d1 = 0, d2 = 0;
  // 入れ替える日付を選択
  while (d1 == d2)
  {
    d1 = rand() % d + 1;
    d2 = rand() % d + 1;
  }
  // その日に工事する枝の集合から shiftsize個だけランダムサンプル
  set<int> s1 = new_state.ansdict[d1];
  set<int> s2 = new_state.ansdict[d2];
  if (s1.size() < shiftsize || s2.size() < shiftsize)
    shiftsize = min(s1.size(), s2.size());
  if (shiftsize == 0)
    return 0;

  vector<int> o1, o2;
  sample(s1.begin(), s1.end(), back_inserter(o1), shiftsize, get_rand_mt);
  sample(s2.begin(), s2.end(), back_inserter(o2), shiftsize, get_rand_mt);
  // puts("[D]");
  // vector debug = {d1, d2};
  // print(debug);
  // print(o1);
  // print(o2);
  // 入れ替え前のd1, d2のスコアを計算
  vector<vector<int>> dist;
  for (int day : {d1, d2})
  {
    if (state.fk[day] >= 0)
      continue;
    dist.assign(n, vector<int>(n, INF));
    REP(v, n)
    {
      Dijkstra(G, dist[v], v, day, state.pi);
    }
    ll fk = 0;
    FOR(u, 0, n)
    {
      FOR(v, u + 1, n)
      {
        fk += dist[u][v];
      }
    }
    // state.fk[day] = fk - state.f;
    state.fk[day] = fk;
  }

  // vector debug = {i1, i2, new_state.ans[i1], new_state.ans[i2]};
  // i1 = rand() % s1.size();
  // i2 = rand() % s2.size();

  // 枝の工事日を入れ替え (ans と pi を交換)
  for (int i = 0; i < shiftsize; i++)
  {
    int i1 = o1[i], i2 = o2[i];
    pair<int, int> e1 = idx2edge[i1];
    pair<int, int> e2 = idx2edge[i2];

    new_state.ansdict[d1].erase(i1);
    new_state.ansdict[d1].insert(i2);

    new_state.ansdict[d2].erase(i2);
    new_state.ansdict[d2].insert(i1);
    // swap
    new_state.ans[i1] = d2, new_state.ans[i2] = d1;
    new_state.pi[e1.first][e1.second] = d2, new_state.pi[e1.second][e1.first] = d2;
    new_state.pi[e2.first][e2.second] = d1, new_state.pi[e2.second][e2.first] = d1;
  }
  // 取り替えた日だけ更新すれば良い
  // if (new_state.ans[i1] == new_state.ans[i2])
  //   return 0;
  long long ret = 0;
  for (int day : {d1, d2})
  {
    vector<vector<int>> dist;
    dist.assign(n, vector<int>(n, INF));
    REP(v, n)
    {
      Dijkstra(G, dist[v], v, day, new_state.pi);
    }
    ll fk = 0;
    FOR(u, 0, n)
    {
      FOR(v, u + 1, n)
      {
        fk += dist[u][v];
      }
    }
    // new_state.fk[day] = fk - new_state.f;
    new_state.fk[day] = fk;
    // 最小化なので、スコアの差分はマイナスつけておく
    ret -= (new_state.fk[day] - state.fk[day]);
  }
  return ret;
}

// 状態のスコア計算
ll calc_score(STATE &state)
{
  ll ret = 0;
  for (auto val : state.fk)
    if (val >= 0)
      ret -= val;
  return ret;
}

// 焼きなまし法
void sa()
{
  long long Stime, Etime;
  Stime = getTime();
  // 入力
  int n, m, d, k;
  cin >> n >> m >> d >> k;
  int u, v;
  int w;
  G.resize(n);
  // Graph G(n);
  REP(i, m)
  {
    cin >> u >> v >> w;
    u--;
    v--;
    edge2idx[{u, v}] = i;
    edge2idx[{v, u}] = i;
    idx2edge[i] = {u, v};
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  // Etime = getTime();
  // cout << "[D] Read input: " << Etime - Stime << "msec. \n";
  // 状態のインスタンス作成 (全点対最短経路を計算)
  STATE state(n, m, d, k);
  // Etime = getTime();
  // cout << "[D] Instantiate state: " << Etime - Stime << "msec. \n";

  // 初期解探索
  init(state);
  // print(state.ans);
  // Etime = getTime();
  // cout << "[D] Init state: " << Etime - Stime << "msec. \n";

  long long start_temp = 1e9 / (n * (n - 1)), end_temp = 0; // 適当な値を入れる（後述）
  long long start_time = getTime();                         // 開始時刻
  while (true)
  {                                 // 時間の許す限り回す
    long long now_time = getTime(); // 現在時刻
    if (now_time - Stime > TIME_LIMIT)
      break;

    STATE new_state = state;
    // Etime = getTime();
    // cout << "[D] Backup state: " << Etime - Stime << "msec. \n";
    long long diff_score = modify(state, new_state, (m / d) / 2);
    // Etime = getTime();
    // cout << "[D] Modify state: " << Etime - Stime << "msec. \n";
    // int new_score = calc_score(new_state);
    // int pre_score = calc_score(state);
    // Etime = getTime();
    // cout << "[D] Calc score: " << Etime - Stime << "msec. \n";

    // 温度関数
    long long temp = start_temp + (end_temp - start_temp) * (now_time - start_time) / TIME_LIMIT;
    // 遷移確率関数(最大化の場合)
    // double prob = exp((new_score - pre_score) / temp);
    double prob = exp((diff_score) / temp);

    if (prob > (rand() % INF) / (double)INF)
    { // 確率probで遷移する
      state = new_state;
    }
    // print(state.ans);

    // Etime = getTime();
    // cout << "[D] End iteration: " << Etime - Stime << "msec. \n";
  }
  // 出力処理
  print(state.ans);
}

int main()
{
  // long long Stime, Etime;
  // Stime = getTime();
  sa();
  // Etime = getTime();
  // cout << "[D] SA: " << Etime - Stime << "msec. \n";

  return 0;
}
