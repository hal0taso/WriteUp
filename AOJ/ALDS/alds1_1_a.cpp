#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> A, int N){
  for (int i = 0; i < N; i ++){
    if(i == N - 1){
      cout << A[i] << "\n";
    }else{
      cout << A[i] << " ";
    }
  }
}

void insertionSort(vector<int> A, int N){
  for (int i = 1; i <= N - 1; i ++){
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    printVec(A, N);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> vc;
  int n;
  cin >> n;
  while (n--){
    int x;
    cin >> x;
    vc.push_back(x);
  }
  printVec(vc, vc.size());
  insertionSort(vc, vc.size());
}

