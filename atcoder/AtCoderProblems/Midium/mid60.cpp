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
    vector<ll> a(5, 0);
    string f = "MARCH";
    string s;
    ll ans = 0;
    REP(i, n)
    {
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            if (s[0] == f[j])
            {
                a[j]++;
                break;
            }
        }
    }

    REP(i, 5)
    {
        FOR(j, i + 1, 5)
        {
            FOR(k, j + 1, 5)
            {
                ans += a[i] * a[j] * a[k];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
