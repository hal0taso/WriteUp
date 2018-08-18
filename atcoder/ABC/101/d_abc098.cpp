// d_abc098.cpp
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

#define FOR(i,a,b) for(i = a; i < b; ++i)
#define REP(i,n)   for(i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull powmod(ull a, ull b, ull mod) {ull res = 1; for(; b; b >>= 1){if (b & 1) {res = res * a % mod;} a = a * a % mod;} return res;}

int main()
{
    ull l, r, n, x, res, sum, xors;
    vector<ull> a;

    cin >> n;
    REP(l, n) {
        cin >> x;
        a.push_back(x);
    }
    res = 0;
    sum = a[0];
    xors = a[0];
    r = 0;
    REP(l, n) {
        if (l > 0) {
            sum -= a[l - 1];
            xors ^= a[l - 1];
        }

        if (l > r){
            r = l;
        }
        while (r < n) {
            if (sum != xors){
                sum -= a[r];
                xors ^= a[r];
                // res--;
                cout << "[*]" << l << ", " << r << "\n";
                --r;
                break;
            }
            cout << l << ", " << r << "\n";
            ++r;
            sum += a[r];
            xors ^= a[r];
            res ++;
        }
        //res += r - l;
    }

    cout << res << "\n";
}
