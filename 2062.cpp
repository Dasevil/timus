#include <iostream>
#include <vector>

#define MAX 300000
// заранее хочу сказать что операция i&(-i) Дает первый значащий бит числа i
using namespace std;

long long Fenwick_Tree[MAX + 1]; // значения смещений
int Start_value[MAX + 1]; // стартовые значения
int n; // ну типа количество частиц
vector<int> Divisors[MAX + 1]; // вектор делителей, т.е divisors[6]={1,2,3,6}

long long Divisors_sum(int i); // сумма делителей числа

void Update(int l, int r, long long d); // добавление значений сигналов в промежуток

void addToSuffix(int left, long long bias); // прибавить ко всем начиная с left до n bias

int main() {
    int q, tmp = 0, opt, l, r, d, i; // кол-во запросов,переменная тупо для ввода, опция (1 или 2) , левая правая граница и значение сигнала и итератор
    cin >> n; // вводим количество частиц
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * i <= n; j++)
            Divisors[i * j].push_back(i); // цикл для заполнения делителей всех чисел от 1 до n


    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        Start_value[i] = tmp; // ввод стартовых значений
    }

    cin >> q; // пошли запросы
    while (q--) {
        cin >> opt;
        if (opt == 1) { // если мы выводим значение частицы то:
            cin >> i;
            long long result = Start_value[i]; // тут будет ответ на запрос типа 1
            for (auto d: Divisors[i]) // по каждому делителю
                result += Divisors_sum(d); // суммируем значения смещений, т.е для 6-рки например мы будем пробегать Divisors_sum по 1 2 3 6
            cout << result << "\n";
        } else { // если нам надо послать сигнал с l по r значения d
            cin >> l >> r >> d;
            Update(l, r, d); // функция для обновления значений смещений
        }
    }
    return 0;
}

long long Divisors_sum(int i) {
    long long sum = 0;
    while (i > 0) // для всех [0;i] (на самом деле не для всех т.к дерево фенвика)
        sum += Fenwick_Tree[i], i -= i & -i; // тупо суммируем значения смещений в делителях
    return sum; // выкидываем это значение суммы всех смещений
}

void addToSuffix(int left, long long bias) {
    while (left <= n) { // для всех [left;n](не совсем для всех) прибавим вот это вот d которое в мейне
        Fenwick_Tree[left] += bias; // тупо прибавляем
        left += left & -left; // ебать ну тут дерево фенвика иди читай
    }
}


void Update(int l, int r, long long d) {
    addToSuffix(l, d); // добавляем с l до конца d
    addToSuffix(r + 1, -d); // фиксим то что прибавили с >r с помощью вычитания того же самого значения
}
