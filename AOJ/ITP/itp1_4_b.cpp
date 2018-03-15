#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define REP(i,n)   for(int i = 0; i < n; ++i)
typedef long long ll;
typedef unsigned long long ull;

ull powmod(ull a, ull b, ull mod) {ull res = 1; for(; b; b >>= 1){if (b & 1) {res = res * a % mod;} a = a * a % mod;} return res;}

int main(){
  long double r;
  cin >> r;

  long double s = M_PI * (r * r);

  long double c = M_PI * 2 * r;

  cout << fixed << setprecision(5) << s << " " << fixed << setprecision(5) << c << "\n";
 
}
