#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho danh sach moc noi vong
struct Node {
    int data;
    Node* next;

    Node(int value = 0) : data(value), next(NULL) {}  // Constructor
};

// Ham them mot phan tu vao vi tri bat ky trong danh sach
void addElement(Node** head, int newData, int pos) {
    Node* newNode = new Node(newData);

    if (*head == NULL) {  // Danh sach rong
        *head = newNode;
        newNode->next = *head;
    } 
    else if (pos == 0) {  // Them vao dau danh sach
        Node* temp = *head;
        while (temp->next != *head) {  // Tim node cuoi cung
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    } 
    else {  // Them vao vi tri bat ky
        Node* temp = *head;
        for (int i = 1; i < pos && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Ham hien thi cac phan tu trong danh sach
void displayList(Node* head) {
    if (head == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* temp = head;
   // cout << "Danh sach: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Ham giai phong bo nho cua danh sach
void freeList(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* nextNode;
    do {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != *head);
    *head = NULL;
}

int main() {
    Node* head = NULL;

    // Them phan tu vao danh sach tai cac vi tri khac nhau
    addElement(&head, 10, 0);  // Them vao dau danh sach
    addElement(&head, 20, 1);  // Them vao vi tri 1
    addElement(&head, 5, 0);   // Them vao dau danh sach
    // Hien thi danh sach
    cout<<"Danh sach ban dau: ";
    displayList(head);
    cout<<"\nThem phan tu 15 vao vi tri 2 trong danh sach: ";
    addElement(&head, 15, 2);  // Them vao vi tri 2
	displayList(head);

    // Giai phong bo nho cua danh sach
    freeList(&head);

    return 0;
}

