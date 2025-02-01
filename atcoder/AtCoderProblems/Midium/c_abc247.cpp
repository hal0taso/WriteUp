#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int Q;
    cin >> Q;
    vector<pair<long long, long long>> a;
    vector<long long> o;
    int op;
    long long x;
    long long c;
    int aidx = 0;
    int onum = 0;
    int oidx = 0;
    REP(i, Q)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> c;
            a.push_back(make_pair(x, c));
        }
        else
        {
            cin >> c;
            o.push_back(c);
            onum++;
        }
    }
    long long ans = 0;
    while (oidx < onum)
    {
        long long bn = o[oidx];
        if (bn > a[aidx].second)
        {
            o[oidx] -= a[aidx].second;
            ans += a[aidx].second * a[aidx].first;
            aidx++;
        }
        else
        {

            ans += bn * a[aidx].first;
            a[aidx].second -= bn;
            oidx++;
            cout << ans << endl;
            ans = 0;
        }
    }
}
