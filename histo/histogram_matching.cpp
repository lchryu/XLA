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
    int n; cin >> n;
    int h1[n], h2[n];
    vector<int>res;
    for (int i = 0; i < n; i++) cin >> h1[i];
    for (int i = 0; i < n; i++) cin >> h2[i];
    for (int i = 0; i < n; i++) {
        bool check = false;
        for (int j = 0; j < n; j++) {
            if (h2[j] - h1[i] >= 0 && !check) {
                res.push_back(j + 1);
                check = true;
            }
        }
    }
    for (auto i : res) cout << i << " ";
    // for (auto i : h1) cout << i << " ";
    // cout << endl;
    // for (auto i : h2) cout << i << " ";
}
