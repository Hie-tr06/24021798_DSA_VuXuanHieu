#include <iostream>
using namespace std;
void readArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}
// Độ phức tạp thời gian là: O(n).
int sumArray(const int array[], int size) {
    int totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += array[i];
    }
    return totalSum;
}
// Độ phức tạp thời gian là: O(n).
int main() {
    int size; 
    cin >> size;
    
    int numbers[1000];
    readArray(size, numbers);
    
    cout << sumArray(numbers, size);
    
    return 0;
}
// Độ phức tạp thuật toán là: O(n).
// Độ phức tạp memory là O(1).