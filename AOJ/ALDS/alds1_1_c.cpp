#include <iostream>
#include <random>
#include <vector>

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

bool MillerRabin(ull n, ull k){
  if (n == 2){
    return true;
  }
  if (n == 1 || (n & 1) == 0){
    return false;
  }

  random_device rd;
  mt19937 rand_src(rd());
  uniform_int_distribution<ull> rand_dist(1, n - 1);

  ull d = n - 1;
  while ((d & 1) == 0){
    d >>= 1;
  }
  while(k--){
    ull a = rand_dist(rand_src);
    ull t = d;
    ull y = powmod(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1){
      y = (y * y) % n;
      t <<= 1;
    }
    if (y != n - 1 && (t & 1) == 0){
      return false;
    }
  }
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  vector<ull> vc;
  int c = 0;
  cin >> n;
  while(n--){
    ull x;
    cin >> x;
    vc.push_back(x);
  }

  for (size_t i = 0; i < vc.size(); i++){
    if (MillerRabin(vc[i], 20)){
        c ++;
    }
  }
  cout << c << "\n";
}
