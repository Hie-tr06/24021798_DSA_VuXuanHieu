#include <iostream>
using namespace std;
void nhapMang(int mang[], int soPhanTu) {
    for (int i = 0; i < soPhanTu; i++) {
        cin >> mang[i];
    }
}

void inMang(const int mang[], int soPhanTu) {
    for (int i = 0; i < soPhanTu; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;
}

void xoaPhanTu(int mang[], int &soPhanTu, int viTriK) {
    if (viTriK < 0 || viTriK >= soPhanTu) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }

    for (int i = viTriK; i < soPhanTu - 1; i++) {
        mang[i] = mang[i + 1];
    }

    soPhanTu--;
}

void chenPhanTu(int mang[], int &soPhanTu, int viTriM, int giaTriY) {
    if (viTriM < 0 || viTriM > soPhanTu) {
        cout << "Vi tri m khong hop le!" << endl;
        return;
    }

    for (int i = soPhanTu - 1; i >= viTriM; i--) {
        mang[i + 1] = mang[i];
    }

    mang[viTriM] = giaTriY;
    soPhanTu++;
}

int main() {
    int soPhanTu;
    cin >> soPhanTu;

    int mangSoNguyen[1000];
    nhapMang(mangSoNguyen, soPhanTu);

    // Xóa ptu tai vtri k
    int viTriK;
    cin >> viTriK;
    xoaPhanTu(mangSoNguyen, soPhanTu, viTriK);
    cout << "Mang sau khi xoa: ";
    inMang(mangSoNguyen, soPhanTu);

    // Chèn pptu y vao vtri m
    int viTriM, giaTriY;
    cin >> viTriM >> giaTriY;
    chenPhanTu(mangSoNguyen, soPhanTu, viTriM, giaTriY);
    cout << "Mang sau khi chen: ";
    inMang(mangSoNguyen, soPhanTu);

    return 0;
}
// Độ phức tạp thuật toán là O(n).
// Độ phức tạp memory là O(1).