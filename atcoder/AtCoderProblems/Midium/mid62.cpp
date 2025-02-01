#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n)
    cin >> a[i];

    REP(i, n - 1)
    {
        a[i + 1] = gcd(a[i], a[i + 1]);
    }
    cout << a[n - 1] << endl;
    return 0;
}
