#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> Balls;
    int N, ball_number, max = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ball_number;
        if (ball_number > max) {
            for (int j = max + 1; j < ball_number; j++)
                Balls.push(j);
            max = ball_number;
        } else {
            if (ball_number == Balls.top()) {
                Balls.pop();
            } else {
                cout << "Cheater";
                return 0;
            }
        }
    }
    cout << "Not a proof";
    return 0;
}
