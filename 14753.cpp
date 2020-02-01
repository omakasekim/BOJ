#include <bits/stdc++.h>
using namespace std;

int N, tmp;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	 
	int ans = INT_MIN;
	if (v[N - 1] >= 0 && v[N - 2] >= 0) {
		ans = max(ans, v[N - 1] * v[N - 2]); //++
		if (v[N - 3] > 0) ans = max(ans, v[N - 1] * v[N - 2] * v[N - 3]); //+++
	}

	if (v[N - 1] >= 0 && v[0] <= 0 && v[1] <= 0) {
		if (v[N - 1] >= 0) ans = max(ans, v[0] * v[1] * v[N - 1]); //--+
		ans = max(ans, v[0] * v[1]); //--
	}

	cout << ans << "\n";
}