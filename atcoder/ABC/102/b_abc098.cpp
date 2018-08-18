// b_abc098.cpp
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define REP(i,n)   for(int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ull powmod(ull a, ull b, ull mod) {ull res = 1; for(; b; b >>= 1){if (b & 1) {res = res * a % mod;} a = a * a % mod;} return res;}

int main()
{
    ull n, sn, tmp;
    cin >> n;
    tmp = n;
    sn = 0;
    for(int i = 9; i > 0; --i){
        sn += (tmp % ull(pow(10, double(i))));
        cout << sn << endl;
        tmp -= (tmp % ull(pow(10, i))) * pow(10, double(i));
        cout << tmp << endl;
    }

    if (n % sn == 0){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}
