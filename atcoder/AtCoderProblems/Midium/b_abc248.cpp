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
    vector<long long> a(n);
    REP(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long>{});
    vector<long long> x(2, 0);
    long long prev = -1;
    int cnt = 0;
    REP(i, n)
    {
        if (cnt > 1)
        {
            break;
        }
        if (prev == a[i])
        {
            x[cnt] = a[i];
            cnt++;
            prev = -1;
        }
        else
        {
            prev = a[i];
        }
    }
    cout << x[0] * x[1] << endl;
}
