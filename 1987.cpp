#include <iostream>
#include <vector>
#include <utility>



using namespace std;

int main() {
    vector<int> point;
    vector<pair<pair<int, int>, int>> interwalls;
    vector<pair<pair<int, int>, int>> good_interwalls;
    vector<int> result;
    int n, m, dot, l, r, dot_index = 0, interwall_index = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        interwalls.push_back(make_pair(make_pair(l, r), i));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> dot;
        point.push_back(dot);
    }
    interwalls.push_back(make_pair(make_pair(1000000001, 1000000001), n));
    while (dot_index < m) {
        if (good_interwalls.size()) {
            if (point[dot_index] >= good_interwalls.back().first.first &&
                point[dot_index] <= good_interwalls.back().first.second) {
                if (point[dot_index] >= interwalls[interwall_index].first.first &&
                    point[dot_index] <= interwalls[interwall_index].first.second) {
                    good_interwalls.push_back(interwalls[interwall_index]);
                    interwall_index++;
                } else if (point[dot_index] < interwalls[interwall_index].first.first) {
                    result.push_back(good_interwalls.back().second);
                    dot_index++;
                } else
                    interwall_index++;
            } else good_interwalls.pop_back();
        } else {
            if (point[dot_index] >= interwalls[interwall_index].first.first &&
                point[dot_index] <= interwalls[interwall_index].first.second) {
                good_interwalls.push_back(interwalls[interwall_index]);
                interwall_index++;
            } else if (point[dot_index] < interwalls[interwall_index].first.first) {
                result.push_back(-1);
                dot_index++;
            } else
                interwall_index++;
        }

    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}