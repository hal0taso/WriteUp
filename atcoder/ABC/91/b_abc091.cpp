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

int main(){
  ull N, M;
  map<string, ll> mp;
  ll res = 0;

  cin >> N;
  REP(i, N){
    string s;
    cin >> s;
    auto itr = mp.find(s);
    if (itr != mp.end()){
      ++mp[s];
    }else{
      mp[s] = 1;
    }
  }

  cin >> M;
  REP(i, M){
    string s;
    cin >> s;
    auto itr = mp.find(s);
    if (itr != mp.end()){
      --mp[s];
    }else{
      mp[s] = -1;
    }
  }

  for (auto itr = mp.begin(); itr != mp.end(); ++itr){
    if(itr->second > res){
      res = itr->second;
    }
  }
  cout << res << "\n";

}
