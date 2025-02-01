#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);

constexpr int MOD = 1000000000 + 7;

const string direction = "<>v^";
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {-1, 1, 0, 0};

using Graph = std::vector<std::vector<int>>;

void bfs(Graph G, int s, vector<int> &dist)
{
  // todo リストを表すキュー
  queue<int> que;

  // 頂点 0 を始点とする
  dist[s] = 0;
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
  vector<string> B(h);
  REP(i, h)
  cin >> B[i];
  vector viewed(h, vector<int>(w, 0));
  REP(k, 4)
  {
    REP(i, h)
    {
      REP(j, w)
      {
        if (B[i][j] == direction[k])
        {
          int x = i, y = j;
          do
          {
            viewed[x][y] = 1;
            x += dx[k];
            y += dy[k];
          } while (x < h && x >= 0 && y >= 0 && y < w && B[x][y] == '.');
        }
      }
    }
  }

  Graph G(h * w);
  int s, t;
  REP(i, h)
  {
    REP(j, w)
    {
      if (B[i][j] == 'S')
        s = i * w + j;
      if (B[i][j] == 'G')
        t = i * w + j;
      if ((B[i][j] == '.' || B[i][j] == 'S' || B[i][j] == 'G') && viewed[i][j] == 0)
        REP(k, 4)
        {
          int x = i + dx[k], y = j + dy[k];
          if (x < h && x >= 0 && y >= 0 && y < w && B[x][y] == '.' && viewed[x][y] == 0)
          {
            G[i * w + j].push_back(x * w + y);
            G[x * w + y].push_back(i * w + j);
          }
        }
    }
  }
  vector<int> dist(h * w, -1);
  bfs(G, s, dist);
  cout << dist[t] << '\n';

  return 0;
}