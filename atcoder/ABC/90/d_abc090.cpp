#include <iostream>
#include <random>
#include <vector>
#include <array>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ll n, k;

  cin >> n >> k;
  ll c = 0;

  if (k == 0){
    c = n * n;
    cout << c << "\n";
  } else {
    for (int b = k + 1; b <= n; b++){
      c += (n / b) * (b - k);
      if (n % b >= k){
        c += (n % b) - (k - 1);
      }
    }
    cout << c << "\n";
  }
}
