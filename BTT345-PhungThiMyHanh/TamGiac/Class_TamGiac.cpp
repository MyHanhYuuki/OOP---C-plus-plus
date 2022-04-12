#include <iostream>
#include <cmath>
#include "Class_TamGiac.h"
using namespace std;

void TAMGIAC::KhoiTao()
{
    a = b = c = 1;
}

void TAMGIAC::Nhap()
{
    cout << "Lan luot nhap vao 3 canh cua tam giac o day: \n";
    cin >> this->a >> this->b >> this->c;
}

void TAMGIAC::Xuat()
{
    cout << "\nTam giac co 3 canh lan luot la: " << this->a << " " << this->b << " " << this->c;
}

bool TAMGIAC::Kiem_Tra()
{
    if (a + b < c || a + c < b || b + c < a)
        return 0;
    return 1;
}

int TAMGIAC::Phan_Loai()
{
    if (this->Kiem_Tra() == 0)
        return -1; // Khong phai tam giac

    if (a == b && b == c)
        return 1; // Tam gi�c deu

    if ((a == b && a == c) || (b == a && b == c) || (c == a && c == b)) // ?i?u ki?n tam gi�c c�n
    {
        // Dieu kien tam giac vuong
        if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
            return 2; // Tam gi�c vu�ng c�n
        else
            return 3; // Tam gi�c c�n
    }

    if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
        return 4; // Tam gi�c vu�ng

    return 5; // Kh�ng ph�i c�c truong hop tr�n => tam gi�c thuong;
}

double TAMGIAC::Chu_Vi()
{
    return a + b + c;
}

double TAMGIAC::Dien_Tich()
{
    double ncv = this->Chu_Vi() / 2; // Nua chu vi
    return sqrt(ncv * (ncv - a) * (ncv - b) * (ncv - c));
}