#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct NOTE2 
{
    string Name; // Фамилия и инициалы
    string TELE; // Номер телефона
    string DATE; // Дата рождения в формате ГГГГ-ММ-ДД
};

// Функция для сравнения номеров телефонов
bool compare(const NOTE2& a, const NOTE2& b) 
{
    return a.TELE < b.TELE; // Сравниваем по номеру телефона
}

int main() 
{
    setlocale (LC_ALL, "Rus");

    NOTE2 BLOCK2[7]; // Массив из 7 элементов структуры NOTE2
    // Ввод данных
    for (int i = 0; i < 5; ++i) 
    {
        cout << "Введите данные о пяти людях: ";

        cout << "\n\nВведите фамилию и инициалы: ";
        getline(cin, BLOCK2[i].Name);
        cout << "Введите номер телефона: ";
        getline(cin, BLOCK2[i].TELE);
        cout << "Введите дату рождения (ГГГГ-ММ-ДД): ";
        getline(cin, BLOCK2[i].DATE);

    }

    // Сортировка по номеру телефона
    sort(BLOCK2, BLOCK2 + 7, compare);

    // Поиск информации по фамилии
    string searchName;
    cout << "Введите фамилию и инициалы для поиска: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto& note : BLOCK2) {
        if (note.Name == searchName) {
            cout << "Найден: " << note.Name << ", " << note.TELE << ", " << note.DATE << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Запись не найдена." << endl; // Сообщение, если запись не найдена
    }

    return 0;
}