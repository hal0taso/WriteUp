#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int arr[3];
  for (int i = 0; i < 3; i ++){
    cin >> arr[i];
  }
  sort(arr, arr+3);

  for (int i = 0; i < 3; i ++){
    if (i == 2){
      cout << arr[i] << "\n";
    }else{
      cout << arr[i] << " ";
    }
  }

}
