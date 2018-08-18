// c_abc098.cpp
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

void printVec(vector<ll> A, ll N){
    for (int i = 0; i < N; i ++){
        if(i == N - 1){
            cout << A[i] << "\n";
        }else{
            cout << A[i] << " ";
        }
    }
}

ull count(string str, char c)
{
    ull cnt = 0;
    ull i;
    REP(i, str.length()){
        if(str[i] == c){
            ++cnt;
        }
    }
    return cnt;
}

// pair<ll, ll> error(vector<ll> a, ull len, ull b)
// {
//     ll err;
//     ull i, err_abs;


//     FOR(i, 1, len + 1){
//         err = a[i] - (b + i);
//         err_abs = (ll)abs(err);
//     }

//     return make_pair(err, err_abs);
// }

ll error(vector<ll> a, ull len, ll b)
{
    ll err, err_abs;
    ull i;

    err_abs = 0;
    REP(i, len){
        err = a[i] - (b + i + 1);
        err_abs += abs(err);
    }

    return err_abs;
}

int main()
{
    ull n, i;
    vector<ll> a, err_v;
    // ll max_a, min_a;
    ll x, err_now, err_prev, b, l, r;

    cin >> n; cin.ignore();

    REP(i, n) {
        cin >> x;
        a.push_back(x);
    }

    // cout << n << endl;
    // printVec(a, n);
    // min_a = *min_element(a.begin(), a.end());
    // max_a = *max_element(a.begin(), a.end());


    b = 0;
    err_now = error(a, n, b);
    r = error(a, n, b + 1);
    l = error(a, n, b - 1);
    if (l - err_now > 0){
        err_prev = l;
        while (true){
            if (err_now - err_prev >= 0){
                err_now = min(err_prev, err_now);
                break;
            }
            ++b;
            err_prev = err_now;
            err_now = error(a, n, b);
        }
    }else if(r - err_now > 0){
        err_prev = r;
        while (true){
            if (err_now - err_prev >= 0){
                err_now = min(err_prev, err_now);
                break;
            }
            --b;
            err_prev = err_now;
            err_now = error(a, n, b);
        }
    }

    err_now = *min_element(err_v.begin(), err_v.end());

    cout << err_now << endl;

}
