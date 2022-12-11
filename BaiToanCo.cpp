#include <iostream>
using namespace std;
#define MAX_SIZE 1000

struct Trau
{
    int dung;
    int nam;
    int gia;
};

// Nhập tổng trâu và cỏ
void setTrauCo(int &tongTrau, int &tongCo)
{
    cout << "Nhap tong trau: ";
    cin >> tongTrau;
    cout << "Nhap tong co: ";
    cin >> tongCo;
}

// Tìm trâu đứng nằm già
bool timTrau(Trau &trau, int tongTrau = 100, int tongCo = 100, int min = 0)
{
    for (trau.dung = min; trau.dung <= tongCo / 5; trau.dung++) // Chạy vòng lập trâu đứng
    {
        int trauNG = tongTrau - trau.dung;
        for (trau.gia = 0; trau.gia <= trauNG; trau.gia += 3) // Chạy vòng lập trâu già
        {
            trau.nam = trauNG - trau.gia;
            if ((trau.dung * 5) + (trau.nam * 3) + (trau.gia / 3) == tongCo) // Xét điều kiện nếu đúng thì nhận 2 vòng lập trên
            {
                return true;
            }
        }
    }
    return false;
}

// Xuất số trâu
void printTrau(Trau trau)
{
    cout << "So trau dung: " << trau.dung << endl;
    cout << "So trau nam: " << trau.nam << endl;
    cout << "So trau gia: " << trau.gia << endl;
}

int main()
{
    Trau trau;
    int tongTrau, tongCo, D;
    setTrauCo(tongTrau, tongCo);
    do
    {
        for (int i = 0, min = 0; timTrau(trau, tongTrau, tongCo, min); i++, min = trau.dung + 1) // Để lặp tính các trường hợp còn lại
        {
            cout << "Truong hop "<< i + 1 << ": " << endl;
            printTrau(trau);
        }
        cout << "Nhap 1 de chay tiep chuong trinh.\nNhap 0 de thoat chuong trinh.\nLua chon cua ban: ";
        cin >> D;
        if (D == 0)
        {
            return 0;
        }
        setTrauCo(tongTrau, tongCo);
    } while (tongTrau * tongCo);
}