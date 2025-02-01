#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int N, M;
vector<vector<int>> A;
vector<vector<int>> tmpA;
vector<vector<int>> origA;
vector<int> global_used;
int THR = 6;
int S_THR = 5;
struct UnionFind
{
  std::vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  map<int, int> _size;
  map<int, int> _op_cost;
  int _n;
  UnionFind(int N) : par(N)
  { // 最初は全てが根であるとして初期化
    _n = N;
    for (int i = 0; i <= N; i++)
    {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int root(int x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) // x を y にマージ
  {                        // xとyの木を併合
    int rx = root(x);      // xの根をrx
    int ry = root(y);      // yの根をry
    int sx = size(x);
    int sy = size(y);
    if (rx == ry)
      return;     // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    _size[ry] = sx + sy;
  }
  bool same(int x, int y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  int size(int x)
  {
    int rx = root(x);
    return _size[rx];
  }
};

int cell(int i, int j)
{
  return i * N + j + 1;
}

bool is_valid_move(int i, int j)
{
  if (i < 0 || i >= N || j < 0 || j >= N)
    return false;
  return true;
}

void update_nearest(int i, int j, UnionFind &uf, int target)
{
  int u, v;
  // puts("called");
  for (int d : {-1, 1})
  {
    if (is_valid_move(i + d, j))
    {
      v = cell(i, j);
      u = cell(i + d, j);
      if (A[i][j] == target && A[i + d][j] == target)
      {
        if (uf.root(u) != uf.root(v))
        {
          uf.unite(u, v);
        }
      }
    }
    if (is_valid_move(i, j + d))
    {
      u = cell(i, j + d);
      v = cell(i, j);
      if (A[i][j] == target && A[i][j + d] == target)
      {
        if (uf.root(u) != uf.root(v))
        {
          uf.unite(u, v);
        }
      }
    }
  }
}

void solve(int target, int thr, int &m, vector<int> &ans, vector<int> &ans2)
{

  REP(i, N)
  {
    REP(j, N)
    {
      A[i][j] = tmpA[i][j];
    }
  }
  priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> cost; // 育成する必要がある頂点(サイズ, 手数, 隣接点, 自点)
  vector<vector<pair<int, int>>> cand;                                                                                   // 育てる操作
  vector<tuple<int, int, int>> cost_value;                                                                               // 最終的にナップザック解くならcost:valueでいいけど、単にいいやつ取るだけならvalue - costと頂点のペアで良い？（最後に復元するのにコストは欲しい）
  vector<int> used;

  cand.resize(N * N + 1);
  cost_value.assign(N * N + 1, {0, 0, 0});
  used.assign(N * N + 1, false);
  int cnt = 0;
  // UF構築
  UnionFind uf(N * N + 1);
  REP(i, N)
  {
    REP(j, N)
    {
      // cout << "DEBUG UF" << endl;
      update_nearest(i, j, uf, target);
    }
  }

  // 初期探索
  REP(i, N)
  {
    REP(j, N)
    {
      // cout << "DEBUG UF" << endl;
      int v = cell(i, j);
      int rv = uf.root(v); // 収穫の操作は連結集合のrootだけにしたい
      if (A[i][j] == target)
      {
        if (!used[rv] && uf.size(v) >= target + S_THR)
        {
          // // もう収穫できる
          used[rv] = true;
          cost_value[rv] = {target * uf.size(rv), -1, rv};
        }
        else if (!used[rv] && uf.size(rv) < target)
        {
          // まだ収穫できない. サイズが大きいものから処理してもらう
          for (int d : {-1, 1})
          {
            if (is_valid_move(i + d, j))
            {
              if (A[i + d][j] < target)
              {
                // 必要コストと頂点を追加
                cost.push({-uf.size(rv), target - A[i + d][j], cell(i + d, j), v});
              }
            }
            if (is_valid_move(i, j + d))
            {
              if (A[i][j + d] < target)
              {
                // 必要コストと頂点を追加
                cost.push({-uf.size(rv), target - A[i][j + d], cell(i, j + d), v});
              }
            }
          }
        }
      }
    }
  }

  while (!cost.empty())
  {
    tuple<int, int, int, int> p = cost.top();
    cost.pop();
    int c = get<1>(p), v = get<2>(p), u = get<3>(p);
    int ru = uf.root(u);
    if (uf.size(u) >= target + S_THR)
    {
      if (!used[ru])
      {
        int tmp = 0;
        for (auto p2 : cand[ru])
        {
          tmp += p2.first;
        }
        cost_value[ru] = {target * uf.size(ru) - tmp, -tmp - 1, ru};
        used[ru] = true;
      }
      continue;
    }

    int i = (v - 1) / N, j = (v - 1) % N;
    if (c < thr)
    {
      cand[ru].push_back({c, v});
      A[i][j] = target;
      uf.unite(v, u); // u にmerge
      for (int d : {-1, 1})
      {
        if (is_valid_move(i + d, j))
        {
          int rv = uf.root(v);
          int next_v = cell(i + d, j);
          int rnext_v = uf.root(next_v);
          if (A[(next_v - 1) / N][(next_v - 1) % N] == target)
          {
            if (!uf.same(v, next_v)) // ここを ru != rvにしても良さそう？
            {
              // マージが必要だけど、
              // 1. 完全新規 -> 他の2と同様
              // 2. 自分(A)と隣接する他の9(B)がつながる
              if (uf.size(v) < target + S_THR && uf.size(next_v) < target + S_THR)
              {
                //   2-1. size(A)<9, size(B)<9
                for (auto p2 : cand[rnext_v])
                {
                  // rnext_vを育てるまでの操作をruが引き継ぐ
                  cand[ru].push_back(p2);
                }
                uf.unite(next_v, v); // vにnext_vをマージ（vは育てる対象だったので）
              }
              if (uf.size(v) < target + S_THR && uf.size(next_v) >= target + S_THR)
              {
                used[ru] = false;
                int tmp = 0;
                for (auto p2 : cand[rnext_v])
                {
                  tmp += p2.first;
                }
                for (auto p2 : cand[ru])
                {
                  cand[rnext_v].push_back(p2);
                  tmp += p2.first;
                }
                used[rnext_v] = true;
                uf.unite(v, next_v);
                cost_value[ru] = {0, 0, 0};
                cost_value[rnext_v] = {target * uf.size(rnext_v) - tmp, -tmp - 1, rnext_v};
              }
              else if (uf.size(v) >= target + S_THR && uf.size(next_v) < target + S_THR)
              {
                // この時点でr(自分)はどこかとマージ済
                //   2-2. size(A)>= 9, size(B) < 9
                // used[rnext_v] = false;
                int tmp = 0;
                for (auto p2 : cand[rnext_v])
                {
                  cand[ru].push_back(p2);
                  tmp += p2.first;
                }
                uf.unite(next_v, v); // v に next_vをマージ
                cost_value[ru] = {target * uf.size(ru) - tmp, -tmp - 1, ru};
                used[ru] = true;
              }
              else
              {
                //   2-4. size(A)>= 9, size(B) >= 9
                used[rnext_v] = false;
                int tmp = 0;
                for (auto p2 : cand[ru])
                {
                  tmp += p2.first;
                }
                for (auto p2 : cand[rnext_v])
                {
                  cand[ru].push_back(p2);
                  tmp += p2.first;
                }
                uf.unite(next_v, v); // vにnext_vをマージ
                cost_value[ru] = {target * uf.size(ru) - tmp, -tmp - 1, ru};
                used[ru] = true;
                cost_value[rnext_v] = {0, 0, 0};
              }
              // 本当はMを増やしたい. used[]を使って判定すれば不要なものはやらない？
            }
          }
          else if (A[(next_v - 1) / N][(next_v - 1) % N] < target)
          { // 次の隣接点を追加
            cost.push({-uf.size(v), target - A[(next_v - 1) / N][(next_v - 1) % N], next_v, ru});
          }
        }
        if (is_valid_move(i, j + d))
        {
          int rv = uf.root(v);
          int next_v = cell(i, j + d);
          int rnext_v = uf.root(next_v);
          if (A[(next_v - 1) / N][(next_v - 1) % N] == target)
          {
            if (!uf.same(v, next_v)) // ここを ru != rvにしても良さそう？
            {
              // マージが必要だけど、
              // 1. 完全新規 -> 他の2と同様
              // 2. 自分(A)と隣接する他の9(B)がつながる
              if (uf.size(v) < target + S_THR && uf.size(next_v) < target + S_THR)
              {
                //   2-1. size(A)<9, size(B)<9
                for (auto p2 : cand[rnext_v])
                {
                  // rnext_vを育てるまでの操作をruが引き継ぐ
                  cand[ru].push_back(p2);
                }
                uf.unite(next_v, v); // vにnext_vをマージ（vは育てる対象だったので）
              }
              if (uf.size(v) < target + S_THR && uf.size(next_v) >= target + S_THR)
              {
                used[ru] = false;
                int tmp = 0;
                for (auto p2 : cand[rnext_v])
                {
                  tmp += p2.first;
                }
                for (auto p2 : cand[ru])
                {
                  cand[rnext_v].push_back(p2);
                  tmp += p2.first;
                }
                used[rnext_v] = true;
                uf.unite(v, next_v);
                cost_value[ru] = {0, 0, 0};
                cost_value[rnext_v] = {target * uf.size(rnext_v) - tmp, -tmp - 1, rnext_v};
              }
              else if (uf.size(v) >= target + S_THR && uf.size(next_v) < target + S_THR)
              {
                // この時点でr(自分)はどこかとマージ済
                //   2-2. size(A)>= 9, size(B) < 9
                int tmp = 0;
                for (auto p2 : cand[rnext_v])
                {
                  cand[ru].push_back(p2);
                  tmp += p2.first;
                }
                uf.unite(next_v, v); // v に next_vをマージ
                cost_value[ru] = {target * uf.size(ru) - tmp, -tmp - 1, ru};
                used[ru] = true;
              }
              else
              {
                //   2-4. size(A)>= 9, size(B) >= 9
                used[rnext_v] = false;
                int tmp = 0;
                for (auto p2 : cand[ru])
                {
                  tmp += p2.first;
                }
                for (auto p2 : cand[rnext_v])
                {
                  cand[ru].push_back(p2);
                  tmp += p2.first;
                }
                uf.unite(next_v, v); // vにnext_vをマージ
                cost_value[ru] = {target * uf.size(ru) - tmp, -tmp - 1, ru};
                used[ru] = true;
                cost_value[rnext_v] = {0, 0, 0};
              }
              // 本当はMを増やしたい. used[]を使って判定すれば不要なものはやらない？
            }
          }
          else if (A[(next_v - 1) / N][(next_v - 1) % N] < target)
          { // 次の隣接点を追加
            cost.push({-uf.size(v), target - A[(next_v - 1) / N][(next_v - 1) % N], next_v, ru});
          }
        }
      }
    }
  }
  used.assign(N * N + 1, false);
  std::sort(cost_value.begin(), cost_value.end());
  std::reverse(cost_value.begin(), cost_value.end());
  for (auto p : cost_value)
  {
    if (m <= 0)
      break;
    int v = get<2>(p);
    int c = get<1>(p);
    c *= -1;
    if (v == 0)
      continue;
    if (used[v])
      continue;
    if (c >= m)
    {
      break;
    }
    for (auto p : cand[v])
    {
      int u = p.second;
      int ic = p.first;
      if (m - A[(u - 1) / N][(u - 1) % N] - tmpA[(u - 1) / N][(u - 1) % N] <= 0)
        break;
      m -= A[(u - 1) / N][(u - 1) % N] - tmpA[(u - 1) / N][(u - 1) % N];
      tmpA[(u - 1) / N][(u - 1) % N] = A[(u - 1) / N][(u - 1) % N]; // += ic;
      global_used[ic] = true;
    }
    ans.push_back(v);
    used[v] = true;
    m--;
  }
}

int main()
{
  cin >> N >> M;
  A.assign(N, vector<int>(N, 0));
  tmpA.assign(N, vector<int>(N, 0));
  origA.assign(N, vector<int>(N, 0));
  global_used.assign(N * N + 1, false);

  // 入力読み込み
  int cnt = 0;
  REP(i, N)
  {
    REP(j, N)
    {
      cin >> A[i][j];
      tmpA[i][j] = A[i][j];
      origA[i][j] = A[i][j];
    }
  }
  vector<int> ans;
  vector<int> ans2;
  int m = M;
  for (int target = 9; target >= 1; target--)
  {
    solve(target, THR, m, ans, ans2);
    // if (target % 2)
    if (S_THR > 0)
      S_THR--;
    // cout << "DEBUG:" << target << "," << ans.size() << '\n';
  }
  REP(i, N)
  {
    if (M == 0)
      break;
    REP(j, N)
    {
      if (M == 0)
        break;
      if (origA[i][j] < A[i][j])
      {
        REP(t, A[i][j] - origA[i][j])
        {
          if (M == 0)
            break;
          cout << 1 << ' ' << i << ' ' << j << '\n';
          M--;
        }
      }
    }
  }
  for (int v : ans)
  {
    if (M == 0)
      break;
    int i = (v - 1) / N, j = (v - 1) % N;
    if (global_used[v])
      continue;
    cout << 2 << ' ' << i << ' ' << j << '\n';
    global_used[v] = true;
    M--;
  }
  return 0;
}
