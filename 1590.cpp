#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    unsigned long long answer = 1;
    int lenght = 1;
    int max_z_for_current_s = -1;
    string current_s;
    current_s.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        current_s.push_back(s[i]);
        lenght += 1;

        reverse(current_s.begin(), current_s.end());
        vector<int> current_z = z_function(current_s);
        reverse(current_s.begin(), current_s.end());

        max_z_for_current_s = -1;
        for (int j = 0; j < current_z.size(); j++) {
            if (current_z[j] > max_z_for_current_s)
                max_z_for_current_s = current_z[j];
        }
        answer += lenght - max_z_for_current_s;

    }
    cout << answer;
    return 0;
}