#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int row, col;
int a[50][50];
int a_windows[3][3];
int dx[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
int dy[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
void solve(int i, int j) {
    cout << "Xét điểm (" << i - 1 << ", " << j - 1 << "): \n";
    double sum = 0;
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        int i2 = 1 + dx[k], j2 = 1 + dy[k];
        a_windows[i2][j2] = a[i1][j1];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a_windows[i][j];
            if (j != 2) cout << " ";
        }
        cout << endl;
    }
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
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> a[i][j];
            cout << a[i][j];
            if (j != col) cout << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            solve(i, j);
            cout << endl;
        }
    }
}
