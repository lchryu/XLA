#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

struct node
{
    vector<double> lst;
    int i_next;
    int i_pre, j_pre;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<double> nk = {113, 139, 142, 145, 181, 105, 52, 1323};
    vector<double> pk;
    double tong = accumulate(nk.begin(), nk.end(), 0);
    for (auto x : nk)
    {
        pk.push_back(x / tong);
    }
    for (auto x : pk)
        cout << x << " ";

    cout << endl;

    node n1;
    n1.lst.assign(pk.begin(), pk.end());

    for (auto x : n1.lst)
        cout << x << " ";
    cout << endl;

    vector<node> res;

    res.push_back(n1);

    // for (int i = 0; i <= 5; i++)
    // {
    //     sort(res[i].lst.begin(), res[i].lst.end(), greater<double>());
    //     vector<double> tmp(res[i].lst.begin(), res[i].lst.end());
    //     sort(tmp.begin(), tmp.end(), greater<double>());

    //     tmp[tmp.size() - 2] += tmp[tmp.size() - 1];
    //     tmp.pop_back();

    //     node newNode;
    //     newNode.i_next = *find(tmp.begin(), tmp.end(), tmp[tmp.size() - 2]);
    //     newNode.lst = tmp;
    //     newNode.i_pre = tmp.size() - 1;
    //     newNode.j_pre = tmp.size() - 2;

    //     res.push_back(newNode);
    // }
    for (int i = 0; i <= 5; i++)
    {
        sort(res[i].lst.begin(), res[i].lst.end(), greater<double>());
        vector<double> tmp(res[i].lst.begin(), res[i].lst.end());
        sort(tmp.begin(), tmp.end(), greater<double>());

        tmp[tmp.size() - 2] += tmp[tmp.size() - 1];
        tmp.pop_back();


        // sort lại sau khi tính tổng
        sort(tmp.begin(), tmp.end(), greater<double>());


        node newNode;
        
        // Tìm iterator của giá trị tmp[tmp.size() - 2]
        auto it = find(tmp.begin(), tmp.end(), tmp[tmp.size() - 2]);

        // Tính chỉ số của giá trị trong vector
        newNode.i_next = distance(tmp.begin(), it);
        
        newNode.lst = tmp;
        newNode.i_pre = tmp.size() - 1;
        newNode.j_pre = tmp.size() - 2;

        res.push_back(newNode);
    }
    // In kết quả
    int cnt = 0;
    for (const auto &item : res)
    {
        cout << "node[" << cnt++ << "] = ";
        for (auto x : item.lst)
            cout << x << " ";
        // cout << " | i_pre: " << item.i_pre << " | j_pre: " << item.j_pre << " | i_next: " << item.i_next << endl;
    }

    return 0;
}
