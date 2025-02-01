#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n, k;
  cin >> n >> k;
  vector<string> S;
  REP(i, n)
  {
    string s;
    cin >> s;
    if (i < k)
      S.push_back(s);
  }
  sort(S.begin(), S.end());
  REP(i, k)
  {
    cout << S[i] << endl;
  }
  return 0;
}
