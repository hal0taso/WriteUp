#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    vector<long long> A(46, 0), B(46, 0), C(46, 0);

    REP(i, n)
    {
        cin >> a[i];
        A[a[i] % 46]++;
    }

    REP(i, n)
    {
        cin >> b[i];
        B[b[i] % 46]++;
    }

    REP(i, n)
    {
        cin >> c[i];
        C[c[i] % 46]++;
    }
    long long ans = 0;
    REP(i, 46)
    {
        REP(j, 46)
        {
            int k = (i + j) % 46;
            if (k < 0)
                k += 46;
            k = (46 - k) % 46;
            ans += A[i] * B[j] * C[k];
        }
    }
    cout << ans << '\n';

    return 0;
}