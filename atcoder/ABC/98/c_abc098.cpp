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

void printVec(vector<ull> A, int N){
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

int main()
{
    string s;
    ull i, tmp, n, res;
    vector<ull> r, l, cnt;
    r.push_back(0);
    l.push_back(0);

    cin >> n; cin.ignore();
    getline(cin, s);

    REP(i, n-1) {
        if (s[i] == 'W') {
            tmp = l[i] + 1;
        } else {
            tmp = l[i];
        }
        l.push_back(tmp);

        if (s[n - i - 1] == 'E') {
            tmp = r[i] + 1;
        } else {
            tmp = r[i];
        }
        r.push_back(tmp);

    }

    REP(i, n){
        cnt.push_back(r[n - i - 1] + l[i]);
    }

    // printVec(r, r.size());
    // printVec(l, l.size());
    // printVec(cnt, cnt.size());

    res = *min_element(cnt.begin(), cnt.end());
    cout << res << "\n";
}
