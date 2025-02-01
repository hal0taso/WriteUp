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
    int q;
    cin >> s >> q;
    deque<char> deq;
    for (char c : s)
        deq.push_back(c);

    int t, f;
    bool flg = true; // true: neutral, false: reversed
    REP(i, q)
    {
        cin >> t;
        if (t == 1)
            flg = !flg;
        else
        {
            char c;
            cin >> f >> c;
            if ((f == 1 ^ !flg))
                deq.push_front(c);
            else
                deq.push_back(c);
        }
    }
    string ans = "";
    if (!flg)
    {
        while (!deq.empty())
        {
            ans += deq.back();
            deq.pop_back();
        }
    }
    else
    {
        while (!deq.empty())
        {
            ans += deq.front();
            deq.pop_front();
        }
    }
    cout << ans << '\n';
    return 0;
}
