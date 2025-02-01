#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

long double calc(long double t, long double A, long double B)
{
  return A / sqrt(t + 1.0) + t * B;
}

int main()
{
  long double A, B;
  cin >> A >> B;
  long double t = pow(A * A / (4.0 * B * B), 1.0 / 3.0) - 1.0;
  long double t1 = floor(t), t2 = ceil(t);
  long double ans1, ans2, ans0;
  ans1 = A / sqrt(t1 + 1) + t1 * B;
  ans2 = A / sqrt(t2 + 1) + t2 * B;
  ans0 = calc(0, A, B);
  cout << fixed;
  if (B - A / 2.0 < 0)
  {
    if (t > 0)
    {
      if (ans1 < ans2)
      {
        cout << std::setprecision(10) << ans1 << '\n';
      }
      else
      {
        cout << std::setprecision(10) << ans2 << '\n';
      }
    }
    else
    {
      cout << std::setprecision(10) << calc(0, A, B) << '\n';
    }
  }
  else
  {
    if (t > 0)
    {
      if (ans1 < ans2)
      {
        if (ans1 < ans0)
          cout << std::setprecision(10) << ans1 << '\n';
        else
          cout << std::setprecision(10) << ans0 << '\n';
      }
      else
      {
        if (ans0 < ans1)
          cout << std::setprecision(10) << ans2 << '\n';
        else
          cout << std::setprecision(10) << ans0 << '\n';
      }
    }
    else
    {
      cout << std::setprecision(10) << ans0 << '\n';
    }
  }
  return 0;
}
