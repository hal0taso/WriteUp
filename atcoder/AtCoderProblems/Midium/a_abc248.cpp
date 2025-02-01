#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

bool compare(pair<long long, int> a, pair<long long, int> b)
{
    if (get<1>(a) < get<1>(b))
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << "0" << s.substr(1) << endl;
}
