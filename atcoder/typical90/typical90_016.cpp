#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

constexpr long long INF = 10000;

int main()
{
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    long long ans = INF;
    REP(x, INF)
    {
        if (x * a > n)
            continue;
        REP(y, INF - x)
        {
            if (y * b > n)
                continue;
            long long tmp = n - (x * a) - (y * b);
            if (tmp >= 0 && tmp % c == 0)
            {
                int z = tmp / c;
                if (x + y + z < ans)
                    ans = x + y + z;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}