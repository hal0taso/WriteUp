#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{

    int h, w, n;
    cin >> w >> h >> n;
    vector<vector<int>> B(h + 1, vector<int>(w + 1, 1));
    REP(i, n)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1)
        {
            REP(j, h + 1)
            REP(k, x)
            B[j][k] = 0;
        }
        if (a == 2)
        {
            REP(j, h + 1)
            FOR(k, x, w + 1)
            B[j][k] = 0;
        }
        if (a == 3)
        {
            REP(j, y)
            REP(k, w + 1)
            B[j][k] = 0;
        }
        if (a == 4)
        {
            FOR(j, y, h + 1)
            REP(k, w + 1)
            B[j][k] = 0;
        }
    }
    int ans = 0;
    REP(i, h)
    REP(j, w)
    ans += B[i][j];

    cout << ans << endl;
    return 0;
}
