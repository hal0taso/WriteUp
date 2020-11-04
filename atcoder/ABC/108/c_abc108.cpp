#include <iostream>

using namespace std;
int main(){
    long long N, K;
    long long a, b, c;

    cin >> N >> K;

    long long cnt = 0;
    long long q;

    for (a = 1; a <= K; ++a){
        b = c = a;
        // cout << a << " " << b << " " << c << endl;
        if ((2 * (a + b + c)) % K == 0 && (a + b) % K == 0) {
            q = N/K;
            if (N % K >= a){
                ++q;
            }
            cnt += q;
            cnt += (q * (q - 1) * (q - 2));
            cnt += (q * (q - 1)) * 3;
            // cout << "(x, x, x) = " << q << endl;
            // cout << "(x1, x1, x2) = " << q * (q - 1) << endl;
            // cout << "(x1, x2, x3) = " << q * (q - 1) * (q - 2) << endl;

        }
    }
    cout << cnt;
}
