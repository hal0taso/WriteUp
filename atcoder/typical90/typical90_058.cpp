#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

const long long MOD = 100000LL;
// 99999
// 99999 + 9+9+9+9+9 = 100044 = 00044
// 00044 + 4+4 = 00052
// 00052 + 5+2 = 00059
// 00059 + 5+9 = 00073
// 00073 + 7+3 = 000

// 55555
// 55555 + 5+5+5+5+5 = 55555 + 25 = 55580
// 55580 + 5+5+5+8+0 = 55580 + 23 = 55603
// 55603 + 5+5+6+0+3 = 55603 + 19 = 55632
int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(100000, -1);
    vector<ll> b(100000, -1);

    int now = 0;
    int prev;
    while (a[n] < 0 && now <= k)
    {
        a[n] = now;
        b[now] = n;
        // b[now] = n;
        ll tmp = n;
        ll add = 0;
        REP(i, 5)
        {
            add += (tmp % 10);
            tmp /= 10;
        }
        prev = n;
        n = (n + add) % MOD;
        now++;
    }

    if (a[n] < 0)
        cout << prev << endl;
    else
    {
        k = (k - a[n]) % (now - a[n]);
        cout << b[k + a[n]] << endl;
    }

    return 0;
}