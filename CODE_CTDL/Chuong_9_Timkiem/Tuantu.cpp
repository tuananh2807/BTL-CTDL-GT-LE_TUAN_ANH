#include <iostream>
#include <vector>
using namespace std;

// Ham SEQUEN_SEARCH: Tim kiem tuan tu
int SEQUEN_SEARCH(const vector<int>& k, int n, int X) {
    int i = 0;                 // Buoc 1: Khoi dau
    vector<int> arr = k;       
    arr.push_back(X);           // Them X vao cuoi mang

    while (arr[i] != X) {      // Buoc 2: Tim khoa trong day
        i++;
    }

    if (i == n) {               // Buoc 3: Kiem tra ket qua
        return 0;                // X khong co trong mang
    } else {
        return i + 1;           // Tra ve vi tri cua X trong mang
    }
}

int main() {
    int n, X;
    
    // Nhap vao kich thuoc mang
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;
    
    vector<int> k(n);
    
    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    // Nhap gia tri X can tim
    cout << "Nhap gia tri X can tim: ";
    cin >> X;

    // Goi ham SEQUEN_SEARCH
    int result = SEQUEN_SEARCH(k, n, X);

    // Xuat ket qua
    if (result == 0) {
        cout << "Gia tri " << X << " khong ton tai trong mang." << endl;
    } else {
        cout << "Gia tri " << X << " tim thay tai vi tri " << result << " trong mang." << endl;
    }

    return 0;
}

