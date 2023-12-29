#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const float e = M_E;
struct update_point
{
    int i;
    int j;
    double value;
};
vector<update_point> update_points;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int row, col;
	cin >> row >> col;
	float a[row][col];
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cin >> a[i][j];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int u = 0; u < row; u++)
	{
		for (int v = 0; v < col; v++)
		{
			cout << "F(" << u << ", " << v << ") = \n";
			float res = 0;
			for (int h = 0; h < row; h++)
			{
				for (int k = 0; k < col; k++)
				{
					string mu_str = "(" + to_string(u) + " * " + to_string(h) + ")/2 + (" + to_string(v) + " * " + to_string(k) + ")/2";
					float mu =  1.0 * (u * h)/2 +  1.0*(v * k)/2;
					// cout << 1.0 * (v * k)/2 << " || ";
					// cout << mu << " || ";
					cout << a[h][k] << "*" << "(e)^(-j*pi*2*(" << mu_str << "))";
					// cout << a[h][k] << "*" << "(e)^(-j*2*pi*" << mu << ")";
					if (k != col - 1) cout << " + ";
					// else cout << " = ";
					cout << pow(-1, 2 * mu);
					res += a[h][k] * pow(-1, 2 * mu);
				}
				if (h == row - 1) cout << " = ";
				else cout << " +\n";
			}
			update_points.push_back({u, v, res});
			// cout << endl;
			cout << res << endl;
		}
	}

	for (auto update_point : update_points) {
        a[update_point.i][update_point.j] = update_point.value; 
    }

	cout << endl;
    cout << "Kết quả bộ lọc: \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j];
            if (j != col) cout << " ";
        }
        cout << endl;
    }
}
