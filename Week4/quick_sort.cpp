//5th
#include <iostream>
#include <algorithm>
using namespace std;

// Hàm chia mảng theo phần tử chốt (pivot)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Vị trí pivot đã đúng chỗ

        quickSort(arr, low, pi - 1);  // Sắp xếp nửa bên trái pivot
        quickSort(arr, pi + 1, high); // Sắp xếp nửa bên phải pivot
    }
}

int main() {
    int a[5] = {7, -5, -10, 99, 5};
    int n = 5;

    quickSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}