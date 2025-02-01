#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int M;
long double eps;
int n = 21;
int N = n * (n - 1) / 2;
// dp[x][y][c]: probabiliy of

template <typename T>
vector<vector<T>> binomial_table(int N)
{
  vector<vector<T>> mat(N + 1, vector<T>(N + 1));
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i)
        mat[i][j] = 1;
      else
        mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return mat;
}

int main()
{
  cin >> M >> eps;
  // 枝 i, j が1->0になる確率=eps
  // N頂点、M本の枝のグラフの枝数X=xとなる確率 P(X = x)
  // P(X = x) = \sum_{y = 0}^{x} \binom(M, y) \eps^{M-y} (1 - \eps)^y + \binom(N^2 - M, x-y) \eps^{x-y} (1 - \eps)^{N^2 - M - (x - y)}
  //          =
  // モーメント G(s) = E[s^X] として、期待値 = dG(0)/ds =
  // M本の1枝のうち、y本の枝が減る確率　\binom(M, y) \eps^{y} (1 - \eps)^{M - y}
  // N^2 - M 本の0枝のうち、z本の枝が増える確率 = \binom(N^2 - M, z) \eps^{z} (1 - \eps)^{N^2 - M - z}
  // M - y + z = x となる確率 (z = x + y - M)
  // = \sum_{y = 0}^{M} \binom{M, y} \eps^{y} (1 - \eps)^{M - y} * \binom{N^2 - M, x + y - M} \eps^{x + y - M} (1 - \eps)^{N^2 - (x + y)}
  // = \sum_{y = 0}^{M} \binom{M, y} * \binom{N^2 - M, x + y - M} \eps^{x + 2y - M} (1 - \eps)^{N^2 + M - x - 2y)}
  // \binom{M, y} * \binom{N^2 - M, x + y - M} = \frac{M!}{(M-y)!y!}\frac{(N^2 - M)!}{(N^2 - (x + y))!(x + y - M)!}
  // e.g., M = 10, x = 12, (y, z) = {(0, 2), (1, 3), (2, 4), (3, 5), (4, 6), (5, 7), (6, 8), (7, 9), (8, 10), (9, 11), (10, 12)}
  vector<vector<long long>> mat(N + 1, vector<long long>(N + 1));
  mat = binomial_table<long long>(N);
  vector<vector<long double>> prob(N + 1, vector<long double>(N + 1, 0.0));
  vector<long double> mean(N + 1, 0.0);
  vector<long double> mean2(N + 1, 0.0);
  vector<long double> flip(N + 1);
  vector<long double> left(N + 1);
  int diff = N / M;

  REP(i, N + 1)
  {
    flip[i] = pow(eps, i);
    left[i] = pow(1 - eps, i);
  }
  for (int m = 0; m <= N; m += diff)
  {
    for (int x = 0; x <= N; x++)
    {
      for (int y = max(m - x, 0); y <= min(m, N - x); y++)
      {
        prob[m][x] += (long double)mat[m][y] * flip[y] * left[m - y] * (long double)mat[N - m][x - m + y] * flip[x - m + y] * left[N - x - y];
        // cout << "prob[" << m << "][" << x << "]=" << prob[m][x] << endl;
        // cout << mat[m][y] << endl;
        // cout << flip[y] << endl;
        // cout << left[m - y] << endl;
        // cout << mat[N - m][x - m + y] << endl;
        // cout << flip[x - m + y] << endl;
        // cout << left[N - x - y] << endl;
      }
      mean2[x] += m * prob[m][x];
      mean[m / diff] += x * prob[m][x];
    }
  }
  // REP(m, N)
  // {
  //   cout << mean[m] << endl;
  // }
  map<int, int> Map;
  REP(m, N)
  {
    Map[(int)round(mean[m])] = m;
  }
  cout << n << endl;
  int m = 0;
  REP(i, M)
  {
    FOR(j, 1, m + 1)
    {
      cout << 1;
    }
    FOR(j, 1, N - m + 1)
    {
      cout << 0;
    }
    cout << endl;
    m += diff;
  }

  string s;
  int cnt;
  REP(i, 100)
  {
    cin >> s;
    cnt = 0;
    REP(j, N)
    {
      if (s[j] == '1')
      {
        cnt++;
      }
    }
    cout << Map[cnt] << endl;
    // cout << (int)round(mean2[cnt]) << endl;
  }

  // cout << "YES" << endl;
  return 0;
}
