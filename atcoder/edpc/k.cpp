#include <bits/stdc++.h>
using namespace std;

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
constexpr long long INF = 1000000000000LL;

constexpr int MOD = 1000000000 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n)
    {
        cin >> a[i];
    }
    vector dp(k + 1, 0);
    REP(i, k + 1)
    {
        int res = 0;
        for (int ai : a)
        {
            if (i - ai >= 0)
            {
                if (dp[i - ai] == 0)
                {
                    res = ai;
                    break;
                }
            }
        }
        dp[i] = res;
    }
    if (dp[k] > 0)
        puts("First");
    else
        puts("Second");
    return 0;
}