#include <iostream>

class Queue {
private:
    int* QArray;    
    int QMax;       
    int QNumItems;  
    int QFront;    
    int QRear;    

public:
    Queue(int size) {
        QArray = new int[size];
        QMax = size;
        QFront = QRear = -1; // Queue rong
        QNumItems = 0;
    }

    ~Queue() {
        delete[] QArray;
    }

    // Kiem tra queue rong
    bool isEmpty() const {
        return (QNumItems == 0);
    }

    // Kiem tra queue day
    bool isFull() const {
        return (QNumItems == QMax);
    }

    // Them phan tu vao cuoi queue
    bool append(int newItem) {
        if (isFull()) return false; 
        if (QFront == -1) QFront = 0; 
        QRear = (QRear + 1) % QMax;   
        QArray[QRear] = newItem;     
        QNumItems++;
        return true; 
    }

    // Lay ra mot phan tu o queue
    bool take(int &itemOut) {
        if (isEmpty()) return false; 
        itemOut = QArray[QFront];    
        QFront = (QFront + 1) % QMax; 
        QNumItems--;
        if (QNumItems == 0) {       
            QFront = QRear = -1;
        }
        return true; // Lay thanh cong
    }

    // Hien thi cac phan tu trong queue
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue rong!" << std::endl;
            return;
        }
        std::cout << "Cac phan tu trong queue: ";
        int i = QFront;
        for (int count = 0; count < QNumItems; count++) {
            std::cout << QArray[i] << " ";
            i = (i + 1) % QMax;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Tao mot queue voi kich thuoc 5
    Queue queue(5);

    // Them cac phan tu vao queue
    queue.append(10);
    queue.append(20);
    queue.append(30);

    // Hien thi cac phan tu trong queue
    queue.display();

    int item;
    // Lay phan tu ra khoi queue va hien thi lai
    if (queue.take(item)) {
        std::cout << "Phan tu lay ra tu queue: " << item << std::endl;
    } else {
        std::cout << "Queue rong!" << std::endl;
    }

    // Hien thi lai cac phan tu trong queue sau khi da lay
    queue.display();

    return 0;
}

