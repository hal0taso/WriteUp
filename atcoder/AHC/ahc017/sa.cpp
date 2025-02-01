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
const long long TIME_LIMIT = 5500LL;
const long long SAMPLE_NUM = 3;
// int TABU_LIST_SIZE = 5;
// vector<int> tabu;
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

void print(set<int> &ans)
{
  for (int e : ans)
  {
    cout << e;
    cout << ' ';
  }
  cout << '\n';
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
using uwGraph = std::vector<std::vector<int>>;

// { distance, from }
using Pair = std::pair<int, int>;

// global variables
// map<pair<int, int>, int> edge2idx; // edge -> index
vector<vector<int>> edge2idx;
// map<int, pair<int, int>> idx2edge; // index -> edge
vector<pair<int, int>> idx2edge;
mt19937_64 get_rand_mt(0); // generate random value (fix seed to 0)
Graph G;
vector<int> seen;
vector<int> rm_eff;
vector<int> ad_eff;

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

void DijkstraTree(const Graph &graph, std::vector<int> &distances, std::vector<int> &parent, int startIndex)
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
      // to までの新しい距離
      const int d = (distances[from] + edge.cost);

      // d が現在の記録より小さければ更新
      if (d < distances[edge.to])
      {
        distances[edge.to] = d;
        q.emplace(d, edge.to);
        parent[edge.to] = from;
      }
    }
  }
}

void DijkstraTree(const Graph &graph, std::vector<int> &distances, std::vector<int> &parent, int startIndex, int k, const vector<vector<int>> &pi)
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
        parent[edge.to] = from;
      }
    }
  }
}

// 状態
struct STATE
{
  int n, m, d, k;
  ll f;
  vector<vector<int>> dist;
  vector<vector<int>> parent;
  vector<int> degree;
  // vector<vector<int>> degreek;
  int maxdeg;
  // vector<vector<vector<long long>>> pi_dist;
  vector<ll> fk;
  // vector<ll> f;
  vector<int> ans; // idx(edge) to day
  vector<int> size_pi;
  map<int, set<int>> ansdict; // ans to set of idx
  vector<vector<int>> pi;
  bool shuffle_flg;
  set<int> sample_set;
  STATE() {}

  STATE(int _n, int _m, int _d, int _k) //, Graph &_G)
  {
    n = _n, m = _m;
    d = _d, k = _k;
    // d = (m + _k - 1) / _k, k = _k;
    // d += 3;
    // if (_d < d)
    // {
    //   d = _d;
    // }
    parent.assign(_n, vector<int>(_n, INF));
    degree.assign(_n, 0);
    ans.resize(_m);
    pi.assign(_n, vector<int>(_n, -1));

    // degreek.assign(_d + 1, vector<int>(_n, 0));
    // G = _G;
    dist.assign(_n, vector<int>(_n, INF));
    size_pi.assign(_d + 1, 0);
    while (sample_set.size() < SAMPLE_NUM)
    {
      int r = rand() % n;

      sample_set.insert(r);
    }
    maxdeg = 0;
    REP(v, _n)
    {
      for (auto edge : G[v])
      {
        degree[v]++;
      }
      maxdeg = max(degree[v], maxdeg);
    }
    // for (int day = 1; day <= _d; day++)
    // {
    //   degreek[day] = degree;
    // }
    // shuffle_flg = false;
    shuffle_flg = d < maxdeg; //(d <= 7 && m <= n * 2);
    f = 0LL;
    for (int v : sample_set)
    {
      DijkstraTree(G, dist[v], parent[v], v);
      REP(u, _n)
      {
        if (u != v)
          f += dist[u][v];
      }
    }
    f /= (SAMPLE_NUM * (n - 1));
    // cout << "[D]" << f << '\n';
    fk.assign(_d + 1, -1LL);
    // fk.assign(_d, -1);
  }
};

// 状態の初期化
void init(STATE &state)
{
  // TODO: ansの初期化, fkの初期化
  int n = state.n, m = state.m, d = state.d;
  // state.fk.assign(d, INF); // とりあえずサイズ決めてINF入れる
  // state.pi_dist.assign(d, vector<vector<ll>>(n, vector<ll>(n, d)));
  // 作戦1. 最短路木から枝が使われる頻度を求めて利用する
  vector<int> used(m, 0);
  REP(v, n)
  {
    FOR(u, v + 1, n)
    {
      int w = state.parent[v][u];
      if (w < INF)
      {
        used[edge2idx[u][w]]++;
      }
    }
  }
  vector<pair<int, int>> order;
  REP(i, m)
  {
    order.emplace_back(used[i], i);
  }
  sort(order.begin(), order.end());
  // // int k;
  int day = 1;
  int cnt = 0;
  if (state.shuffle_flg)
  {
    // 作戦3.ランダムシャッフル
    REP(i, m)
    {
      state.ans[i] = (i + state.d) % state.d + 1;
    }
    shuffle(state.ans.begin(), state.ans.end(), get_rand_mt);
    REP(i, m)
    {
      // とりあえず均等に割り振り
      pair<int, int> p = idx2edge[i];
      int ans = state.ans[i];
      state.size_pi[ans]++;
      state.pi[p.first][p.second] = ans;
      state.pi[p.second][p.first] = ans;
      state.ansdict[ans].insert(i);
    }
  }
  else
  { // 辺彩色してみる?
    REP(i, m)
    {
      // 作戦1-1. あまり使ってない枝を最初に工事
      if (cnt == (state.m + state.d - 1) / state.d)
        day++, cnt = 0;
      state.ans[order[i].second] = day;
      cnt++;
      // 作戦2 - 2. 使われる頻度別に均等に割り振り
      // day = i % d + 1;
      // state.ans[order[i].second] = day;

      pair<int, int> p = idx2edge[order[i].second];
      state.size_pi[day]++;
      state.pi[p.first][p.second] = day;
      state.pi[p.second][p.first] = day;
      state.ansdict[day].insert(order[i].second);
    }
  }
  // 一度サンプル使って計算してみる
  // set<int> sample_set;
  // while (sample_set.size() < SAMPLE_NUM)
  // {
  //   int r = rand() % n;

  //   sample_set.insert(r);
  // }
  // puts("[D] Compute Initial Score");

  FOR(day, 1, d + 1)
  {
    vector<vector<int>> dist;
    dist.assign(n, vector<int>(n, INF));
    // REP(v, n)
    state.fk[day] = 0;
    for (int v : state.sample_set)
    {
      Dijkstra(G, dist[v], v, day, state.pi);
      REP(u, n)
      {
        if (u != v)
          state.fk[day] += dist[v][u]; // - state.dist[u][v]);
      }
    }
    state.fk[day] = state.fk[day] / (SAMPLE_NUM * (n - 1)) - state.f;
  }
}

long long modify(STATE &state, STATE &new_state, int shiftsize, bool &is_move)
{
  // cout << "[D] Exchange " << shiftsize << " edges\n";
  int n = new_state.n, d = new_state.d, m = new_state.m;

  // long long Stime, Etime;
  // Stime = getTime();

  int d1 = 0, d2 = 0;
  // 不満度が高い日と低い日で入れ替え
  if (state.shuffle_flg)
  {
    // ランダムシャッフル
    // int d1 = (d - 1 + iternum) % d + 1, d2 = (d - 2 + iternum) % d + 1;

    // 入れ替える日付を選択
    while (d1 == d2)
    {
      d1 = rand() % d + 1;
      d2 = rand() % d + 1;
    }
  }
  else
  {
    priority_queue<pair<ll, int>> que1;
    priority_queue<pair<ll, int>> que2;
    FOR(day, 1, d + 1)
    {
      que1.push({-state.fk[day], day}); // 平均パス長が小さい日
      que2.push({state.fk[day], day});  // 平均パス長が大きい日
    }
    pair<ll, int> p1, p2;
    p1 = que1.top();
    que1.pop();
    p2 = que2.top();
    que2.pop();
    d1 = p1.second, d2 = p2.second;
    // while ((step >= tabu[d1] && step >= tabu[d2]) || d1 == d2)
    // {
    //   p1 = que1.top();
    //   que1.pop();
    //   p2 = que2.top();
    //   que2.pop();
    //   d1 = p1.second, d2 = p2.second;
    // }
    // tabu[d1] += TABU_LIST_SIZE;
    // tabu[d2] += TABU_LIST_SIZE;
  }
  // tabu.insert(d1);
  // tabu.insert(d2);
  // その日の工事辺の数を調べる
  set<int> s1 = state.ansdict[d1];
  set<int> s2 = state.ansdict[d2];
  if (is_move)
  { // day2 -> day1に移動
    shiftsize = min(shiftsize, state.size_pi[d2] / 2);
    shiftsize = min(shiftsize, state.k - state.size_pi[d1]);
    // cout << shiftsize << endl;
  }
  else
  { // day1, day2 で入れ替え
    if (state.size_pi[d1] < shiftsize || state.size_pi[d2] < shiftsize)
      shiftsize = min(state.size_pi[d1], state.size_pi[d2]) / 2;
  }
  if (shiftsize <= 0)
  {
    is_move = false;
    // cout << "Return 0" << endl;
    return 0LL;
  }
  vector<int> o1, o2;
  // 既に計算しているので、もう一度Dijkstraする必要はない
  // vector<int> parent;
  // set<int> pool;
  // vector<vector<int>> dist;
  // int idx = 0;
  // for (int day : {d1, d2})
  // {
  //   vector<int> used(m, 0);
  //   if (state.fk[day] >= 0)
  //     continue;
  //   vector<int> parent;
  //   set<int> pool;
  //   int is_removed = 0;
  //   dist.assign(n, vector<int>(n, INF));
  //   parent.assign(n, INF); // for dijkstra tree
  //   // Stime = getTime();
  //   ll fk = 0;
  //   // REP(v, n)
  //   for (int v : state.sample_set)
  //   {
  //     // if (v != r)
  //     //   continue;
  //     DijkstraTree(G, dist[v], parent, v, day, state.pi);
  //     REP(u, n)
  //     {
  //       if (u != v)
  //         fk += dist[v][u];
  //     }
  //   }
  //   state.fk[day] = (fk / (SAMPLE_NUM * (n - 1)) - state.f);
  //   // Etime = getTime();
  //   // cout << "[D] Compute Original f_k: " << Etime - Stime << "msec. \n";
  // }
  if (state.shuffle_flg)
  {
    vector<int> deg1(n, 0);
    vector<int> deg2(n, 0);
    priority_queue<pair<int, int>> q1;
    priority_queue<pair<int, int>> q2;
    if (!is_move)
      for (int i1 : s1)
      {
        pair<int, int> e1 = idx2edge[i1];
        deg1[e1.first]++;
        deg1[e1.second]++;
      }
    if (!is_move)
      for (int i1 : s1)
      {
        pair<int, int> e1 = idx2edge[i1];
        q1.emplace(deg1[e1.first] - state.degree[e1.first] + deg1[e1.second] - state.degree[e1.second], i1);
      }
    for (int i2 : s2)
    {
      pair<int, int> e2 = idx2edge[i2];
      deg2[e2.first]++;
      deg2[e2.second]++;
    }
    for (int i2 : s2)
    {
      pair<int, int> e2 = idx2edge[i2];
      q2.emplace(deg2[e2.first] - state.degree[e2.first] + deg2[e2.second] - state.degree[e2.second], i2);
    }
    if (!is_move)
      while (o1.size() < shiftsize && !q1.empty())
      {
        int i = q1.top().second;
        int deg = q1.top().first;
        q1.pop();
        pair<int, int> e = idx2edge[i];
        int curr_deg = deg1[e.first] - state.degree[e.first] + deg1[e.second] - state.degree[e.second];
        if (find(o1.begin(), o1.end(), i) == o1.end() && curr_deg == deg && state.degree[e.first] - deg2[e.first] > 0 && state.degree[e.second] - deg2[e.second] > 0)
        {
          o1.push_back(i);
          deg1[e.first]--;
          deg1[e.second]--;
        }
      }
    while (o2.size() < shiftsize && !q2.empty())
    {
      int i = q2.top().second;
      int deg = q2.top().first;
      q2.pop();
      pair<int, int> e = idx2edge[i];
      int curr_deg = deg2[e.first] - state.degree[e.first] + deg2[e.second] - state.degree[e.second];
      if (find(o2.begin(), o2.end(), i) == o2.end() && curr_deg == deg && state.degree[e.first] - deg1[e.first] > 0 && state.degree[e.second] - deg1[e.second] > 0)
      {
        o2.push_back(i);
        deg2[e.first]--;
        deg2[e.second]--;
      }
    }
    // 作戦1. その日に工事する枝の集合から shiftsize個だけランダムサンプル
    // sample(s1.begin(), s1.end(), back_inserter(o1), shiftsize, get_rand_mt);
    // sample(s2.begin(), s2.end(), back_inserter(o2), shiftsize, get_rand_mt);
  }
  else
  {
    // 作戦1. その日に工事する枝の集合から shiftsize個だけランダムサンプル
    if (!is_move)
      sample(s1.begin(), s1.end(), back_inserter(o1), shiftsize, get_rand_mt);
    sample(s2.begin(), s2.end(), back_inserter(o2), shiftsize, get_rand_mt);
  }
  // Etime = getTime();
  // cout << "[D] Random Sampling: " << Etime - Stime << "msec. \n";
  // print(o1);
  // print(o2);

  // 作戦2. お互いにあまり使ってない枝を入れ替える
  // shiftsize = min(cnt1, shiftsize);
  // shiftsize = min(cnt2, shiftsize);
  // REP(i, shiftsize)
  // {
  //   auto [q1, i1] = que1.top();
  //   auto [q2, i2] = que2.top();
  //   que1.pop(), que2.pop();
  //   o1.push_back(i1);
  //   o2.push_back(i2);
  // }
  // puts("[D]");
  // vector debug = {d1, d2};
  // print(debug);
  // print(o1);
  // print(o2);
  // 入れ替え前のd1, d2のスコアを計算
  // Stime = getTime();
  // vector<vector<int>> dist;
  // for (int day : {d1, d2})
  // {
  //   if (state.fk[day] >= 0)
  //     continue;
  //   dist.assign(n, vector<int>(n, INF));
  //   REP(v, n)
  //   {
  //     Dijkstra(G, dist[v], v, day, state.pi);
  //   }
  //   ll fk = 0;
  //   FOR(u, 0, n)
  //   {
  //     FOR(v, u + 1, n)
  //     {
  //       fk += dist[u][v];
  //     }
  //   }
  //   state.fk[day] = fk - state.f;
  // }
  // Etime = getTime();
  // cout << "[D] Compute Original f_k: " << Etime - Stime << "msec. \n";

  // vector debug = {i1, i2, new_state.ans[i1], new_state.ans[i2]};
  // i1 = rand() % s1.size();
  // i2 = rand() % s2.size();

  // 枝の工事日を入れ替え (ans と pi を交換)
  // Stime = getTime();
  if (is_move)
  {
    // 辺の移動
    // print(o2);
    for (int i = 0; i < shiftsize; i++)
    {
      // int i1 = o1[i];
      int i2 = o2[i];
      // pair<int, int> e1 = idx2edge[i1];
      pair<int, int> e2 = idx2edge[i2];

      // new_state.ansdict[d1].erase(i1);
      new_state.ansdict[d1].insert(i2);
      new_state.size_pi[d1]++;

      new_state.ansdict[d2].erase(i2);
      new_state.size_pi[d2]--;
      // new_state.ansdict[d2].insert(i1);
      // swap
      new_state.ans[i2] = d1;
      // new_state.pi[e1.first][e1.second] = d2, new_state.pi[e1.second][e1.first] = d2;
      new_state.pi[e2.first][e2.second] = d1, new_state.pi[e2.second][e2.first] = d1;
    }
  }
  else
  {
    // 交換
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
  }

  // Etime = getTime();
  // cout << "[D] Switch Assignment: " << Etime - Stime << "msec. \n";

  // 取り替えた日だけ更新すれば良い
  // if (new_state.ans[i1] == new_state.ans[i2])
  //   return 0;
  // Stime = getTime();
  long long ret = 0;
  vector<vector<int>> dist;
  for (int day : {d1, d2})
  {
    ll fk = 0;

    dist.assign(n, vector<int>(n, INF));
    // new_state.fk[day] = 0;
    // 最短路木の枝を使っている頂点だけ更新（一方しか計算されないので）
    // cout << "[D] Start Compute New f_k: " << pool.size() << " vertices. \n";
    // Stime = getTime();
    // for (int v : pool)
    for (int v : new_state.sample_set)
    {
      Dijkstra(G, dist[v], v, day, new_state.pi);
      REP(u, n)
      {
        if (u != v)
          fk += dist[v][u];
      }
    }
    // cout << "[D] new fk for day " << day << ": " << (fk / (n * (n - 1)) - new_state.f) * 2.0 << '\n';

    // new_state.fk[day] = fk[1] - new_state.f;
    new_state.fk[day] = (fk / (SAMPLE_NUM * (n - 1)) - new_state.f);
    // Etime = getTime();
    // cout << "[D] Compute New f_k and Evaluate the diff: " << Etime - Stime << "msec. \n";
    ret -= (new_state.fk[day] - state.fk[day]);
  }

  return ret;
}

// 状態のスコア計算
ll calc_score(STATE &state)
{
  ll ret = 0;
  for (auto val : state.fk)
    ret -= val;
  // print(state.fk);
  return ret;
}

// 焼きなまし法
void sa()
{
  long long Stime, Etime;
  // ll step = 0;
  Stime = getTime();
  // 入力
  int n, m, d, k;
  cin >> n >> m >> d >> k;
  // TABU_LIST_SIZE = min(TABU_LIST_SIZE, d / 2);
  int u, v;
  int w;
  G.resize(n);
  // tabu.assign(d + 1, 0);
  // Graph G(n);
  edge2idx.assign(n, vector<int>(n, -1));
  idx2edge.resize(m);
  // Etime = getTime();
  // cout << "[D] Start input: " << Etime - Stime << "msec. \n";

  REP(i, m)
  {
    cin >> u >> v >> w;
    u--;
    v--;
    edge2idx[u][v] = i;
    edge2idx[v][u] = i;
    idx2edge[i] = {u, v};
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  // Etime = getTime();
  // cout << "[D] Read input: " << Etime - Stime << "msec. \n";
  // 状態のインスタンス作成 (全点対最短経路を計算)
  // SAMPLE_NUM = 10;
  STATE state(n, m, d, k);
  // Etime = getTime();
  // cout << "[D] Instantiate state: " << Etime - Stime << "msec. \n";

  // 初期解探索
  init(state);
  // return;
  // print(state.ans);
  // Etime = getTime();
  // cout << "[D] Init state: " << Etime - Stime << "msec. \n";
  // int cnt = 0;
  long long start_temp = 1e9 * SAMPLE_NUM / (SAMPLE_NUM * (n - 1)), end_temp = 1LL; // 適当な値を入れる（後述）
                                                                                    // cout << start_temp << endl;
                                                                                    // long long start_time = getTime();                         // 開始時刻
  // int modify_edges = min(((m + d - 1) / d), k) / 2;
  // int modify_edges = k / 2;
  bool is_move = true;
  while (true)
  {                                 // 時間の許す限り回す
    long long now_time = getTime(); // 現在時刻
    if (now_time - Stime > TIME_LIMIT)
      break;

    STATE new_state = state;
    // Etime = getTime();
    // cout << "[D] Backup state: " << Etime - Stime << "msec. \n";
    int modify_edges = min(((m + d - 1) / d), k) / 2 + (10 - min(((m + d - 1) / d), k) / 2) * (now_time - Stime) / TIME_LIMIT;
    // int modify_edges = k / 2 + (end_temp - k / 2) * (now_time - Stime) / TIME_LIMIT;
    if (modify_edges < 5)
      modify_edges = 5;
    // modify_edges = rand() % modify_edges + 1;
    // if (modify_edges < 5)
    //   modify_edges = 5;
    long long diff_score = modify(state, new_state, modify_edges, is_move);
    // cnt++;
    // Etime = getTime();
    // cout << "[D] Modify state: " << modify_edges << ":" << Etime - Stime << "msec. \n";
    // int new_score = calc_score(new_state);
    // int pre_score = calc_score(state);
    // Etime = getTime();
    // cout << "[D] Calc score: " << Etime - Stime << "msec. \n";

    // 温度関数
    long long temp = start_temp + (end_temp - start_temp) * (now_time - Stime) / TIME_LIMIT;
    // cout << temp << '\n';
    // 遷移確率関数(最大化の場合)
    // double prob = exp((new_score - pre_score) / temp);
    double prob = exp((diff_score) / max(temp, 1LL));
    double threshold = (rand() % INF) / (double)INF;
    // cout << "[D] diff_score = " << diff_score << '\n';
    // cout << "[D] prob: " << prob << ", threshold: " << threshold << "\n";
    if (prob > threshold)
    { // 確率probで遷移する
      state = new_state;
    }
    // int score = calc_score(state);
    if ((d <= 7 && m <= n * 2) && (now_time - Stime) / (double)TIME_LIMIT >= 0.5)
    {
      state.shuffle_flg = !state.shuffle_flg;
      // modify_edges = modify_edges * 0.9;
    }
    if ((rand() % INF) / (double)INF > 0.7)
    {
      is_move = !is_move;
      state.shuffle_flg = true;
    }
    else if ((rand() % INF) / (double)INF > 0.7)
    {
      state.shuffle_flg = !state.shuffle_flg;
    }
    // step++;

    // Etime = getTime();
    // cout << "[D] state.shuffle_flg: " << (state.shuffle_flg ? "true" : "false") << "\n";
    // cout << "[D] Calc score: " << score << ":" << Etime - Stime << "msec. \n";

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
