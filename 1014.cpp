#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int digits[9] = { 0 };

    if (!N) {
        cout << 10;
        return 0;
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    for (int i = 8; i > 0; i--) {
        while (N % (i + 1) == 0) {
            N /= (i + 1);
            digits[i]++;
        }
    }
    if (N == 1) {
        for (int i = 1; i <= 8; i++) {
            while (digits[i] != 0) {
                digits[i]--;
                cout << i + 1;
            }
        }
    }
    else
        cout << -1;
    return 0;
}
