#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    int cnt, cnt_d = 0;
    cin >> s;
    string ans = "Yes";

    if (d < c)
    {
        cnt = 0;
        for (int i = b - 1; i <= d + 1; i++)
        {
            if (s[i - 1] == '.')
                cnt++;
            else
            {
                if (cnt > cnt_d)
                    cnt_d = cnt;
                cnt = 0;
            }
        }
        if (cnt > cnt_d)
            cnt_d = cnt;

        if (cnt_d < 3)
            ans = "No";
    }
    cnt = 0;
    for (int i = b; i <= d; i++)
    {
        if (s[i - 1] == '.')
            cnt = 0;
        else
            cnt++;
        if (cnt > 1)
        {
            ans = "No";
            break;
        }
    }
    cnt = 0;
    for (int i = a; i <= c; i++)
    {
        if (s[i - 1] == '.')
            cnt = 0;
        else
            cnt++;
        if (cnt > 1)
        {
            ans = "No";
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
