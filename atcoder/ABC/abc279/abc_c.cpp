#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

bool is_square(vector<int> x, vector<int> y)
{
  vector<int> l(4);
  bool ret = true;
  REP(i, 4)
  {
    int j = (i + 1) % 4;
    l[i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  }
  REP(i, 4)
  {
    int j = (i + 1) % 4;

    if (l[i] != l[j])
      ret = false;
  }

  if ((x[0] - x[2]) * (x[1] - x[3]) + (y[0] - y[2]) * (y[1] - y[3]) != 0)
    ret = false;
  return ret;
}

int main()
{
  int h, w;

  cin >> h >> w;
  vector<string> St(w, "");
  vector<string> Tt(w, "");
  vector<string> S(h);
  vector<string> T(h);
  REP(i, h)
  {
    cin >> S[i];
    REP(j, w)
    {
      St[j] += S[i][j];
    }
  }
  REP(i, h)
  {
    cin >> T[i];
    REP(j, w)
    {
      Tt[j] += T[i][j];
    }
  }
  sort(St.begin(), St.end());
  sort(Tt.begin(), Tt.end());
  REP(i, w)
  {
    if (St[i] != Tt[i])
    {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
