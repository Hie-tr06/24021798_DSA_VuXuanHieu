//6th
#include <iostream>
#include <algorithm> //swap
using namespace std;

// Hàm cây con có gốc tại chỉ số i
// n là kích thước của Heap
void heapify(int arr[], int n, int i) {
    int largest = i;       // Khởi tạo largest là gốc
    int left = 2 * i + 1;  // Con trái = 2*i + 1
    int right = 2 * i + 2; // Con phải = 2*i + 2

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn phần tử lớn nhất hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu phần tử lớn nhất không phải là gốc
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Đệ quy heapify lại cây con bị ảnh hưởng
        heapify(arr, n, largest);
    }
}

// Hàm chính thực hiện Heap Sort
void heapSort(int arr[], int n) {
    // Bước 1: Xây dựng Max-Heap (Vun đống từ nút không phải lá đầu tiên)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Bước 2: Trích xuất từng phần tử từ Heap
    for (int i = n - 1; i > 0; i--) {
        // Đưa phần tử lớn nhất (gốc) về cuối mảng
        swap(arr[0], arr[i]);

        // Gọi heapify trên heap đã giảm kích thước
        heapify(arr, i, 0);
    }
}

int main() {
    int a[5] = {7, -5, -10, 99, 5};
    int n = 5;

    heapSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}