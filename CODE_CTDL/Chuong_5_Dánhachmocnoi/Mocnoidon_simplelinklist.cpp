#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho danh sach moc noi don
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}  // Constructor
};

// Lop LinkedList chua cac ham xu ly danh sach moc noi don
class LinkedList {
private:
    Node* head;

public:
    // Constructor: Khoi tao danh sach rong
    LinkedList() : head(NULL) {}

    // Them mot phan tu vao dau danh sach
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Them mot phan tu vao cuoi danh sach
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {  // Danh sach rong
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  // Nguoi cuoi cung tro den node moi
        }
    }

    // Loai bo mot nut ra khoi danh sach moc noi don
    void deleteNode(int value) {
        // Truong hop danh sach rong
        if (head == NULL) {
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Truong hop xoa nut dau tien
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Cap nhat head tro den nut tiep theo
            delete temp;         // Giai phong bo nho
            return;
        }

        // Duyet danh sach de tim nut can xoa
        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        // Neu khong tim thay nut can xoa
        if (current->next == NULL) {
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Truong hop xoa nut o giua hoac cuoi danh sach
        Node* temp = current->next;
        current->next = current->next->next;  // Cap nhat con tro cua nut truoc
        delete temp;                           // Giai phong bo nho
    }

    // In cac phan tu trong danh sach
    void display() const {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor: Giai phong bo nho cua cac node trong danh sach
    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Them phan tu vao dau va cuoi danh sach
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    // Hien thi danh sach
    cout<<"Danh sach ban dau: ";
    list.display();

    // Xoa phan tu
    list.deleteNode(20);
    cout<<"\nDanh sach sau khi xoa phan tu 20: ";
    list.display();

    // Xoa mot phan tu khong ton tai
    cout<<"\nXoa mot phan tu khong ton tai: ";
    list.deleteNode(40);

    // Hien thi danh sach sau khi xoa
    cout<<"\nDanh sach sau khi xoa: ";
    list.display();

    return 0;
}

