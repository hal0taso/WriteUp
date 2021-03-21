#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int h, w, i, j;
  string s;
  cin >> h >> w;
  char a[h + 2][w + 2];
  for (i = 0; i < h + 2; ++i) {
    a[i][0] = '#';
    a[i][w + 1] = '#';
  }
  for (i = 0; i < w + 2; ++i) {
    a[0][i] = '#';
    a[h + 1][i] = '#';
  }
  for (i = 0; i < h; ++i) {
    cin >> s;
    for (j = 0; j < w; ++j) {
      a[i + 1][j + 1] = s[j];
    }
  }
  for (i = 0; i < h + 2; ++i) {
    for (j = 0; j < w + 2; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
