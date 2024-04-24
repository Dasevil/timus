#include <iostream>
#include <vector>
#pragma comment(linker, "/STACK:64777216")
#define MAX 500001
using namespace std;

int N, l, Murdered;
vector<pair<int, int>> nodes[MAX];
int time_in[MAX], time_out[MAX], root_distance[MAX];
int binary_up[MAX][17];

int timer;


void DFS(int node, int parent, int Q);

bool parent(int a, int b);

int LCA(int a, int b);

int main() {
    vector<int> ans;
    cin >> N;
    l = 1;
    while ((1 << l) <= N)
        ++l;
    int u, v, w;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> w;
        nodes[u].push_back(make_pair(v, w));
        nodes[v].push_back(make_pair(u, w));
    }

    DFS(0,0,0);

    cin >> Murdered;
    int lca;
    for (int i = 0; i < Murdered; i++) {
        cin >> u >> v;
        lca = LCA(u, v);
        ans.push_back(root_distance[u] + root_distance[v] - 2 * root_distance[lca]);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    cout<<"\n\n\n"<<parent(0,4);
    return 0;
}

void DFS(int v, int parent = 0, int root_to_nood_len = 0) {
    int i, to;
    time_in[v] = timer++;
    binary_up[v][0] = parent;
    root_distance[v] = root_to_nood_len;
    for (i = 1; i <= l; i++) {
        binary_up[v][i] = binary_up[binary_up[v][i - 1]][i - 1];

    }
    for (i = 0; i < nodes[v].size(); i++) {
        to = nodes[v][i].first;
        if (parent != to) {
            DFS(to, v, root_to_nood_len + nodes[v][i].second);
        }
    }
    time_out[v] = timer++;
}

bool parent(int a, int b) {
    return time_in[a] <= time_in[b] && time_out[a] >= time_out[b];
}

int LCA(int a, int b) {
    if (parent(b, a)) return b;
    if (parent(a, b)) return a;
    for (int i = l; i >= 0; --i)
        if (!parent(binary_up[a][i], b))
            a = binary_up[a][i];
    return binary_up[a][0];
}