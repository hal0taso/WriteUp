#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
  int n;
  cin >> n;
  vector<pair<string, int>> S(n);
  // vector<RH> R;
  REP(i, n)
  {
    string s;
    cin >> s;
    S[i] = {s, i};
    // T += S[i];
  }
  stable_sort(S.begin(), S.end());

  // R.push_back(RH(S[i]));
  // RH rh(T);
  vector<int> ans(n, 0);
  REP(i, n - 1)
  {
    auto [a, ai] = S[i];
    auto [b, bi] = S[i + 1];
    int now = 0;
    while (now < a.size() && now < b.size())
    {
      if (a[now] != b[now])
        break;
      now++;
    }
    ans[ai] = max(ans[ai], now);
    ans[bi] = max(ans[bi], now);
  }
  REP(i, n)
  cout << ans[i] << '\n';

  return 0;
}
