#include <iostream>
#include <vector>

using namespace std;

vector<int> left_max;
vector<int> right_max;

void RMQ_solve(const vector<int> data, int M);

int main() {
    vector<int> data;
    int M, tmp;
    cin >> M;
    while (1) {
        cin >> tmp;
        if (!(tmp + 1))
            break;
        data.push_back(tmp);
    }
    RMQ_solve(data, M);

    return 0;
}

void RMQ_solve(const vector<int> data, int M) {
    int n = data.size();
    left_max.resize(n);
    right_max.resize(n);
    left_max.front() = data.front();
    right_max.back() = data.back();
    M--;

    for (int i = 1, j = n - 2; i < n; i++, j--) {
        left_max[i] = (i % M) ? max(data[i], left_max[i - 1]) : data[i];
        right_max[j] = ((j + 1) % M) ? max(data[j], right_max[j + 1]) : data[j];
    }
    for (int i = 0; i < n - M; i++) {
        cout << max(right_max[i], left_max[i + M]) << endl;
    }
}