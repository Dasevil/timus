#include <iostream>
#include <cstdlib>

using namespace std;

int Tree_village[1001][1001] = {0};
char Murdered[1001] = {0};
int N;

void DFS_up(int p) {
    int i;
    if (Murdered[p] == 1)
        return;
    Murdered[p] = 1;
    for (i = 1; i <= N; i++) {
        if (Tree_village[i][p] == 1)
            DFS_up(i);
    }
}

void DFS_down(int p) {
    int i;
    if (Murdered[p] == 1)
        return;
    Murdered[p] = 1;
    for (i = 1; i <= N; i++) {
        if (Tree_village[i][p] == -1)
            DFS_down(i);
    }
}

int main() {
    char input[8];
    int i, parent, child;
    cin >> N;
    while (1) {
        cin >> input;
        if (input[0] == 'B')
            break;
        parent = atoi(input);
        cin >> child;
        Tree_village[parent][child] = 1;
        Tree_village[child][parent] = -1;
    }
    while (scanf("%d", &parent) != EOF) {
        DFS_up(parent);
        Murdered[parent] = 0;
        DFS_down(parent);
    }
    parent = -1;
    for (i = 1; i <= N; i++) {
        if (Murdered[i] == 0) {
            parent = i;
            cout << parent << " ";
        }
    }
    if (parent == -1)
        cout << 0;
}
