#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
int compare_start_segment(pair<int, int>one, pair<int, int>two);
int compare_end_segment(pair<int, int>one, pair<int, int>two);


int main(){

    int n, start_seg, end_seg, i = 0;
    cin >> n;
    vector <pair<int, int>> segments;
    vector <pair<int, int>> result;

    while(i < n){
        cin >> start_seg;
        cin >> end_seg;
        segments.push_back(make_pair(start_seg, end_seg));
        i++;
    }

    sort(segments.begin(), segments.end(), compare_end_segment);
    result.push_back(segments[0]);
    i = 0;
    while(i < n){
        if(segments[i].first >= result[result.size() - 1].second){
            result.push_back(segments[i]);
        }
        i++;
    }
   // sort(result.begin(), result.end(), compare_start_segment);
    cout << result.size() << endl;
    i = 0;
    while(i < result.size()){
        cout << result[i].first<< ' '<< result[i].second<<endl;
        i++;
    }

    return 0;
}

int compare_start_segment(pair<int, int>one, pair<int, int>two){
    if(one.first != two.first){
        return (one.first < two.first);
    }
    if(one.first == two.first) {
        return (one.second < two.second);
    }
}

int compare_end_segment(pair<int, int>one, pair<int, int>two){
    if(one.second != two.second){
        return (one.second < two.second);
    }
    if(one.second == two.second) {
        return (one.first < two.first);
    }
}