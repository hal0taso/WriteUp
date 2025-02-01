#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

constexpr long long INF = 10000;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long tmp = 1;
    REP(i, b)
    {
        if (a < tmp)
        {
            puts("Yes");
            return 0;
        }
        tmp *= c;
    }
    if (a < tmp)
        puts("Yes");
    else
        puts("No");
    return 0;
}