#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using ll = long long;
int tongcs(int n)
{
	int s = 0;
	while (n != 0)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

bool cmp(int a, int b) {
	if (tongcs(a) != tongcs(b)) {
		return tongcs(a) > tongcs(b);
	}
	return a > b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n, cmp);
	vector<int>v = {1, -1, 3, -3, 5, -5};

	sort(v.begin(), v.end(), cmp);

	abs giảm dần 
	abs = nhau --> tăng dần
}