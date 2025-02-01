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
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
constexpr long long INF = (1LL << 60);

constexpr int MOD = 1000000000 + 7;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    /*
    dp[i][j][S]: i番目まで決めて最後にjだったときに選んだ集合がSである組合せ
    dp[0][0][\empty] = 1;
    for j = 1, .., n:
        for k = 1,..,n:
            for S = 1, ..., 1<<n - 1:
                if j \in S and k \in S:
                    dp[i][j][S] += dp[i-1][k][S^j] if s[i-1] == '<' and if k < j;
                    dp[i][j][S] += dp[i-1][k][S^j] if s[i-1] == '>' and if k > j;
    -> O(n^3 2^n)-time
    */
    /*
    dp[i][j]: i番目まで決めたときに最後の数以上のものがj個残っている組合せ
    dp[0][n] = 1
    for i = 1,...,n:
        for j = 0,...,n-i:
            // i番目まで決めてj個上にあるので, i-1番目まで決めたときには未選択のi番目を含めたj+1個が残る. 最大でもn-(i-1)個までしか残らない
            dp[i][j] = \sum_{k=j+1}^{n - i + 1} dp[i-1][k] if s[i-1] == '<'
            // i番目まで決めてj個上にあるので, i-1番目まで決めたときには高々j個までしか残らない(>なので大きい数字から遷移してくるため)
            dp[i][j] = \sum_{k=0}^{j} dp[i-1][k] if s[i-1] == '>'
    */
    vector dp(n + 1, vector<mint>(n + 1, 0));
    FOR(j, 0, n)
    dp[1][j] = 1;
    FOR(i, 2, n + 1)
    {
        // cum[l]は\sum_{k=0}^{l-1}に対応していることに注意
        vector<mint> cum(n + 2, 0);
        FOR(j, 1, n - i + 3)
        cum[j] += cum[j - 1] + dp[i - 1][j - 1];
        if (s[i - 2] == '<')
        {
            REP(j, n - i + 1)
            dp[i][j] += cum[n - i + 2] - cum[j + 1];
        }
        else
        {
            REP(j, n - i + 1)
            dp[i][j] += cum[j + 1];
        }
    }

    cout << dp[n][0].val() << '\n';
    return 0;
}