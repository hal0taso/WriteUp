#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  vector<ull> vc;
  while(1){
    ull x, y;
    cin >> x >> y;
    if ( x == 0 && y == 0 ) break;
    vc.push_back(x); vc.push_back(y);
  }

  for (size_t i = 0; i < vc.size()/2; i ++){
    if (vc[2 * i] > vc[2 * i + 1]){
      ull tmp;
      tmp = vc[2 * i];
      vc[2 * i] = vc[2 * i + 1];
      vc[2 * i + 1] = tmp;
    }
    cout << vc[2 * i] << " " << vc[2 * i + 1] << "\n";
  }
}
