#include <iostream>
#include <string>
using namespace std;

//имя класса
class Com_Device {//поля класса
private:
    string manufacturer;
    int processing;

public://конструктор
    Com_Device(string manufacturer, int processing) {
        this-> manufacturer = manufacturer;//оператор доступа к членам класса. спользуется для обращения к членам класса через указатель на объект
        this-> processing = processing;
    }
    //метод для изменения производителя
    void set_Man(string manufacturer) {
        this-> manufacturer = manufacturer;
    }
    //метод для изменения задержки
    void set_Proc(int processing) {
        this-> processing = processing;
    }
    //метод для получения значения производитель
    string get_Man() {
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
    Com_Device device("Samsung", 10);
    cout << "Текущие значения:" << endl;
    device.display();

    //сохраняем старые значения
    string old_Man = device.get_Man();
    int old_Proc = device.get_Proc();

    cout << endl << "Введите новое название производителя: ";
    string new_Man;
    cin >> new_Man;
    device.set_Man(new_Man);

    cout << "Введите новую задержку обработки(ms): ";
    int new_Proc;
    cin >> new_Proc;
    device.set_Proc(new_Proc);

    //выводим старые и новые значения
    cout << endl << "Старые значения:" << endl;
    cout << "Производитель: " << old_Man << endl;
    cout << "Задержка обработки: " << old_Proc << " ms" << endl;

    cout << endl << "Обновленные значения:" << endl;
    device.display();

    return 0;
}
