#include <iostream>
#include <vector>

using namespace std;
int N, Murdered;
vector<int> k(50);
vector<bool> winner(10001, false);

int main() {
    winner[0] = true;
    cin >> N >> Murdered;
    for (int i = 0; i < Murdered; i++)
        cin >> k[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < Murdered; j++)
            if (i >= k[j] && !winner[i - k[j]]) {
                winner[i] = true;
                break;
            }
    cout << 2 - winner[N];
    return 0;
}
