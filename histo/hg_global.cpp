#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[5][5];
struct thong_ke
{
    int n_i;
    int p_i;
};
int dx[9] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
int dy[9] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
double k0, k1, k2, k3, C;

double m = 0;
double xich_ma_square = 0;


struct update_point
{
    int i;
    int j;
    double value;
};

vector<update_point> update_points;

void solve(int i, int j) {
    cout << "--------------------------------------------------------------------------------------------" << endl;
    map<int, int> cnt;
    cout << "Xet diem (" << i - 1 << ", " << j - 1 << ")\n";
    int dem = 0;
    for (int k = 0; k < 9; k++)
    {
        dem++;
        int i1 = i + dx[k], j1 = j + dy[k];
        cout << a[i1][j1] << " ";
        cnt[a[i1][j1]]++;
        if (dem % 3 == 0) cout << endl;
    }
    cout << endl;

    int width = 4;
    cout << "\nBang thong ke muc xam: \n";
    cout << setw(width) << "r_i "; for (auto i : cnt) cout << setw(width) << i.first << " ";
    cout << endl;
    cout << setw(width) << "n_i "; for (auto i : cnt) cout << setw(width) << i.second << " ";
    cout << endl;
    cout << setw(width) << "p_i "; for (auto i : cnt) cout << setw(2) << i.second << "/9" << " ";
    cout << endl;

    cout << "\nCường độ sáng trung bình của vùng S("  << i - 1 << ", " << j - 1 << "):\n";
    double m_s = 0;
    for (auto i : cnt) {
        m_s += i.first * i.second;
    } 
    m_s /= 9;
    cout << "m_s = " << m_s << endl;

    cout << "Chỉ số tương phản của vùng S(" << i - 1 << ", " << j - 1 << "):\n";
    double xich_ma_square_s = 0;
    for (auto i : cnt) {
        xich_ma_square_s += pow(i.first - m_s ,2) * i.second / 9;
    }

    cout << "xich_ma_square_s = " << fixed << setprecision(4) << xich_ma_square_s << endl << endl;

    cout << "Bước 3: kiểm tra điều kiện cập nhập cường độ sáng tại S(" << i - 1 << ", " << j - 1 << "):\n";
    cout << "| k_0 * m <= m_s <= k_1 * m" << endl;
    cout << "| k_2 * &^2<= &^2 <= k_3 * &^2" << endl;
    cout << endl;

    cout << "|" << k0 * m << "<=" << m_s << "<=" << k1 * m << endl;
    cout << "|" << k2 * xich_ma_square << "<=" << xich_ma_square_s << "<=" << k3 * xich_ma_square << endl;
    cout << endl;


    if ((k0 * m <= m_s) and (m_s <= k1 * m) and (k2 * xich_ma_square <= xich_ma_square_s) and (xich_ma_square_s <= k3 * xich_ma_square)) {
        cout << "Nhận thấy điều kiện thoả mãn, khi đó cập nhật lại cường độ sáng tại vị trí S(" << i - 1 << ", " << j - 1 << "):\n";
        if (round(C * a[i][j]) > 7) {
            cout << "f(x, y) = round(C * f(x, y)) = round(" << C << "*" << a[i][j] << ") = " << round(C * a[i][j]) << endl;
            cout << "Do f(x, y) = " << round(C * a[i][j]) << " > 7" << endl;
            cout << "-->f(" <<i << "," << j <<") = 7\n";
            update_points.push_back({i, j, 7});
        } else {
            cout << "-->f(" <<i << "," << j <<") = round(C * f(x, y)) = round(" << C << "*" << a[i][j] << ") = " << round(C * a[i][j]) << endl;
            update_points.push_back({i, j, round(C * a[i][j])});
        }
    } else {
        cout << "Không thoả mãn --> giữ nguyên";
    }
    cout << endl;

    // cout << "------------------------------------------------------------------------";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k0 >> k1 >> k2 >> k3 >> C;
    int row = 3, col = 3;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> a[i][j];
        }
    }
    // for (int i = 0; i <= row + 1; i++) {
    //     for (int j = 0; j <= col + 1; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    map<int, int>dict;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            dict[a[i][j]]++;
        }
    }

    cout << "Bước 1: Tính cường độ sáng trung bình và phương sai của ảnh I: ";
    for (auto i : dict) {
        m += i.first * i.second;
    }
    m /= 9;
    cout << "\nCường độ sáng trung bình của ảnh I\n";
    cout << "\nm = " << m << endl;
    cout << "\nChi so tuong phan cua anh I(Phuong sai cua anh):\n";
    cout << "\nxich_ma_square = \n";
    for (auto i : dict) {
        cout << "(" << i.first << " - " << m << ")^2" << " * " << i.second << "/9 + ";
        xich_ma_square += pow((i.first - m) ,2) * i.second/9;
    }




    cout << "\nxich_ma_square = " << xich_ma_square << endl << endl;


    cout << "\nBuoc2: Tinh cuong do sang trung binh va chi so tuong phan cua tat ca cac vung S(x, y) " << endl;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            solve(i, j);
        }
    }
    
    for (auto update_point : update_points) {
        a[update_point.i][update_point.j] = update_point.value; 
    }

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// 0 0.8 0 4 1.8
// 4 3 0
// 1 0 1
// 4 2 3