#include <iostream>
using namespace std;

bool is_prime (int x){
  for (int i = 2; i*i < x; i++){
    if (x % i == 0){
      return false;
    }
  }
  return true;
}

int main() {
  int x;
  cin >> x;
  if ((x > 2) && !(x & 1)){
    x += 1;
  }
  while(!is_prime(x)){
    x += 2;
  }
  cout << x << endl;
  return 0;
}
