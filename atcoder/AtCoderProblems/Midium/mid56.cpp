#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> res(n, s);
    FOR(i, k, n)
    {
        if (s < 1e9)
            res[i]++;
        else
            res[i] = 1;
    }
    REP(i, n - 1)
    {
        cout << res[i] << ' ';
    }
    cout << res[n - 1] << '\n';
    return 0;
}
