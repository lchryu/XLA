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
int dx[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
int dy[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};

int K1[3][3]  = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};
int K2[3][3] = {{1, 1, 1}, {0, 0, 0}, {-1, -1, -1}};


struct update_point
{
    int i;
    int j;
    double value;
};
vector<update_point> update_points;
vector<update_point> update_points2;


void solve(int i, int j, int K1[3][3]) {
    cout << "G(" << i - 1 << ", " << j - 1 << ") = ";
    double sum = 0;
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        int i2 = 1 + dx[k], j2 = 1 + dy[k];
        sum += a[i1][j1] * K1[i2][j2];
        cout << a[i1][j1] << "*" << K1[i2][j2];
        if (k != 8) cout << " + ";
    }

    cout << " = " << sum;


    update_points.push_back({i, j, sum});
}
void solve2(int i, int j) {
    cout << "C(" << i - 1 << ", " << j - 1 << ") = ";
    double sum = 0;

    cout << a_cp[i][j];
    cout << "/(sqrt(105) * sqrt(";
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];

        cout << a[i1][j1] << "^2";
        if (k != 8) cout << " + ";
        sum += pow(a[i1][j1], 2);
    }
    cout << "))";
    double value = 1.0 * a_cp[i][j]/(sqrt(105) * sqrt(sum));
    cout << " = " << value;


    update_points2.push_back({i, j, value});
}
void genMatrix() {
    K1[0][0] = a[1][1];
    K1[0][1] = a[1][2];
    K1[0][2] = a[1][3];
    K1[1][0] = a[2][1];
    K1[1][1] = a[2][2];
    K1[1][2] = a[2][3];
    K1[2][0] = a[3][1];
    K1[2][1] = a[3][2];
    K1[2][2] = a[3][3];
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
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> a[i][j];
            cout << a[i][j];
            if (j != col) cout << " ";
        }
        cout << endl;
    }



    cout << endl;
    cout << "Thực hiện dò biên theo phương pháp Laplacian. Sử dụng mặt nạ: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << K1[i][j];
            if (j != 2) cout << " ";
        }
        cout << endl;
    }
    cout << endl;


    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            solve(i, j, K1);
            cout << endl;
        }
    }



    for (auto update_point : update_points) {
        a_cp[update_point.i][update_point.j] = update_point.value; 
    }


    // in ra ket qua
    cout << endl << "Kết quả:\n";
    cout << "\nG = |I + H| = \n\n";
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cout << a_cp[i][j];
            if (j != col) cout << " ";
        }
        cout << endl;
    }

}