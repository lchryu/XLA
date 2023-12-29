#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int row, col;
double a[50][50];
int a_cp[9][9];
int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int K1[3][3] = {{1, 0, -1},
                {2, 0, -2},
                {1, 0, -1}};

int K2[3][3] = {{1, 2, 1}, 
                {0, 0, 0}, 
                {-1, -2, -1}};

struct update_point
{
    int i;
    int j;
    double value;
};

vector<update_point> update_points;
vector<update_point> update_points2;

void solve(int i, int j, int K1[3][3])
{
    cout << "G(" << i - 1 << ", " << j - 1 << ") = ";
    double sum = 0;
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        int i2 = 1 + dx[k], j2 = 1 + dy[k];
        sum += a[i1][j1] * K1[i2][j2];
        // cout << a[i1][j1] << "*" << K1[i2][j2];
        if (a[i1][j1] * K1[i2][j2] == 0) continue;
        cout << a[i1][j1] * K1[i2][j2];
        if (k != 8)
            cout << " + ";
    }

    cout << " = " << sum;
    cout << "\n----------------------------------------";
    update_points.push_back({i, j, sum});
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> row >> col;
    cout << "I = \n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
            cin >> a[i][j];
    }
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


    cout << endl;
    cout << "K1 = \n";
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
        a_cp[update_point.i][update_point.j] = update_point.value;
    }

    // in ra ket qua
    cout << endl
         << "Kết quả:\n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << a_cp[i][j];
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }

    // truoc khi tuong quan voi matrix 2 thi clear update
    update_points.clear();

    cout << endl;

    cout << endl;
    cout << "---------------------------------------------\n";
    cout << "K2 = \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << K2[i][j];
            if (j != 2)
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // tương quan 2
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            solve(i, j, K2);
            cout << endl;
        }
    }

    // update lan cuoi
    for (auto update_point : update_points)
    {
        a[update_point.i][update_point.j] = update_point.value;
    }

    // in ra ket qua
    cout << endl
         << "Kết quả:\n";
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

    cout << endl;
    cout << "G = |Gx| + |Gy|\n";
    // cout << fixed << setprecision(4);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            a[i][j] = abs(a[i][j]) + abs(a_cp[i][j]);
            cout << a[i][j];
            if (j != col)
                cout << " ";
        }
        cout << endl;
    }
}