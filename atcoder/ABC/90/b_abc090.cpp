#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull powmod(ull  a,ull b, ull mod) {
  ull res=1;
  for(; b; b >>= 1){
    if(b & 1){
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}

bool check(string s){
  int h = 0;
  int t = s.length() - 1;
  while (h <= t){
    if (s[h] != s[t]){
      return false;
    }
    h++; t--;
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string a, b;
  cin >> a;
  cin >> b;

  int a_i = stoi(a);
  int b_i = stoi(b);
  int counter = 0;
  for(int i = a_i; i <= b_i; i ++){
    if (check(to_string(i))){
      counter ++;
    }
  }
  cout << counter << "\n";
}
