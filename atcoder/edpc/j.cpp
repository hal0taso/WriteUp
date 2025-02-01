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

double f(int n, int x, int y, int z, vector<vector<vector<double>>> &dp)
{
    if (dp[x][y][z] >= 0)
    {
        return dp[x][y][z];
    }
    if (x == 0 && y == 0 && z == 0)
    {
        dp[x][y][z] = 0.;
        return 0.;
    }
    double ans = 1.;
    // cout << x << y << z << '\n';
    if (x > 0)
        ans += (double)x / (double)n * f(n, x - 1, y, z, dp);
    if (y > 0)
        ans += (double)y / (double)n * f(n, x + 1, y - 1, z, dp);
    if (z > 0)
        ans += (double)z / (double)n * f(n, x, y + 1, z - 1, dp);
    ans /= (1. - (double)(n - x - y - z) / (double)n);
    dp[x][y][z] = ans;
    // cout << x << y << z << ":" << dp[x][y][z] << '\n';
    return dp[x][y][z];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0, y = 0, z = 0;
    REP(i, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            x++;
        if (a[i] == 2)
            y++;
        if (a[i] == 3)
            z++;
    }
    // dp[x][y][z]:= 1個の寿司がx皿, 2個の寿司がy皿, 3個の寿司がz皿ある時の操作回数の期待値
    // dp[0][0][0] が答え
    /*
    dp[x][y][z] = 1
                + dp[x + 1][y][z] * (x + 1) / n
                + dp[x][y + 1][z] * (y + 1) / n
                + dp[x][y][z + 1] * (z + 1) / n
                + dp[x][y][z] * (n - x - y - z)/n
    dp[x][y][z] = (1
                + dp[x + 1][y][z] * (x + 1) / n
                + dp[x][y + 1][z] * (y + 1) / n
                + dp[x][y][z + 1] * (z + 1) / n ) / (1 - (n - x - y - z)/n)
     */
    vector dp(n + 1, vector(n + 1, vector<double>(n + 1, -1.0)));
    // dp[x][y][z] = 0.;
    cout << fixed << setprecision(10) << f(n, x, y, z, dp) << '\n';
    return 0;
}