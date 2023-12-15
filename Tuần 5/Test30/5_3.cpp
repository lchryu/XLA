#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int row, col;
double a[9][9];
double a1[9][9];
double a2[9][9];
double a3[9][9];
double a4[9][9];
double a5[9][9];
double a6[9][9];
double a7[9][9];
double a8[9][9];

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

double K1[3][3] = {{-3, -3, 5}, {-3, 0, 5}, {-3, -3, 5}};
double K2[3][3] = {{-3, 5, 5}, {-3, 0, 5}, {-3, -3, -3}};
double K3[3][3] = {{5, 5, 5}, {-3, 0, -3}, {-3, -3, -3}};
double K4[3][3] = {{5, 5, -3}, {5, 0, -3}, {-3, -3, -3}};
double K5[3][3] = {{5, -3, -3}, {5, 0, -3}, {5, -3, -3}};
double K6[3][3] = {{-3, -3, -3}, {5, 0, -3}, {5, 5, -3}};
double K7[3][3] = {{-3, -3, -3}, {-3, 0, -3}, {5, 5, 5}};
double K8[3][3] = {{-3, -3, -3}, {-3, 0, 5}, {-3, 5, 5}};

int cnt = 1;

struct update_point
{
    int i;
    int j;
    double value;
};
vector<update_point> update_points;
vector<update_point> update_points2;

void solve(int i, int j, double K1[3][3])
{
    cout << "G" << cnt << "(" << i - 1 << ", " << j - 1 << ") = ";
    double sum = 0;
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        int i2 = 1 + dx[k], j2 = 1 + dy[k];
        cout << a[i1][j1] << "*" << K1[i2][j2];
        if (k != 8)
            cout << " + ";
        sum += a[i1][j1] * K1[i2][j2];
    }

    cout << " = " << sum;

    update_points.push_back({i, j, sum});
}
void TinhToan(double K1[3][3], double a[9][9])
{
    cout << endl;
    cout << "K" << cnt << " = \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << K1[i][j];
            if (j != 2)
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            solve(i, j, K1);
            cout << endl;
        }
    }

    for (auto update_point : update_points)
    {
        a[update_point.i][update_point.j] = update_point.value;
    }

    // in ra ket qua
    cout << endl
         << "G" << cnt << " = \n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << a[i][j];
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }
    cout << "\n|G" << cnt << "| = \n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            a[i][j] = abs(a[i][j]);
            cout << a[i][j];
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }
    cnt++;
}

// Hàm tìm giá trị lớn nhất từ 8 số kiểu bất kỳ
template <typename T>
T findMax(T arg1, T arg2, T arg3, T arg4, T arg5, T arg6, T arg7, T arg8) {
    // Sử dụng hàm std::max để tìm giá trị lớn nhất
    return std::max({arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8});
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> row >> col;
    cout << "I = \n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> a[i][j];
            cout << a[i][j];
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }


    TinhToan(K1, a1);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K2, a2);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K3, a3);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K4, a4);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K5, a5);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K6, a6);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K7, a7);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;
    TinhToan(K8, a8);
    cout << endl;
    cout << "-------------------------------------------------------------------------------------";
    cout << endl;

    cout << "G = max{ |G1|, |G2|, |G3|, |G4|, |G5|, |G6|, |G7|, |G8| }: " << endl;


    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << findMax(a1[i][j], a2[i][j], a3[i][j], a4[i][j], a5[i][j], a6[i][j], a7[i][j], a8[i][j]);
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }

}