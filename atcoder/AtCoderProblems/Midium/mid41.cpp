
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
    int ans = 100;
    REP(i, n)
    {
        int ans_i = 0;
        int curr = -1;
        REP(j, n)
        {
            if (s[j] == s[i])
            {
                int tmp = j - curr - 1;
                if (ans_i < tmp)
                {
                    ans_i = tmp;
                }
                curr = j;
            }
        }
        if (n - curr - 1 > ans_i)
        {

            ans_i = n - curr - 1;
        }
        if (ans > ans_i)
        {
            ans = ans_i;
        }
    }
    cout << ans << endl;

    return 0;
}
