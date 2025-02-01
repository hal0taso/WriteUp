#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, p;
    cin >> n >> p;
    int ai;
    long long n_odd = 0;
    long long n_even = 0;
    REP(i, n)
    {
        cin >> ai;
        if (ai % 2 == 1)
        {
            n_odd++;
        }
        else
        {
            n_even++;
        }
    }
    vector<long long> comb_odd(n_odd + 1, 1);
    vector<long long> comb_even(n_even + 1, 1);
    long long denom = n_odd;
    FOR(i, 1, n_odd + 1)
    {
        comb_odd[i] = comb_odd[i - 1] * denom / i;
        denom--;
    }
    denom = n_even;
    FOR(i, 1, n_even + 1)
    {
        comb_even[i] = comb_even[i - 1] * denom / i;
        denom--;
    }
    long long total_comb_from_even = 0;
    REP(i, n_even + 1)
    {
        total_comb_from_even += comb_even[i];
    }
    long long total_comb_from_odd = 0;
    for (int i = p; i < n_odd + 1; i += 2)
    {
        total_comb_from_odd += comb_odd[i];
    }
    cout << total_comb_from_even * total_comb_from_odd << endl;
    return 0;
}
