#include <iostream>

using namespace std;

// Dinh nghia cau truc Node cho cay nhi phan tim kiem
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}  // Constructor
};

// Ham them mot phan tu vao cay nhi phan tim kiem
int insert(int x, Node*& root) {
    if (root == NULL) {
        root = new Node(x);  // Tao node moi
        if (root == NULL) {
            return -1;  // Loi cap phat bo nho
        } else {
            return 1;   // Them thanh cong
        }
    } else {
        if (root->data == x) {
            return 0;   // Gia tri da ton tai trong cay
        } else if (x < root->data) {
            return insert(x, root->left);  // Them vao ben trai
        } else {
            return insert(x, root->right); // Them vao ben phai
        }
    }
}

// Ham tim nut co khoa nho nhat
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;  // Di chuyen den con trai nhat
    }
    return root;
}

// Ham tim nut co khoa lon nhat
Node* findMax(Node* root) {
    while (root && root->right != NULL) {
        root = root->right;  // Di chuyen den con phai nhat
    }
    return root;
}

// Ham xoa mot phan tu khoi cay nhi phan tim kiem
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);  // Xoa o ben trai
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // Xoa o ben phai
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;  // Xoa node va tra ve con phai
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;  // Xoa node va tra ve con trai
        }

        // Neu node co hai con, tim node thay the (min cua ben phai)
        Node* temp = findMin(root->right);
        root->data = temp->data;  // Thay gia tri node hien tai bang node thay the
        root->right = deleteNode(root->right, temp->data);  // Xoa node thay the
    }
    return root;
}

// Ham duyet cay theo thu tu giua (Inorder)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);      // Duyet con trai
        cout << root->data << " "; // In ra node hien tai
        inorder(root->right);     // Duyet con phai
    }
}

// Ham duyet cay theo thu tu truoc (Preorder)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " "; // In ra node hien tai
        preorder(root->left);      // Duyet con trai
        preorder(root->right);     // Duyet con phai
    }
}

// Ham duyet cay theo thu tu sau (Postorder)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Duyet con trai
        postorder(root->right);    // Duyet con phai
        cout << root->data << " "; // In ra node hien tai
    }
}

// Ham de khoi tao va hien thi cay nhi phan tim kiem
int main() {
    Node* root = NULL;

    // Them cac phan tu vao cay
    insert(50, root);
    insert(30, root);
    insert(20, root);
    insert(40, root);
    insert(70, root);
    insert(60, root);
    insert(80, root);

    // Duyet cay theo thu tu giua
    cout << "Duyet cay theo thu tu giua (Inorder): ";
    inorder(root);
    cout << endl;

    // Duyet cay theo thu tu truoc
    cout << "Duyet cay theo thu tu truoc (Preorder): ";
    preorder(root);
    cout << endl;

    // Duyet cay theo thu tu sau
    cout << "Duyet cay theo thu tu sau (Postorder): ";
    postorder(root);
    cout << endl;

    // Tim min va max trong cay
    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);
    cout << "Gia tri nho nhat trong cay: " << minNode->data << endl;
    cout << "Gia tri lon nhat trong cay: " << maxNode->data << endl;

    // Xoa mot phan tu
    cout << "Xoa 20 khoi cay..." << endl;
    root = deleteNode(root, 20);

    // Duyet lai cay sau khi xoa
    cout << "Duyet cay sau khi xoa 20:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}

