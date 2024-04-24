#include <iostream>

using namespace std;

int main() {
    float a0, a_last, summ = 0, c, i = 0;
    int N;
    cin >> N;
    cin >> a0;
    cin >> a_last;
    while (i <= N) {
        cin >> c;
        summ += (N - i) * c;
        i++;
    }
    printf("%.2f", (a_last + a0 * N - 2 * summ) / (N + 1));
    return 0;
}