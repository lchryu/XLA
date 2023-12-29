#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int row, col;
int a[50][50];
int dx[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
int dy[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
struct update_point
{
    int i;
    int j;
    double value;
};
vector<update_point> update_points;

void solve(int i, int j) {
    vector<double>v;
    double sum = 0;
    cout << "TV(" << i - 1 << ", " << j - 1 << ") = ";
    cout << "{";
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        sum += a[i1][j1];
        
        v.push_back(a[i1][j1]);
    }
    sort(v.begin(), v.end());

    for (int k = 0; k < v.size(); k++) {
        if (k == 4) cout << "[" << v[k] << "], ";
        else if (k != v.size() - 1) cout << v[k] << ", ";
        else if (k == v.size() - 1) cout << v[k];
    }
    cout << "}";
    update_points.push_back({i, j, v[4]});

}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cin >> row >> col;    
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
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

    for (auto update_point : update_points) {
        a[update_point.i][update_point.j] = update_point.value; 
    }

    cout << endl;
    cout << "Kết quả bộ lọc: \n";
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cout << a[i][j];
            if (j != col) cout << " ";
        }
        cout << endl;
    }
}
