#include <iostream>
#include <vector>
#include <algorithm> //для функции sort
#include <string>
using namespace std;

//имя класса
class Com_Device {//поля класса
private:
    string manufacturer;
    int processing;

public://конструктор
    Com_Device(string manufacturer, int processing) {
        this->manufacturer = manufacturer;//оператор доступа к членам класса. используется для обращения к членам класса через указатель на объект
        this->processing = processing;
    }
    //метод для изменения производителя
    void set_Man(string manufacturer) {
        this->manufacturer = manufacturer;
    }
    //метод для изменения задержки
    void set_Proc(int processing) {
        this->processing = processing;
    }
    //метод для получения значения производитель
    string get_Man() const {
    return manufacturer;
}
    //метод для получения значения задержки
    int get_Proc() {
        return processing;
    }
    //вывод информации
    void display() {
        cout << "Производитель: " << manufacturer << endl;
        cout << "Задержка обработки: " << processing << " ms" << endl;
    }
};

int main() {
    int n; //размерность векторов
    cout << "Введите размерность векторов: ";
    cin >> n;

    vector<Com_Device> vec1; //исходный вектор
    vector<Com_Device> vec2; //новый вектор

    //заполнение исходного вектора
    for (int i = 0; i < n; i++) {
        string man;
        int proc;
        cout << "Введите производителя и задержку обработки для устройства " << i + 1 << ":" << endl;
        cin >> man >> proc;
        vec1.push_back(Com_Device(man, proc));
    }

    //заполнение нового вектора (переписываем только устройства с задержкой менее 5 мс)
    for (int i = 0; i < n; i++) {
        if (vec1[i].get_Proc() <= 5) {
            vec2.push_back(vec1[i]);
        }
    }

    //проверка на пустоту нового вектора
    if (vec2.empty()) {
        cout << "Новый вектор пуст" << endl;
    }
    else {
        //сортировка нового вектора по производителю
        sort(vec2.begin(), vec2.end(), [](const Com_Device& a, const Com_Device& b) {
            return a.get_Man() < b.get_Man();
        });

        //вывод нового вектора
        cout << "Новый вектор:" << endl;
        for (int i = 0; i < vec2.size(); i++) {
            vec2[i].display();
            cout << endl;
        }
    }

    return 0;
}
