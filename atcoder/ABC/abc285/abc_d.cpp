#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

using Graph = std::vector<std::vector<int>>;
vector<bool> seen;
vector<bool> finished;

bool dfs(const Graph &G, int v)
{
  seen[v] = true;
  bool ret = false;
  for (auto next_v : G[v])
  {
    if (seen[next_v] && !finished[next_v])
      return true;
    if (!seen[next_v])
      ret |= dfs(G, next_v);
  }
  finished[v] = true;
  return ret;
}

int main()
{
  int n;
  cin >> n;
  vector<string> S(n);
  vector<string> T(n);
  vector<string> V;
  int vsize = 0;
  unordered_set<string> setV;
  map<string, int> fromS;
  map<string, int> toT;
  REP(i, n)
  {
    cin >> S[i] >> T[i];
    if (fromS[S[i]] > 0 || toT[T[i]] > 0)
    {
      puts("No");
      return 0;
    }
    if (setV.find(S[i]) == setV.end())
    {
      V.push_back(S[i]);
      vsize++;
      setV.insert(S[i]);
    }
    if (setV.find(T[i]) == setV.end())
    {
      V.push_back(T[i]);
      vsize++;
      setV.insert(T[i]);
    }
  }
  sort(V.begin(), V.end());
  map<string, int> VtoIdx;
  REP(i, vsize)
  {
    VtoIdx[V[i]] = i;
  }
  Graph G(vsize);
  seen.resize(vsize);
  finished.resize(vsize);
  REP(i, n)
  {
    int u = VtoIdx[S[i]];
    int v = VtoIdx[T[i]];
    G[u].push_back(v);
  }
  for (int i = 0; i < vsize; i++)
  {
    if (seen[i] && finished[i])
      continue;
    if (dfs(G, i))
    {
      puts("No");
      return 0;
    }
  }

  puts("Yes");

  return 0;
}
