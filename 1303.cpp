#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_by_start(pair<int, int> &one, pair<int, int> &two);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<pair<int, int>> segments;
    vector<pair<int, int>> result;
    pair<int, int> current_segment;
    int start, end, previous_start = 0, max_end = 0, M, i = 0;
    cin >> M;
    while (1) {
        cin >> start >> end;
        if (start == 0 && end == 0) {
            break;
        } else {
            segments.emplace_back(start, end);
        }
    }
    current_segment = segments[0];
    sort(segments.begin(), segments.end(), sort_by_start);
    while (i < segments.size()) {
        if (segments[i].first > previous_start) {
            if (segments[i].first > max_end) {
                break;
            }
            result.emplace_back(current_segment);
            previous_start = max_end;
        }
        if (segments[i].second > max_end) {
            max_end = segments[i].second;
            current_segment = segments[i];
            if (max_end >= M) {
                result.emplace_back(current_segment);
                break;
            }
        }
        i++;
    }
    if (max_end < M)
        cout << "No solution\n";
    else {
        cout << result.size() << '\n';
        i = 0;
        while (i < result.size()) {
            cout << result[i].first << " " << result[i].second << '\n';
            i++;
        }
    }
    return 0;
}


bool sort_by_start(pair<int, int> &one, pair<int, int> &two) {
    if (one.first == two.first) {
        return (one.second < two.second);
    }
    if (one.first != two.first) {
        return (one.first < two.first);
    }
}
