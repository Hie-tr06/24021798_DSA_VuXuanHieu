#include <iostream>
using namespace std;
int tinhGiaiThua(int soNguyen) {
    if (soNguyen == 0) {
        return 1;
    }
    else {
        return soNguyen * tinhGiaiThua(soNguyen - 1);
    }
}

int main() {
    int nhapSoN;
    cin >> nhapSoN;

    cout << tinhGiaiThua(nhapSoN);

    return 0;
}
// Độ phức tạp thuật toán là O(n).
// Độ phức tạp memory là O(n).