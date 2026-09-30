#include <iostream>
using namespace std;
void nhapDaySo(float mangSoThuc[], int soPhanTu) {
    for (int i = 0; i < soPhanTu; i++) {
        cin >> mangSoThuc[i];
    }
}

float tinhTrungBinhCong(const float mangSoThuc[], int soPhanTu) {
    float tong = 0;
    for (int i = 0; i < soPhanTu; i++) {
        tong += mangSoThuc[i];
    }
    return tong / soPhanTu;
}

void inGiaTriLonHonHoacBangTB(const float mangSoThuc[], int soPhanTu, float giaTriTB) {
    for (int i = 0; i < soPhanTu; i++) {
        if (mangSoThuc[i] >= giaTriTB) {
            cout << mangSoThuc[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int soPhanTu;
    cin >> soPhanTu;
    float mangSoThuc[1000];
    nhapDaySo(mangSoThuc, soPhanTu);
    float giaTriTB = tinhTrungBinhCong(mangSoThuc, soPhanTu);
    inGiaTriLonHonHoacBangTB(mangSoThuc, soPhanTu, giaTriTB);

    return 0;
}
// Độ phức tạp thuật toán là O(n).
// Độ phức tạp memory là O(1).