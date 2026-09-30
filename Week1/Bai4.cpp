#include <iostream>
#include <cmath>
using namespace std;
int timUCLN(int soThuNhat, int soThuHai) {
    if (soThuHai == 0) {
        return soThuNhat;
    }
    return timUCLN(soThuHai, soThuNhat % soThuHai);
}

void rutGonPhanSo(int tuSo, int mauSo) {
    if (mauSo == 0) {
        cout << "Mau so phai khac 0!" << endl;
        return;
    }

    int ucln = timUCLN(abs(tuSo), abs(mauSo));
    tuSo /= ucln;
    mauSo /= ucln;

    if (mauSo < 0) {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }

    if (mauSo == 1) {
        cout << tuSo;
    } else {
        cout << tuSo << "/" << mauSo;
    }
}

int main() {
    int nhapTuSo, nhapMauSo;
    cin >> nhapTuSo >> nhapMauSo;

    rutGonPhanSo(nhapTuSo, nhapMauSo);

    return 0;
}
// Độ phức tạp thuật toán là: O(log(min(a,b))).
// Độ phức tạp memory là O(log(min(a,b))).