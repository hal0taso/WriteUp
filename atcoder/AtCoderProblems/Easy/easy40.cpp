#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main() {
  int a, b;
  cin >> a >> b;
  if (a > 0) {
    puts("Positive");
  } else if (a <= 0 && b >= 0) {
    puts("Zero");
  } else {
    if ((a - b) % 2 == 0) {
      puts("Negative");
    } else {
      puts("Positive");
    }
  }
  return 0;
}
