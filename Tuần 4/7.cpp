#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int row, col;
int a[50][50];
int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
struct update_point
{
    int i;
    int j;
    double value;
};
vector<update_point> update_points;
vector<vector<double>> KK = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

void solve(int i, int j)
{
    vector<double> v;
    cout << "Xet diem (" << i - 1 << ", " << j - 1 << "):\n";
    double sum = 0;
    cout << "I(" << i - 1 << ", " << j - 1 << ") = 1/16 * (";
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        int i2 = 1 + dx[k], j2 = 1 + dy[k];

        cout << a[i1][j1] << "*" << KK[i2][j2];
        if (k != 8)
            cout << " + ";

        sum += a[i1][j1] * KK[i2][j2];

        v.push_back(a[i1][j1]);
    }
    cout << ") = ";
    cout << sum / 16;

    update_points.push_back({i, j, round(sum / 16)});

    cout << endl;
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
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            solve(i, j);
            cout << endl;
        }
    }

    for (auto update_point : update_points)
    {
        a[update_point.i][update_point.j] = update_point.value;
    }

    cout << endl;
    cout << "Kết quả bộ lọc: \n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
