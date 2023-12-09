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
double xich_ma = 1, muy = 0;
vector<update_point> update_points;
double G[3][3];

void solve(int i, int j)
{
    vector<double> v;
    cout << "-----------------------Xét điểm (" << i - 1 << ", " << j - 1 << ")-----------------------";

    double sum = 0;
    cout << "\nD(" << i - 1 << ", " << j - 1 << ") = ";
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        int i2 = 1 + dx[k], j2 = 1 + dy[k];

        cout << a[i1][j1] << "*" << G[i2][j2];
        if (k != 8)
            cout << " + ";
        sum += a[i1][j1] * G[i2][j2];
        
    }
    cout << " = " << sum;

    update_points.push_back({i, j, round(sum)});

    cout << endl;
}
const double pi = M_PI;
const double e = M_E;

vector<double> g_tmp;
void solveG()
{
    for (int k = 0; k < 9; k++)
    {
        cout << "G(" << dx[k] << ", " << dy[k] << ") = 1/(2 * pi * xich_ma^2) * (-(" << dx[k] << ")^2 + (" << dy[k] << ")"
             << "^2"
             << ")/(2 * xich_ma^2) = ";
        double mu = -(dx[k] * dx[k] + dy[k] * dy[k]) / (2 * xich_ma * xich_ma);
        double res = (1.0 / (2 * pi * pow(xich_ma, 2))) * pow(e, mu);
        cout << res << endl;
        g_tmp.push_back(res);
    }
    // Chuyển đổi mảng thành ma trận 3x3
    int index = 0; // Biến này sẽ giúp duyệt qua mảng
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            G[i][j] = g_tmp[index];
            index++;
        }
    }
    cout << endl;
}
void chiaTongG()
{
    cout << "Chia các phần tử cho tổng ta thu được:\n";
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += G[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "G(" << dx[cnt] << ", " << dy[cnt] << ") = ";
            cout << G[i][j] << "/" << sum << " = " << G[i][j] / sum;
            G[i][j] /= sum;
            cout << endl;
            cnt++;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("8.txt", "w", stdout);
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
            if (j != col) cout << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << "(" << dx[i] << "," << dy[i] << ") ";
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
    cout << endl;

    // tính toán ma trận G
    solveG();


    // chia các phần tử của G cho tổng
    chiaTongG();

    // kết quả của mặt nạ
    cout << "\nKết quả của mặt nạ Gaussian kích thước 3x3:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // cout << fixed << setprecision(4) << G[i][j] << " ";
            cout << G[i][j];
            if (j != 2) cout << " ";
        }
        cout << endl;
    }
    cout << endl; 

    // std::cout.unsetf(std::ios::fixed);

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
            cout << a[i][j];
            if (j != col) cout << " ";
        }
        cout << endl;
    }
}
