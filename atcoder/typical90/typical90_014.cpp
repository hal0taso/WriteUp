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
    vector<int> a(n), b(n);
    REP(i, n)
    {
        cin >> a[i];
    }
    REP(i, n)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    REP(i, n)
    {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << '\n';
}