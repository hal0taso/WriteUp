#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    REP(i, n)
    {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int end = t[0] + k;
    int cnt = 1;
    int ans = 1;
    FOR(i, 1, n)
    {
        if ((cnt < c) && (t[i] <= end))
        {
            cnt++;
        }
        else
        {
            end = t[i] + k;
            cnt = 1;
            ans++;
        }
    }
    cout << ans << endl;
}
