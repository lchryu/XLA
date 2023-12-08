#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int row, col;
int a[50][50];
int dx[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
int dy[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
void solve(int i, int j) {
    cout << "Xet diem (" << i - 1 << ", " << j - 1 << "): ";
    double sum = 0;
    cout << "(";
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        sum += a[i1][j1];
        
        if (k == 8) cout << a[i1][j1];
        else cout << a[i1][j1] << " + ";
    }
    cout << ") / 9 = " << fixed << setprecision(2) << sum/9;
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
            cout << a[i][j] << " ";
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
