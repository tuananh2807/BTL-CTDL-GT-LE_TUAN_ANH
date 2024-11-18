#include <iostream>
#include <vector>
using namespace std;

// Ham tim kiem nhi phan
int BinarySearch(const vector<int>& arr, int n, int X) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Tim phan tu o giua

        // Neu X la phan tu giua
        if (arr[mid] == X) {
            return mid + 1;  // Tra ve vi tri (bat dau tu 1)
        }
        // Neu X nho hon phan tu giua
        else if (arr[mid] > X) {
            right = mid - 1;
        }
        // Neu X lon hon phan tu giua
        else {
            left = mid + 1;
        }
    }

    return 0;  // X khong ton tai trong mang
}

int main() {
    int n, X;
    
    // Nhap vao kich thuoc mang
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;
    
    vector<int> arr(n);
    
    // Nhap cac phan tu cua mang (phai sap xep truoc khi tim kiem nhi phan)
    cout << "Nhap cac phan tu cua mang (da sap xep): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Nhap gia tri X can tim
    cout << "Nhap gia tri X can tim: ";
    cin >> X;

    // Goi ham BinarySearch
    int result = BinarySearch(arr, n, X);

    // Xuat ket qua
    if (result == 0) {
        cout << "Gia tri " << X << " khong ton tai trong mang." << endl;
    } else {
        cout << "Gia tri " << X << " tim thay tai vi tri " << result << " trong mang." << endl;
    }

    return 0;
}

