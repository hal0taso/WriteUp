#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <string>

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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c[3];
  vector<string> str;
  for (int i = 0; i < 3; i ++){
    string s;
    cin >> s;
    str.push_back(s);
  }

  for (int i = 0; i < 3; i ++){
    for (int j = 0; j < 3; j ++){
      if (i == j){
        c[i] = str[i][j];
      }
    }
  }

  string res(c, end(c));
  cout << res << "\n";

}
