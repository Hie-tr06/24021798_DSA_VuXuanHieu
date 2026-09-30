#include <iostream>
using namespace std;
void nhapMaTran(int maTran[100][100], int soDong, int soCot) {
    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            cin >> maTran[i][j];
        }
    }
}

void inMaTran(const int maTran[100][100], int soDong, int soCot) {
    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            cout << maTran[i][j] << " ";
        }
        cout << endl;
    }
}

long long tinhTongCacPhanTu(const int maTran[100][100], int soDong, int soCot) {
    long long tong = 0;
    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            tong += maTran[i][j];
        }
    }
    return tong;
}

void xoaDong(int maTran[100][100], int &soDong, int soCot, int viTriDong) {
    if (viTriDong < 0 || viTriDong >= soDong) {
        cout << "Vi tri dong khong hop le" << endl;
        return;
    }

    for (int i = viTriDong; i < soDong - 1; i++) {
        for (int j = 0; j < soCot; j++) {
            maTran[i][j] = maTran[i + 1][j];
        }
    }

    soDong--;
}

int main() {
    int soDong, soCot; 
    cin >> soDong >> soCot;

    int maTran[100][100];
    nhapMaTran(maTran, soDong, soCot);

    cout << "Tong cac phan tu: " << tinhTongCacPhanTu(maTran, soDong, soCot) << endl;

    int dongCanXoa;
    cin >> dongCanXoa;
    xoaDong(maTran, soDong, soCot, dongCanXoa);

    cout << "Ma tran sau khi xoa dong " << dongCanXoa << ":" << endl;
    inMaTran(maTran, soDong, soCot);

    return 0;
}
// Độ phức tạp time là O(NM).
// Độ phức tạp memory là O(1).