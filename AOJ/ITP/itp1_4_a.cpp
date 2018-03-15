#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define REP(i,n)   for(int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;

ull powmod(ull a, ull b, ull mod) {ull res = 1; for(; b; b >>= 1){if (b & 1) {res = res * a % mod;} a = a * a % mod;} return res;}

int main(){
  ull a, b;

  ull d, r;
  double f;

  cin >> a >> b;

  d = a / b;
  r = a % b;

  f = (double)a / (double)b;

  cout << d << " " << r << " " << fixed << setprecision(5) << f << "\n";
}
