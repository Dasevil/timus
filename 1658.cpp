#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    int digit_max = 901, square_max = 8101, t, s1, s2; // 100*9 - максимум суммы цифр, а 9*9*100 - максимум суммы квадратов цифр

    vector<string> answer_vec; // Вектор ответа
    string current_answer; // Ответ

    cin >> t; // Количество запросов
    vector<vector<int> > lenght_of_current_answer(digit_max, vector<int>(square_max, -1)); // прямоугольная матрица 901 х 8101 заполненная -1
    lenght_of_current_answer[0][0] = 0; // длина текущего ответа в ячейке 0 0( т.е число 0 равна нулю)
    int count; // количество цифр в ответе
    for (int i = 1; i < digit_max; i++) { // пробегаем по всевозможным суммам цифр
        for (int j = 0; j < square_max; j++) { // пробегаем по всевозможным суммам квадратов цифр
            for (int digit = 1; digit <= 9; digit++) { // какие могут быть цифры? ну от 1 до 9-ти епта бля
                if (i >= digit && j >= digit * digit && lenght_of_current_answer[i - digit][j - digit * digit] != -1) { /* сначала мы заполним массив числами 1 2 3 4 ... 9
 * потом, т.к например lenght_of_current_answer[10 - 9][19 - 18] = lenght_of_current_answer[1][1] = 1 != -1 мы запишем туда уже не 1 а два, т.е потом мы заполним все числа вида dd, где d = 1...9
 * потом соответственно например lenght_of_current_answer[14-4][25-4*4] = lenght_of_current_answer[10][19] = 2 != -1 мы запишем сюда уже не 2 а 3, т.е мы последовательно заполняем все числа с количеством разрядов
 * 1,2,3,4...100
 */
                    count = lenght_of_current_answer[i - digit][j - digit * digit] + 1; // +1 отвечает за прибавление разряда к числу
                    if (count <= 100 && // по условию число должно быть не более чем 100-значным
                        (lenght_of_current_answer[i][j] == -1 || count <= lenght_of_current_answer[i][j])) // по сути условие работает для только что найденных чисел, мы им присваиваем длину count(либо если доселе мы его не находили, либо находили но более длинным путем)
                        lenght_of_current_answer[i][j] = count; // Присвоим ему правильную длину числа
                }
            }
        }
    }

    for (int i = 0; i < t; i++) {
        current_answer = "";
        cin >> s1 >> s2;
        if (s1 > 900 || s2 > 8100 || lenght_of_current_answer[s1][s2] == -1) // т.е если мы за 100 разрядов не нашли это число или его суммы больше максимальных то сразу говоирм что ответа нет
            current_answer = "No solution";
        else {
            while (s1 != 0 || s2 != 0) {
                for (int digit = 1; digit <= 9; digit++) {
                    if (s1 >= digit && s2 >= digit * digit &&
                        lenght_of_current_answer[s1 - digit][s2 - digit * digit] + 1 == // по сути мы раскручиваем обратно то что мы делали выше, просто ищем разложение этого числа
                        lenght_of_current_answer[s1][s2]) {
                        current_answer += to_string(digit); // т.к мы проходим от меньших к большим, мы гарантируем, что найденное число будет наименьшим!
                        s1 -= digit;
                        s2 -= digit * digit;
                        break;
                    }
                }
            }
        }
        answer_vec.push_back(current_answer);
    }
    for (int i = 0; i < answer_vec.size(); i++)
        cout << answer_vec[i] << "\n";  // выводим ответ

    return 0;
}