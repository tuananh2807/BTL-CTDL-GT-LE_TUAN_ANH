#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho danh sach moc noi kep
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(NULL), prev(NULL) {}  
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    // Them mot phan tu vao dau danh sach
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  // Danh sach rong
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Them mot phan tu vao cuoi danh sach
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == NULL) {  // Danh sach rong
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Loai bo mot phan tu ra khoi danh sach
    void deleteNode(int value) {
        if (head == NULL) return;  // Danh sach rong

        Node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Khong tim thay phan tu " << value << " trong danh sach!" << endl;
            return;
        }

        // Truong hop xoa phan tu dau tien
        if (temp == head) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        }
        // Truong hop xoa phan tu cuoi cung
        else if (temp == tail) {
            tail = temp->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
        }
        // Truong hop xoa phan tu o giua danh sach
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;  
    }

    // Hien thi cac phan tu trong danh sach tu dau den cuoi
    void displayForward() const {
        Node* temp = head;
      //  cout << "Danh sach tu dau den cuoi: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
/*
    // Hien thi cac phan tu trong danh sach tu cuoi len dau
    void displayBackward() const {
        Node* temp = tail;
        cout << "Danh sach tu cuoi len dau: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
*/
    // Destructor: Giai phong bo nho cua cac node trong danh sach
    ~DoublyLinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;

    // Them phan tu vao dau va cuoi danh sach
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    // Hien thi danh sach tu dau den cuoi va tu cuoi len dau
    cout<<"Danh sach ban dau: ";
    list.displayForward();
  //  list.displayBackward();

    // Xoa phan tu
    cout<<"\nXoa phan tu 20, danh sach sau khi xoa: ";
    list.deleteNode(20);
    list.displayForward();

    // Xoa mot phan tu khong ton tai
    cout<<"\nXoa mot phan tu khong ton tai trong danh sach: ";
    list.deleteNode(40);

    // Hien thi danh sach sau khi xoa
    //list.displayForward();

    return 0;
}

