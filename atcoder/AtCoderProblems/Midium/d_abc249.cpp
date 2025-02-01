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
    ll ai;
    map<ll, ll> m;
    vector<ll> a;
    REP(i, n)
    {
        cin >> ai;
        m[ai]++;
        if (m[ai] == 1)
        {
            a.push_back(ai);
        }
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int j;
    REP(i, a.size())
    {
        ai = a[i];
        j = 0;
        while (a[j] * a[j] <= a[i])
        {
            ans += 2 * m[a[i]] * (m[a[i] / a[j]] * m[a[j]]);
            j++;
        }
    }
    cout << ans << endl;
}
