#include <iostream>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int i;
  int counter = 1;
  while (1){
    cin >> i;
    if (i == 0) {
      break;
    } else {
      cout << "Case " << counter << ": " << i << "\n";
    }
    counter ++;
  }
}
