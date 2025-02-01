#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    REP(i, n)
    cin >> A[i];
    int t, x, y;
    int s = n;
    REP(i, q)
    {
        cin >> t >> x >> y;
        x--, y--;
        if (t == 1)
        {
            swap(A[(x + s) % n], A[(y + s) % n]);
        }
        else if (t == 2)
        {
            s--;
            if (s < 0)
                s += n;
        }
        else
        {
            cout << A[(x + s) % n] << '\n';
        }
    }
    return 0;
}