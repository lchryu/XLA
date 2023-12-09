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
    cout << "-----------------------Xét điểm (" << i - 1 << ", " << j - 1 << ")-----------------------";
    double sum = 0;
    for (int k = 0; k < 9; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        sum += a[i1][j1];
        
        v.push_back(a[i1][j1]);
    }
    sort(v.begin(), v.end());

    cout << "\ns(" << i - 1 << ", " << j - 1 << ")= {"; 
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1) cout << v[i] << ", ";
        else cout << v[i];
    }
    cout << "}";
    cout << endl;
    cout << "d = 2 -> ";
    // xoá phần tử min và max
    v.pop_back();
    v.erase(v.begin());

    cout << "{";
    for (int k = 0; k < v.size(); k++) {
        if (k == 4) cout << v[k] << ", ";
        else if (k != v.size() - 1) cout << v[k] << ", ";
        else if (k == v.size() - 1) cout << v[k];
    }
    cout << "}";
    cout << endl;

    cout << "I(" << i - 1 << ", " << j - 1 << ") = " << "(1/(3 * 3 - 2)) * ("; 

    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1) cout << v[i] << " + ";
        else cout << v[i];
    }

    cout << ") = ";

    double I_x_y = 0;
    
    for (auto i : v) I_x_y += i;

    I_x_y /= (3 * 3 - 2);
    cout << I_x_y;

    update_points.push_back({i, j, round(I_x_y)});

    cout << endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("6.txt", "w", stdout);
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
