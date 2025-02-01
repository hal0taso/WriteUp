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
    vector<int> a(n + 1, 0), b(n + 1, 0);
    int c;
    FOR(i, 1, n + 1)
    {
        cin >> c;
        if (c == 1)
        {
            cin >> a[i];
        }
        else
        {
            cin >> b[i];
        }
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    int q, l, r;
    cin >> q;
    REP(i, q)
    {
        cin >> l >> r;
        l--;
        cout << a[r] - a[l] << ' ' << b[r] - b[l] << '\n';
    }
    return 0;
}
