#include <iostream>
#include <vector>

using namespace std;

int main() {
    short N, K;
    cin >> N >> K;
    K--;
    N++;
    vector<long long> res = {0,K};
    while ((N--) - 1)
        res.push_back(K * (res[res.size() - 1] + res[res.size() - 2]));
    cout << res[res.size()-1] / K;
    return 0;
}