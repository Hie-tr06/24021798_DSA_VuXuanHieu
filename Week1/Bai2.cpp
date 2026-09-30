#include <iostream>
using namespace std;
void hoanDoi(int &soThuNhat, int &soThuHai) {
    int bienTam = soThuNhat;
    soThuNhat = soThuHai;
    soThuHai = bienTam;
}

void sapXepTangDan(int mang[], int soPhanTu) {
    for (int i = 0; i < soPhanTu - 1; i++) {
        for (int j = i + 1; j < soPhanTu; j++) {
            if (mang[i] > mang[j]) {
                hoanDoi(mang[i], mang[j]);
            }
        }
    }
}

void inMang(const int mang[], int soPhanTu) {
    for (int i = 0; i < soPhanTu; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;
}

int main() {
    int soPhanTu;
    cin >> soPhanTu;

    int mangSoNguyen[10000];
    for (int i = 0; i < soPhanTu; i++) {
        cin >> mangSoNguyen[i];
    }

    sapXepTangDan(mangSoNguyen, soPhanTu);
    inMang(mangSoNguyen, soPhanTu);

    return 0;
}
//Độ phức tạp thuật toán là: O(n^2).
// Độ phức tạp memory là O(1).