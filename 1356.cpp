#include <iostream>
#include <vector>

using namespace std;

inline bool Test_on_prime(int N) {
    if (N == 1)
        return false;
    for (int i = 2; i * i <= N; i++)
        if (N % i == 0)
            return false;
    return true;
}

int main() {
    int N, T;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N < 4 || Test_on_prime(N))
            cout << N << "\n";
        else if (N % 2 == 0) {
            if (Test_on_prime(N - 2))
                cout << "2 " << N - 2 << "\n";
            else {
                for (int odd = 3;; odd += 2) {
                    if (Test_on_prime(odd) && Test_on_prime(N - odd)) {
                        cout << odd << " " << N - odd << "\n";
                        break;
                    }
                }
            }
        } else {
            if (Test_on_prime(N - 2))
                cout << "2 " << N - 2 << "\n";
            else {
                N -= 3;
                for (int k = N - 3;; k -= 2) {
                    if (Test_on_prime(k) && Test_on_prime(N - k)) {
                        cout << "3 " << k << " " << N - k << "\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}