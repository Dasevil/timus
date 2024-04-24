#include <iostream>
#include <string>

using namespace std;
string chess_board[8][8] = {
        {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8"},
        {"b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8"},
        {"c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8"},
        {"d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8"},
        {"e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8"},
        {"f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8"},
        {"g1", "g2", "g3", "g4", "g5", "g6", "g7", "g8"},
        {"h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8"},
};

int Steps(int x, int y, int **A, const int M);

int printChess(int **A, const int M);

int horse_step[8][2];

int main() {
    int M;

    int x = 0, y = 0, count = 1, step_id = 0;
    int steps[8];
    horse_step[0][0] = 2;
    horse_step[0][1] = 1;

    horse_step[1][0] = 2;
    horse_step[1][1] = -1;

    horse_step[2][0] = 1;
    horse_step[2][1] = 2;

    horse_step[3][0] = 1;
    horse_step[3][1] = -2;

    horse_step[4][0] = -1;
    horse_step[4][1] = 2;

    horse_step[5][0] = -1;
    horse_step[5][1] = -2;

    horse_step[6][0] = -2;
    horse_step[6][1] = 1;

    horse_step[7][0] = -2;
    horse_step[7][1] = -1;
    cin >> M;
    int **A = new int *[M];
    if (M > 8 || M < 1) {
        return 0;
    }
    for (int i = 0; i < M; i++) {
        A[i] = new int[M];
    }


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = 0;
        }
    }
    A[x][y] = count;
    while (true) {
        for (int k = 0; k < 8; k++) {
            steps[k] = Steps(x + horse_step[k][0], y + horse_step[k][1], A, M);
        }
        for (int k = 0; k < 8; k++) {
            if (steps[k] > 0) {
                step_id = k;
                break;
            }
            if (k == 7) {
                for (int i = 0; i < 8; i++) {
                    if (steps[i] == 0) {
                        A[x + horse_step[i][0]][y + horse_step[i][1]] = ++count;
                    }
                }
                printChess(A, M);
                for (int i = 0; i < M; i++) {
                    delete[] A[i];
                }
                return 0;
            }
        }
        for (int k = 0; k < 8; k++) {
            if (steps[k] < steps[step_id] && steps[k] > 0) {
                step_id = k;
            }
        }

        x += horse_step[step_id][0];
        y += horse_step[step_id][1];
        A[x][y] = ++count;

    }
}

int Steps(int x, int y, int **A, const int M) {
    if ((x < 0 || x >= M || y < 0 || y >= M || A[x][y] != 0)) {
        return -1;
    }
    int count = 0;
    for (int k = 0; k < 8; k++) {
        int xn = x + horse_step[k][0];
        int yn = y + horse_step[k][1];
        if (xn >= 0 && xn < M && yn >= 0 && yn < M && A[xn][yn] == 0) {
            count++;
        }
    }
    return count;
}

int printChess(int **A, const int M) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (!A[i][j]) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int k = 1; k <= M * M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] == k)
                    cout << chess_board[i][j] << endl;
            }
        }
    }
    return 0;
}