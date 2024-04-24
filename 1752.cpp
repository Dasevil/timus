#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:64777216")
#define max 100001
using namespace std;

vector<pair<int, int>> request[max];
vector<int> Tree[max];
int depth[max], onLenght[max], answer[max];

void DFS(int u, int v) {
    int i;
    for (i = 0; i < Tree[u].size(); i++) {
        int p = Tree[u][i];
        if (p == v) continue;
        else {
            depth[p] = depth[u] + 1;
            DFS(p, u);
        }
    }
}

void stillDFS(int u, int v, int dist) {
    onLenght[dist] = u;
    int i;
    while (request[u].size()) {
        int p = request[u].back().first;
        if (p > dist) {
            break;
        }
        int q = request[u].back().second;
        answer[q] = onLenght[dist - p];
        request[u].pop_back();
    }
    for (i = 0; i < Tree[u].size(); i++) {
        int p = Tree[u][i];
        if (p == v) continue;
        stillDFS(p, u, dist + 1);
    }
}


int main() {
    int n, q, i, u, v;
    cin >> n >> q;
    for (i = 1; i < n; i++) {
        cin >> u >> v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }

    for (i = 1; i <= q; i++) {
        int c, distance;
        cin >> c >> distance;
        request[c].emplace_back(distance, i);
    }


    for (i = 1; i <= n; i++)
        sort(request[i].rbegin(), request[i].rend());


    int maxOfDepth = -1, DeepestNode = 1, f = 1;
    DFS(1, 0);
    for (i = 1; i <= n; i++) {
        if (depth[i] > maxOfDepth) {
            maxOfDepth = depth[i];
            DeepestNode = i;
        }
    }
    depth[DeepestNode] = 0;
    maxOfDepth = -1;
    DFS(DeepestNode, -1);
    for (i = 1; i <= n; i++) {
        if (depth[i] > maxOfDepth) {
            maxOfDepth = depth[i];
            f = i;
        }
    }

    stillDFS(DeepestNode, -1, 0);
    stillDFS(f, -1, 0);

    for (i = 1; i <= q; i++)
        cout << answer[i] << endl;

    return 0;
}