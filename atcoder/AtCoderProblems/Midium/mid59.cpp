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
    vector<int> a(n);
    int ans = 0;
    int p = 0;
    REP(i, n)
    {
        cin >> a[i];
        if (i + 1 == a[i] && p == 0)
        {
            ans++;
            p++;
        }
        else
        {
            p = 0;
        }
    }
    cout << ans << '\n';

    return 0;
}
