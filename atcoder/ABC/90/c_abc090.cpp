#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ull m, n;
  cin >> n;
  cin >> m;
  ull res;
  if (n > 1 && m > 1){
    res = (m - 2) * (n - 2);
  }else if (n == 1 || m == 1){
    res = m*n - 2;
  }
  if (n == 1 && m == 1){
    res = 1;
  }
  cout << res << "\n";
}
