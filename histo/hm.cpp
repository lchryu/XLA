// cin >> row >> col >> số mức xám
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
int a[50][50];
vector<int> v;
set<int>se;
map<int, int>histo_after;
void output(string name, vector<int> ve)
{
    cout << setw(9) << name << " ";
    for (auto i : ve)
        cout << setw(5) << i << " ";
    cout << endl;
}
void output(string name, vector<double> ve)
{
    cout << setw(9) << name << " ";
    for (auto i : ve)
        cout << setw(5) << i << " ";
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
    int n, m;
    cin >> n >> m;
    int L;
    cin >> L;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            v.push_back(a[i][j]);
            se.insert(a[i][j]);
        }
    }
    vector<int>rk;
    if (se.size() >= L) {
        rk.assign(se.begin(), se.end());
    } else {
        for (int i = 0; i < L; i++) {
            rk.push_back(i);
        }
    }

    vector<int> nk;
    for (auto num : rk)
    {
        nk.push_back(count(v.begin(), v.end(), num));
    }
    vector<int> cdf(rk.size());
    for (int i = 0; i < rk.size(); i++)
    {
        if (i == 0)
            cdf[i] = nk[i];
        else
            cdf[i] = cdf[i - 1] + nk[i];
    }
    vector<double> sk(rk.size());
    int cdf_min = *min_element(cdf.begin(), cdf.end());
    // int cdf_min = 10;
    for (int i = 0; i < sk.size(); i++)
    {
        sk[i] = static_cast<double>(cdf[i]) * (L - 1)/(n * m);
    }

    vector<int>sk_round(sk.size());
    for (int i = 0; i < sk.size(); i++) {
        sk_round[i] = round(sk[i]);
    }



    cout << "Bảng tính toán như sau:\n";
    output("rk"  ,rk);
    output("nk"  ,nk);
    output("cdf" ,cdf);
    // output("sk"  ,sk);/

    cout << setw(10) << "sk ";
    for (auto i : sk) cout << setw(4) << fixed << setprecision(3) << i << " ";
    cout << endl;

    output("round(sk)"  ,sk_round);   


    cout << "\nKết quả cân bằng Histogram:\n";  
    cout << "Trước khi cân bằng:\n";
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    map<int, int>dict;
    cout << "Sau khi cân bằng:\n";
    for (int i = 0; i < rk.size(); i++) {
        dict.insert(make_pair(rk[i], sk_round[i]));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dict[a[i][j]] << " ";
            histo_after[dict[a[i][j]]]++;
        }
        cout << endl;
    }
    cout << endl;




    cout << "Biểu đồ sau khi cân bằng:\n";

    cout << "rk" << " ";
    for (auto i : histo_after)
        cout << setw(5) << i.first << " ";
    cout << endl;

cout << "nk" << " ";
    for (auto i : histo_after)
        cout << setw(5) << i.second << " ";
    cout << endl;

    // bieeu do sau khi can bang
    

}



// 5 5 8
// 4 6 7 6 6
// 3 4 2 6 3
// 6 2 1 6 7
// 3 6 1 7 1
// 3 2 6 4 7