#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
int INF = 1e8;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> s(n + 1);
  vector<vector<int>> G(n + 1);
  vector<vector<int>> Gr(n + 1);
  FOR(i, 1, n + 1)
  {
    cin >> s[i];
    FOR(j, i + 1, i + m + 1)
    {
      if (s[i][j - i - 1] == '1')
        G[i].push_back(j), Gr[j].push_back(i);
      ;
    }
  }
  vector<int> dist1(n + 1, INF); // 全頂点を「未訪問」に初期化
  vector<int> distN(n + 1, INF); // 全頂点を「未訪問」に初期化
  queue<int> que;
  // 初期条件 (頂点 0 を初期ノードとする)
  dist1[1] = 0;
  que.push(1); // 0 を橙色頂点にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty())
  {
    int v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (int nv : G[v])
    {
      if (dist1[nv] != INF)
        continue; // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について距離情報を更新してキューに追加する
      dist1[nv] = dist1[v] + 1;
      que.push(nv);
    }
  }
  // 初期条件 (頂点 0 を初期ノードとする)
  distN[n] = 0;
  que.push(n); // 0 を橙色頂点にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty())
  {
    int v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (int nv : Gr[v])
    {
      if (distN[nv] != INF)
        continue; // すでに発見済みの頂点は探索しない

      // 新たな白色頂点 nv について距離情報を更新してキューに追加する
      distN[nv] = distN[v] + 1;
      que.push(nv);
    }
  }

  FOR(k, 2, n)
  {
    int tmp = INF;
    FOR(i, max(1, min(k + 1 - m, k - 1)), k)
    {
      FOR(j, i + 1, i + m + 1)
      {
        if (j == k)
          continue;
        if (s[i][j - i - 1] == '1')
        {
          if (tmp > dist1[i] + 1 + distN[j])
          {
            tmp = dist1[i] + 1 + distN[j];
          }
        }
      }
    }
    if (tmp == INF)
      cout << -1;
    else
      cout << tmp;
    if (k < n - 1)
      cout << " ";
    else
      cout << "\n";
  }
  return 0;
}
