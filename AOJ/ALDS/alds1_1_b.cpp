#include <iostream>
#include <vector>
using namespace std;

int gcd(unsigned int x, unsigned int y){
  int tmp;
  // must x >= y
  if(x < y){
    tmp = x; x = y;y = tmp;
  }

  while (y != 0){
    tmp = y;
    y = x % y;
    x = tmp;
  }
  return x;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  unsigned long long int x, y, d;
  cin >> x;
  cin >> y;

  d = gcd(x, y);

  cout << d << "\n";
}
