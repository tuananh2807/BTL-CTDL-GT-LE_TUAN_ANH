#include <iostream>

class Cstack {
private:
    int* StkArr;    // Mang chua cac phan tu cua stack
    int StkTop;     // Vi tri cua phan tu tren cung
    int StkMax;     // Kich thuoc toi da cua stack

public:
    // Constructor: Khoi tao stack voi kich thuoc cho truoc
    Cstack(int size) {
        StkArr = new int[size];
        StkMax = size;
        StkTop = -1;
    }

    // Destructor: Giai phong bo nho
    ~Cstack() {
        delete[] StkArr;
    }

    // Kiem tra stack rong
    bool isEmpty() const {
        return (StkTop == -1);
    }

    // Kiem tra stack day
    bool isFull() const {
        return (StkTop == StkMax - 1);
    }

    // Them phan tu vao stack
    bool Push(int item) {
        if (isFull()) return false; // Stack day, khong the them
        StkArr[++StkTop] = item;
        return true;
    }

    // Lay mot phan tu ra tu dinh stack
    bool Pop(int &outitem) {
        if (isEmpty()) return false; // Stack rong, khong the lay ra
        outitem = StkArr[StkTop--];
        return true;
    }

    // Hien thi cac phan tu trong stack
    void Display() const {
        if (isEmpty()) {
            std::cout << "Stack rong!" << std::endl;
            return;
        }
        std::cout << "Cac phan tu trong stack: ";
        for (int i = 0; i <= StkTop; ++i) {
            std::cout << StkArr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Tao mot stack voi kich thuoc 5
    Cstack stack(5);

    // Them cac phan tu vao stack
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
	stack.Push(40);
	stack.Push(50);
    // Hien thi cac phan tu trong stack
    stack.Display();

    int item;
    // Lay phan tu ra khoi stack va hien thi lai
    if (stack.Pop(item)) {
        std::cout << "Phan tu lay ra tu stack: " << item << std::endl;
    } else {
        std::cout << "Stack rong!" << std::endl;
    }

    // Hien thi lai cac phan tu trong stack sau khi da Pop
    stack.Display();

    return 0;
}

