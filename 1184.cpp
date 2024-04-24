#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, K, i = 0;
    double sum = 0;
    cin >> N >> K;
    vector<double> lenghts(N);
    while (i < N) {
        cin >> lenghts[i];
        sum += lenghts[i];
        i++;
    }
    sum /= K;
    double current_answer, e = 0;
    int count;
    while (sum - e > 0.001) {
        current_answer = (sum + e) / 2;
        count = 0;
        i = 0;
        while (i < N) {
            count += (int) (lenghts[i] / current_answer);
            i++;
        }
        if (count >= K) {
            e = current_answer;
        } else sum = current_answer;
    }
    printf("%.2f\n", floor(100*sum)/100);
    return 0;
}
