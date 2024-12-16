#include <iostream>
#include <string>
using namespace std;

// ����� CPU
class CPU {
private:
    string model;
    int cores;
    double frequency;

public:
    void inputData() {
        cout << "������� ������ CPU: ";
        cin >> model;
        cout << "������� ���������� ���� CPU: ";
        cin >> cores;
        cout << "������� ������� CPU (GHz): ";
        cin >> frequency;
    }

    void display() const {
        cout << "CPU: " << model << ", ����: " << cores << ", �������: " << frequency << " GHz" << endl;
    }
};

// ����� RAM
class RAM {
private:
    int size;
    string type;

public:
    void inputData() {
        cout << "������� ����� RAM (GB): ";
        cin >> size;
        cout << "������� ��� RAM (DDR): ";
        cin >> type;
    }

    void display() const {
        cout << "RAM: " << size << " GB, ���: " << type << endl;
    }
};

// ����� SSD
class SSD {
private:
    int capacity;
    int speed;

public:
    void inputData() {
        cout << "������� ����� SSD (GB): ";
        cin >> capacity;
        cout << "������� �������� SSD (MB/s): ";
        cin >> speed;
    }

    void display() const {
        cout << "SSD: " << capacity << " GB, ��������: " << speed << " MB/s" << endl;
    }
};

// ����� GPU
class GPU {
private:
    string model;
    int memory;

public:
    void inputData() {
        cout << "������� ������ GPU: ";
        cin >> model;
        cout << "������� ����� ������ GPU (GB): ";
        cin >> memory;
    }

    void display() const {
        cout << "GPU: " << model << ", ������: " << memory << " GB" << endl;
    }
};

// ����� Mouse
class Mouse {
private:
    string brand;
    int dpi;

public:
    void inputData() {
        cout << "������� ����� ����: ";
        cin >> brand;
        cout << "������� DPI ����: ";
        cin >> dpi;
    }

    void display() const {
        cout << "Mouse: " << brand << ", DPI: " << dpi << endl;
    }
};

// ����� Laptop
class Laptop {
private:
    CPU cpu;
    RAM ram;
    SSD ssd;
    GPU gpu;
    Mouse* mouse; // ��������� �� ���� (�����������)

public:
    Laptop() : mouse(nullptr) {}

    ~Laptop() {
        if (mouse) {
            delete mouse;
        }
    }

    void inputData() {
        cout << "������� ������ ��� ��������:" << endl;
        cpu.inputData();
        ram.inputData();
        ssd.inputData();
        gpu.inputData();

        char choice;
        cout << "�������� ���� � ��������? (�/�): ";
        cin >> choice;

        if (choice == '�' || choice == '�') {
            mouse = new Mouse();
            mouse->inputData();
        }
    }

    void display() const {
        cout << "\n������ � ��������:" << endl;
        cpu.display();
        ram.display();
        ssd.display();
        gpu.display();

        if (mouse) {
            mouse->display();
        }
        else {
            cout << "����: �� ����������" << endl;
        }
    }
};

// ������� �������
int main() {
    setlocale(LC_ALL, "ru"); // ��������� �������� ����� � ������� (c������ �� ���������� � �� � ������� � ����� ��� ��� ���������)

    Laptop laptop;
    laptop.inputData();
    laptop.display();

    return 0;
}
