#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool some_sort(pair<int, int> first, pair<int, int> second){
    if (first.second != second.second){
        return first.second < second.second; // очевидно что при сравнении вторых компонент возвращаем естественный порядок
    }
    if (first.second == second.second){ 
        return first.first < second.first; // при равенстве чисел упорядочиваем индексы(первые компоненты)
    }
}

int main(){
    int n, l, r, x, number_of_iteration;
    cin >> n;
    vector<pair<int, int>> a;
    vector<pair<int, int>>::iterator lower, upper;
    int i = 1;
    while(i <= n){
        int count;
        cin >> count;
        pair<int, int> index = make_pair(i, count);
        a.push_back(index);
        i++;
    }
    sort(a.begin(), a.end(),some_sort);
    cin >> number_of_iteration;
    i = 0;
    while(i < number_of_iteration){
        cin >> l >> r >> x;
        lower = lower_bound(a.begin(), a.end(), make_pair(l, x), some_sort);
        upper = upper_bound(a.begin(), a.end(), make_pair(r, x), some_sort);
        if (upper != lower){
            cout << 1;
        }
        else{
            cout << 0;
        }
        i++;
    }
    return 0;
}
