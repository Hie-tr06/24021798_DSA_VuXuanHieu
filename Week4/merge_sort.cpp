//4th
#include <iostream>
using namespace std;

//Trộn 2 mảng con đã sắp 
void merge(int arr[], int left, int mid, int right) {
    // Tính kthước của 2 mảng con
    int n1 = mid - left + 1; // Số ptử nửa trái
    int n2 = right - mid;     // Số ptử nửa phải

    // Tạo 2 mảng tạm L và R
    int L[n1], R[n2];

    // Sao chép dữ liệu vào 2 mảng tạm
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0;   
    int j = 0;   
    int k = left;

    // So sánh từng ptu L và R, nhỏ hơn thì đưa vào arr[k]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Nếu mảng L vẫn còn ptử thừa, chép hết vào arr
    while (i < n1) { arr[k] = L[i]; i++; k++; }

    // Nếu mảng R vẫn còn ptử thừa, chép hết vào arr
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

//Merge sử dụng cấp phát động cho mảng
/*
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Số phần tử nửa bên trái
    int n2 = right - mid;     // Số phần tử nửa bên phải

    // 1. Cấp phát động bộ nhớ cho mảng L và R
    int* L = new int[n1];
    int* R = new int[n2];

    // 2. Sao chép dữ liệu từ mảng gốc 'arr' vào 2 mảng động L và R
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0;    // Chỉ số cho mảng L
    int j = 0;    // Chỉ số cho mảng R
    int k = left; // Chỉ số cho mảng arr

    // 3. Trộn hai mảng L và R vào mảng arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại nếu có
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    // 4. BẮT BUỘC: Giải phóng bộ nhớ động sau khi hoàn thành
    delete[] L;
    delete[] R;
}
*/

//Hàm chia đệ quy
void mergeSort(int arr[], int left, int right) {
    // Điều kiện dừng đệ quy: khi left >= right (mảng chỉ còn 1 phần tử hoặc rỗng)
    if (left < right) {
        // Tìm vị trí ở giữa mảng
        // Dùng (left + (right - left) / 2) để tránh tràn số khi left và right quá lớn
        int mid = left + (right - left) / 2;

        // Gọi đệ quy chia đôi nửa bên trái
        mergeSort(arr, left, mid);

        // Gọi đệ quy chia đôi nửa bên phải
        mergeSort(arr, mid + 1, right);

        // Sau khi 2 nửa đã được sắp xếp xong, trộn chúng lại
        merge(arr, left, mid, right);
    }
}


int main() {
    int a[5] = {7, -5, -10, 99, 5};
    int n = 5;

    mergeSort(a, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}