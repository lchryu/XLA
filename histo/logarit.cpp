// bien doi logarit
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n, m; cin >> n >> m;
    double a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] /= 255;
        }
    }
    cout << "I1 = \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << fixed << setprecision(4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nI2 = \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double s = 2 * log(1 + a[i][j]);
            cout << fixed << setprecision(4) << s << " ";
            a[i][j] = s;
        }
        cout << endl;
    }

    
    cout << "\nI4 = \n" << fixed << setprecision(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4);
            if (a[i][j] > 1) cout << 255;
            else cout << a[i][j] * 255;
            cout << " ";
        }
        cout << endl;
    }
}
