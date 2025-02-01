
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    FOR(i, 1, n + 1)
    {
        if (s[i - 1] == 'U')
        {
            ans += n - i;
            ans += 2 * (i - 1);
        }
        else
        {
            ans += 2 * (n - i);
            ans += i - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
