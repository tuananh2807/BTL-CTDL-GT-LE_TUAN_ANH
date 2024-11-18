#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}  // Constructor
};

// Duyet cay theo thu tu truoc (Preorder)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";  // In ra node hien tai
        preorder(root->left);       // Duyet con ben trai
        preorder(root->right);      // Duyet con ben phai
    }
}

// Duyet cay theo thu tu sau (Postorder)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Duyet con ben trai
        postorder(root->right);    // Duyet con ben phai
        cout << root->data << " "; // In ra node hien tai
    }
}

// Duyet cay theo thu tu giua (Inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);      // Duyet con ben trai
        cout << root->data << " "; // In ra node hien tai
        inorder(root->right);     // Duyet con ben phai
    }
}

// Ham them mot phan tu vao cay (dung de xay dung cay)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);  // Neu cay rong, tao node moi
    }

    if (value < root->data) {
        root->left = insert(root->left, value);  // Them vao ben trai
    } else {
        root->right = insert(root->right, value);  // Them vao ben phai
    }
    return root;
}

int main() {
    Node* root = NULL;

    // Xay dung cay nhi phan
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Duyet cay theo thu tu truoc
    cout << "Duyet cay theo thu tu truoc (Preorder): ";
    preorder(root);
    cout << endl;

    // Duyet cay theo thu tu sau
    cout << "Duyet cay theo thu tu sau (Postorder): ";
    postorder(root);
    cout << endl;

    // Duyet cay theo thu tu giua
    cout << "Duyet cay theo thu tu giua (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}

