#include <bits/stdc++.h>
using namespace std;

int N, maxv, tmp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	cin >> maxv;
	--N;
	while (N--) {
		cin >> tmp;
		maxv = max(maxv, tmp);
	}
	cout << maxv << "\n";
}