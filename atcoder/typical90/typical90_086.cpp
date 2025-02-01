#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RFOR(i, a, b) for (ll i = b - 1; i >= a; i--)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
using vvi = vector<vector<int>>;
using vi = vector<int>;

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> x(q), y(q), z(q), w(q);
    REP(i, q)
    {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--;
        y[i]--;
        z[i]--;
    }
    mint ans = 1;
    // wのi-bit目のチェック
    REP(i, 60)
    {
        mint tmp = 0;
        // n個の数列のi-bit目を全探索
        REP(j, 1 << n)
        {
            bool flg = true;
            REP(k, q)
            {
                if ((((j >> x[k]) & 1) | ((j >> y[k]) & 1) | ((j >> z[k]) & 1)) == ((w[k] >> i) & 1))
                {
                    // puts("debug");
                }
                else
                {
                    flg = false;
                    break;
                }
            }
            if (flg)
                tmp++;
        }
        ans *= tmp;
    }
    cout << ans.val() << '\n';

    return 0;
}
