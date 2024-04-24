#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;
    N++;
    vector<unsigned int> answer(N, 4);
    answer[0] = 0;
    for (int j = 1; j < N; j++) {
        for (int i = 1; i * i <= j; ++i)
            answer[j] = min(1 + answer[j - i * i], answer[j]);
    }
    cout << answer[answer.size() - 1];

    return 0;
}