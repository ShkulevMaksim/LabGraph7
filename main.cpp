#define _USE_MATH_DEFINES
#include <cmath>
#include <Windows.h>
const int shift = 100;
const int cells = 20;
const int celln = 20;
HWND hwnd = GetConsoleWindow();
HDC dc = GetDC(hwnd);
void draw_grid() {

    int x = 0, y = 0;

    HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));

    SelectObject(dc, pen);
    while (x <= celln) {
        MoveToEx(dc, x * cells + x, shift, nullptr);
        LineTo(dc, x * cells + x, shift + cells * celln + celln);
        x++;
    }

    DeleteObject(pen);
    SelectObject(dc, pen);
    while (y <= celln) {
        MoveToEx(dc, 0, shift + y * cells + y, nullptr);
        LineTo(dc, cells * celln + celln, shift + y * cells + y);
        y++;

    }

    DeleteObject(pen);

}

void multiplication(double A[][4], double B[][4])
{
    double C[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 4; k++)
                C[i][j] += A[i][k] * B[k][j];

        }

    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            A[i][j] = C[i][j];

}

void draw_poly(double P[][4])
{
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

    SelectObject(dc, pen);//выбор пера для контура круга

    for (int i = 0; i < 3; i++)
    {
        MoveToEx(dc, (P[i][0] - 1) * cells + P[i][0] + (celln / 2) * cells + (celln / 2), shift + (celln - P[i][1]) * cells + celln - P[i][1] + 1 - (celln / 2) * cells - (celln / 2), nullptr);
        LineTo(dc, (P[i+1][0] - 1) * cells + P[i+1][0] + (celln / 2) * cells + (celln / 2), shift + (celln - P[i+1][1]) * cells + celln - P[i+1][1] + 1 - (celln / 2) * cells - (celln / 2));

    }

    DeleteObject(pen);
}

void vec_mult(double A[][4], double B[][4])
{
    double C[4][4];

    for (int i = 0; i < 4; i++)
     A[i][3] = 1;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < 4; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            A[i][j] = C[i][j];

}

void Clear()
{
    HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(dc, brush);
    Rectangle(dc, 0, 0, 600, 600);
    DeleteObject(brush);
}
int main()
{
    double dx=1, dy=2, dz=3;
    double size_x = 2, size_y = 2, size_z = 2;
    double T[4][4]={ {1, 0, 0, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0},
                     {dx, dy, dz, 1} };
    double S[4][4]= { {size_x, 0,      0,      0},
                      {0,      size_y, 0,      0},
                      {0,      0,      size_z, 0},
                      {0,      0,      0,      1} };
    double M[4][4] = { {1, 0, 0, 0},
                       {0, 1, 0, 0},
                       {0, 0, 1, 1},
                       {0, 0, 0, 1} };
    for (double fi=0 * M_PI /180; fi>-1; fi+=1* M_PI /180)
    {
        //draw_grid();
        double Pol1[4][4] = { {1.000000, -1.000000, -1.000000, 0},
                              {1.000000, -1.000000, 1.000000, 0},
                              {-1.000000, -1.000000, 1.000000, 0},
                              {-1.000000, -1.000000, -1.000000, 1} };
        double Pol2[4][4] = { {1.000000, 1.000000, -0.999999, 0},
                              {-1.000000, 1.000000, -1.000000, 0},
                              {-1.000000, 1.000000, 1.000000, 0},
                              {0.999999, 1.000000, 1.000001, 1} };
        double Pol3[4][4] = { {1.000000, -1.000000, -1.000000, 0},
                              {1.000000, 1.000000, -0.999999, 0},
                              {0.999999, 1.000000, 1.000001, 0},
                              {1.000000, -1.000000, 1.000000, 1} };
        double Pol4[4][4] = { {1.000000, -1.000000, 1.000000, 0},
                              {0.999999, 1.000000, 1.000001, 0},
                              {-1.000000, 1.000000, 1.000000, 0},
                              {-1.000000, -1.000000, 1.000000, 1} };
        double Pol5[4][4] = { {-1.000000, -1.000000, 1.000000, 0},
                              {-1.000000, 1.000000, 1.000000, 0},
                              {-1.000000, 1.000000, -1.000000, 0},
                              {-1.000000, -1.000000, -1.000000, 1} };
        double Pol6[4][4] = { {1.000000, 1.000000, -0.999999, 0},
                              {1.000000, -1.000000, -1.000000, 0},
                              {-1.000000, -1.000000, -1.000000, 0},
                              {-1.000000, 1.000000, -1.000000, 1} };
        double Rx[4][4] = { {1, 0, 0, 0},
                            {0, cos(fi), sin(fi), 0},
                            {0, -sin(fi), cos(fi), 0},
                            {0, 0, 0, 1} };
        double Ry[4][4] = { {cos(fi), 0, -sin(fi), 0},
                            {0, 1, 0, 0},
                            {sin(fi), 0, cos(fi), 0},
                            {0, 0, 0, 1} };
        double Rz[4][4] = { {cos(fi), sin(fi), 0, 0},
                            {-sin(fi), cos(fi), 0, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 1} };
        multiplication(Pol1, M);
        multiplication(Pol2, M);
        multiplication(Pol3, M);
        multiplication(Pol4, M);
        multiplication(Pol5, M);
        multiplication(Pol6, M);
        vec_mult(Pol1, T);
        vec_mult(Pol2, T);
        vec_mult(Pol3, T);
        vec_mult(Pol4, T);
        vec_mult(Pol5, T);
        vec_mult(Pol6, T);
        multiplication(Pol1, S);
        multiplication(Pol2, S);
        multiplication(Pol3, S);
        multiplication(Pol4, S);
        multiplication(Pol5, S);
        multiplication(Pol6, S);
        multiplication(Pol1, Rx);
        multiplication(Pol2, Rx);
        multiplication(Pol3, Rx);
        multiplication(Pol4, Rx);
        multiplication(Pol5, Rx);
        multiplication(Pol6, Rx);
        multiplication(Pol1, Ry);
        multiplication(Pol2, Ry);
        multiplication(Pol3, Ry);
        multiplication(Pol4, Ry);
        multiplication(Pol5, Ry);
        multiplication(Pol6, Ry);
        multiplication(Pol1, Rz);
        multiplication(Pol2, Rz);
        multiplication(Pol3, Rz);
        multiplication(Pol4, Rz);
        multiplication(Pol5, Rz);
        multiplication(Pol6, Rz);

        draw_poly(Pol1);
        draw_poly(Pol2);
        draw_poly(Pol3);
        draw_poly(Pol4);
        draw_poly(Pol5);
        draw_poly(Pol6);
        Sleep(50);
        Clear();

    }

}