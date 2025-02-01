#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
// using namespace atcoder;
// using mint = modint1000000007;

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
    int n, k;
    cin >> n >> k;
    int N = 5001;
    vector v(N, vector<int>(N, 0));
    REP(i, n)
    {
        int a, b;
        cin >> a >> b;
        v[a][b]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            v[i][j] += v[i][j - 1];
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            v[i][j] += v[i - 1][j];
        }
    }

    int ans = 0;
    REP(i, N - k - 1)
    {
        REP(j, N - k - 1)
        {
            ans = max(ans, v[i + k + 1][j + k + 1] - v[i + k + 1][j] - v[i][j + k + 1] + v[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}