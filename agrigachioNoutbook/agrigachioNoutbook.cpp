#include <iostream>
#include <string>
using namespace std;

// Класс CPU
class CPU {
private:
    string model;
    int cores;
    double frequency;

public:
    void inputData() {
        cout << "Введите модель CPU: ";
        cin >> model;
        cout << "Введите количество ядер CPU: ";
        cin >> cores;
        cout << "Введите частоту CPU (GHz): ";
        cin >> frequency;
    }

    void display() const {
        cout << "CPU: " << model << ", Ядра: " << cores << ", Частота: " << frequency << " GHz" << endl;
    }
};

// Класс RAM
class RAM {
private:
    int size;
    string type;

public:
    void inputData() {
        cout << "Введите объем RAM (GB): ";
        cin >> size;
        cout << "Введите тип RAM (DDR): ";
        cin >> type;
    }

    void display() const {
        cout << "RAM: " << size << " GB, Тип: " << type << endl;
    }
};

// Класс SSD
class SSD {
private:
    int capacity;
    int speed;

public:
    void inputData() {
        cout << "Введите объем SSD (GB): ";
        cin >> capacity;
        cout << "Введите скорость SSD (MB/s): ";
        cin >> speed;
    }

    void display() const {
        cout << "SSD: " << capacity << " GB, Скорость: " << speed << " MB/s" << endl;
    }
};

// Класс GPU
class GPU {
private:
    string model;
    int memory;

public:
    void inputData() {
        cout << "Введите модель GPU: ";
        cin >> model;
        cout << "Введите объем памяти GPU (GB): ";
        cin >> memory;
    }

    void display() const {
        cout << "GPU: " << model << ", Память: " << memory << " GB" << endl;
    }
};

// Класс Mouse
class Mouse {
private:
    string brand;
    int dpi;

public:
    void inputData() {
        cout << "Введите марку мыши: ";
        cin >> brand;
        cout << "Введите DPI мыши: ";
        cin >> dpi;
    }

    void display() const {
        cout << "Mouse: " << brand << ", DPI: " << dpi << endl;
    }
};

// Класс Laptop
class Laptop {
private:
    CPU cpu;
    RAM ram;
    SSD ssd;
    GPU gpu;
    Mouse* mouse; // Указатель на мышь (опционально)

public:
    Laptop() : mouse(nullptr) {}

    ~Laptop() {
        if (mouse) {
            delete mouse;
        }
    }

    void inputData() {
        cout << "Введите данные для ноутбука:" << endl;
        cpu.inputData();
        ram.inputData();
        ssd.inputData();
        gpu.inputData();

        char choice;
        cout << "Добавить мышь к ноутбуку? (д/н): ";
        cin >> choice;

        if (choice == 'д' || choice == 'Д') {
            mouse = new Mouse();
            mouse->inputData();
        }
    }

    void display() const {
        cout << "\nДанные о ноутбуке:" << endl;
        cpu.display();
        ram.display();
        ssd.display();
        gpu.display();

        if (mouse) {
            mouse->display();
        }
        else {
            cout << "Мышь: не подключена" << endl;
        }
    }
};

// Главная функция
int main() {
    setlocale(LC_ALL, "ru"); // Установка русского языка в консоли (cпасибо за примерчики а то я мучался и искал как это делаеться)

    Laptop laptop;
    laptop.inputData();
    laptop.display();

    return 0;
}
