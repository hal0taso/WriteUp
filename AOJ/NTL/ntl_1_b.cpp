#include <iostream>
#include <array>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

array<ull, 3> ex_euclid(ull m, ull n) {
  ull a = m; ull b = n;
  ull x[3], y[3], q, tmp;
  x[0] = 1;
  x[1] = 0;
  y[0] = 0;
  y[1] = 1;
  
  while (b != 0){
    tmp = a;

    a = b; q = tmp / b; b = tmp % b;

    x[2] = x[0] - q * x[1];
    y[2] = y[0] - q * y[1];

    x[0] = x[1]; y[0] = y[1];
    x[1] = x[2]; y[1] = y[2];
  }
  return {a, x[0], y[0]};
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ull m, n;
  cin >> m;
  cin >> n;

  array<ull, 3> res;
  res = ex_euclid(m, n);
  
  cout << res[1] << " " << res[2] << "\n";
}
